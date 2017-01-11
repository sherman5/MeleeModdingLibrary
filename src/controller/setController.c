#include "../controller.h"
#include "../math.h"

#define BUTTON_BITS 0b0000000000011111
#define RADIUS_BITS 0b0000000011100000
#define ANGLE_BITS  0b1111111100000000

#define A_BIT       0b00000001
#define B_BIT       0b00000010
#define X_BIT       0b00000100
#define Z_BIT       0b00001000
#define L_BIT       0b00010000

#define TILT_BIT    0b00100000
#define FULL_BIT    0b01000000

#define TILT_RADIUS 0.5

void setController(Controller* controller, uint16_t state)
{
    uint8_t buttons = state & BUTTON_BITS;
    uint8_t radius = state & RADIUS_BITS;
    uint8_t angle = (state & ANGLE_BITS) >> 8;

    switch (buttons)
    {
        case A_BIT: controller->buttons = 0x0100; break;
        case B_BIT: controller->buttons = 0x0200; break;
        case X_BIT: controller->buttons = 0x0400; break;
        case Z_BIT: controller->buttons = 0x0010; break;
        case L_BIT: controller->buttons = 0x0040; break;
        default: controller->buttons = 0; break;
    }

    float radians = 2 * M_PI * (float) angle / 255;
    controller->stickX = cos(radians);
    controller->stickY = sin(radians);

    if (radius & TILT_BIT) //tilt control stick
    {
        controller->stickX *= TILT_RADIUS;
        controller->stickY *= TILT_RADIUS;
    }
    else if (!(radius & FULL_BIT)) //control stick neutral
    {
        controller->stickX = 0;
        controller->stickY = 0;
    }
}