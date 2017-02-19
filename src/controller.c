#include "controller.h"
#include "math.h"
#include "gamestate.h"

#define PRIMARY_CONTROLLER(x)   ((void*) (0x804C1FAC + 0x44 * ((x) - 1)))
#define SECONDARY_CONTROLLER(x) ((void*) ((char*) playerData(x) + 0x620))

void setController(Controller* controller, u16 state)
{
    u8 buttons = state & BUTTON_BITS;
    u8 radius = state & RADIUS_BITS;
    u8 angle = (state & ANGLE_BITS) >> 8;

    switch (buttons)
    {
        case NO_BUTTON:    controller->buttons = 0x0000; break;
        case A_BUTTON:     controller->buttons = 0x0100; break;
        case B_BUTTON:     controller->buttons = 0x0200; break;
        case X_BUTTON:     controller->buttons = 0x0400; break;
        case Z_BUTTON:     controller->buttons = 0x0010; break;
        case L_BUTTON:     controller->buttons = 0x0040; break;
        case START_BUTTON: controller->buttons = 0x1000; break;
    }

    float radians = 2 * M_PI * (float) angle / 0xFF;
    controller->stickX = cos(radians);
    controller->stickY = sin(radians);

    switch (radius)
    {
        case TILT_STICK:
            controller->stickX *= TILT_RADIUS;
            controller->stickY *= TILT_RADIUS;
            break;
        case FULL_STICK: break;
        default:            
            controller->stickX = 0;
            controller->stickY = 0;
            break;
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

