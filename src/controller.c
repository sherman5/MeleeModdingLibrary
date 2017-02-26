#include "controller.h"
#include "math.h"
#include "game_state.h"

#ifdef PAL

#error controller.c not compatible with PAL

#else

#define PRIMARY_CONTROLLER(x)   ((void*) (0x804C1FAC + 0x44 * ((x) - 1)))
#define SECONDARY_CONTROLLER(x) ((void*) ((char*) playerData(x) + 0x620))

#endif

void setController(Controller* controller, u16 state)
{
    u8 buttons = state & BUTTON_BITS;
    u8 radius = state & RADIUS_BITS;
    u8 angle = (state & ANGLE_BITS) >> 8;
    
    controller->CstickX = 0.f;
    controller->CstickY = 0.f;

    switch (buttons)
    {
        case NO_BUTTON:    controller->buttons = 0x00000000; break;
        case A_BUTTON:     controller->buttons = 0x00000100; break;
        case B_BUTTON:     controller->buttons = 0x00000200; break;
        case X_BUTTON:     controller->buttons = 0x00000400; break;
        case Z_BUTTON:     controller->buttons = 0x00000010; break;
        case L_BUTTON:     controller->buttons = 0x00000040; break;
        case START_BUTTON: controller->buttons = 0x00001000; break;
        case DPAD_UP:      controller->buttons = 0x00000008; break;
        case DPAD_DOWN:    controller->buttons = 0x00000004; break;
        case DPAD_LEFT:    controller->buttons = 0x00000001; break;
        case DPAD_RIGHT:   controller->buttons = 0x00000002; break;

        case CSTICK_UP:
            controller->CstickX = 0.f;    
            controller->CstickY = 1.f;
            break;
        case CSTICK_DOWN:
            controller->CstickX = 0.f;    
            controller->CstickY = -1.f;
            break;
        case CSTICK_LEFT:
            controller->CstickX = -1.f;    
            controller->CstickY = 0.f;
            break;
        case CSTICK_RIGHT:
            controller->CstickX = 1.f;    
            controller->CstickY = 0.f;
            break;
    }

    float degrees = 360.f * (float) angle / 0xFF;
    controller->stickX = cos(degrees);
    controller->stickY = sin(degrees);

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

void writeController(Controller* controller, u32 port, bool pData)
{
    void* primary = PRIMARY_CONTROLLER(port);
    float* secondary = (float*) SECONDARY_CONTROLLER(port);

    *((u32*) primary + 1) = *((u32*) primary);
    *((u32*) primary) = controller->buttons;
    *((float*) primary + 8) = controller->stickX;
    *((float*) primary + 9) = controller->stickY;
    *((float*) primary + 10) = controller->CstickX;
    *((float*) primary + 11) = controller->CstickY;

    if (pData && playerData(port))
    {
        secondary[0] = controller->stickX;
        secondary[1] = controller->stickY;  
    }
}

