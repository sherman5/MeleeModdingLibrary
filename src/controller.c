#include "controller.h"
#include "math.h"
#include "gamestate.h"

#define PRIMARY_CONTROLLER(x)   ((void*) (0x804C1FAC + 0x44 * ((x) - 1)))
#define SECONDARY_CONTROLLER(x) ((void*) ((char*) playerData(x) + 0x620))

#define BUTTON_BITS 0b0000000000111111
#define RADIUS_BITS 0b0000000011000000
#define ANGLE_BITS  0b1111111100000000

#define A_BITS      0b00000001
#define B_BITS      0b00000010
#define X_BITS      0b00000011
#define Z_BITS      0b00000100
#define L_BITS      0b00000110
#define START_BITS  0b00000111

#define TILT_BIT    0b01000000
#define FULL_BIT    0b10000000

#define TILT_RADIUS 0.5

void setController(Controller* controller, u16 state)
{
    u8 buttons = state & BUTTON_BITS;
    u8 radius = state & RADIUS_BITS;
    u8 angle = (state & ANGLE_BITS) >> 8;

    switch (buttons)
    {
        case A_BITS:     controller->buttons = 0x0100; break;
        case B_BITS:     controller->buttons = 0x0200; break;
        case X_BITS:     controller->buttons = 0x0400; break;
        case Z_BITS:     controller->buttons = 0x0010; break;
        case L_BITS:     controller->buttons = 0x0040; break;
        case START_BITS: controller->buttons = 0x1000; break;
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

void writeController(Controller* controller, u8 port)
{
    void* primary = PRIMARY_CONTROLLER(port);
    float* secondary = (float*) SECONDARY_CONTROLLER(port);

    *((u32*) primary) = controller->buttons;
    *((float*) primary + 8) = controller->stickX;
    *((float*) primary + 9) = controller->stickY;
    
    if (playerData(port))
    {
        secondary[0] = controller->stickX;
        secondary[1] = controller->stickY;  
    }
}

