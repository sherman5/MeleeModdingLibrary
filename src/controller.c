#include "controller.h"
#include "math.h"
#include "game_state.h"

#ifdef PAL

#error controller.c not compatible with PAL

#else

#define PRIMARY_CONTROLLER(x)   ((void*) (0x804C1FAC + 0x44 * ((x) - 1)))
#define SECONDARY_CONTROLLER(x) ((void*) ((char*) playerData(x) + 0x620))

#endif

static void storeControllerInputs(Controller* controller)
{
    controller->lastUpdate = CURRENT_FRAME;
    controller->prevButtons = controller->buttons;
    controller->prevStickX = controller->stickX;
    controller->prevStickY = controller->stickY;
}

static void processButtons(Controller* controller, u8 buttons)
{
    controller->cStickX = 0.f;
    controller->cStickY = 0.f;

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
            controller->cStickX = 0.f;    
            controller->cStickY = 1.f;
            controller->buttons = 0x00100000;
            break;
        case CSTICK_DOWN:
            controller->cStickX = 0.f;    
            controller->cStickY = -1.f;
            controller->buttons = 0x00200000;
            break;
        case CSTICK_LEFT:
            controller->cStickX = -1.f;    
            controller->cStickY = 0.f;
            controller->buttons = 0x00400000;
            break;
        case CSTICK_RIGHT:
            controller->cStickX = 1.f;    
            controller->cStickY = 0.f;
            controller->buttons = 0x00800000;
            break;
    }
}

static void processStick(Controller* controller, u8 radius, u8 angle)
{
    float degrees = 360.f * (float) angle / 0xFF;

    if (degrees >= 315.f || degrees <= 45.f)
    {
        controller->buttons |= 0x00080000;
    }
    else if (degrees > 45.f && degrees < 135.f)
    {
        controller->buttons |= 0x00010000;
    }
    else if (degrees >= 135.f && degrees <= 225.f)
    {
        controller->buttons |= 0x00040000;
    }
    else
    {
        controller->buttons |= 0x00020000;
    }

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
            controller->stickX = 0.f;
            controller->stickY = 0.f;
            break;
    }
}

void setController(Controller* controller, u16 state)
{
    if (controller->lastUpdate != CURRENT_FRAME)
    {
        storeControllerInputs(controller);
    }

    u8 buttons = state & BUTTON_BITS;
    u8 radius = state & RADIUS_BITS;
    u8 angle = (state & ANGLE_BITS) >> 8;

    processButtons(controller, buttons); 
    processStick(controller, radius, angle);
}

static void writePrimaryController(Controller* controller, u32 port)
{
    void* primary = PRIMARY_CONTROLLER(port);

    *((u32*) primary + 0) = controller->buttons;
    *((u32*) primary + 1) = controller->prevButtons;
    *((u32*) primary + 7) = controller->buttons & 0x40 ? 0x8c000000 : 0;

    *((float*) primary + 8) = controller->stickX;
    *((float*) primary + 9) = controller->stickY;
    *((float*) primary + 10) = controller->cStickX;
    *((float*) primary + 11) = controller->cStickY;

    s8 stickX = controller->stickX * 79.f;
    s8 stickY = controller->stickY * 79.f;
    s8 cStickX = controller->cStickX * 79.f;
    s8 cStickY = controller->cStickY * 79.f;
    
    *((u32*) primary + 6) = (stickX << 24) | (stickY << 16)
        | (cStickX << 8) | (cStickY);
}

static void writeSecondaryController(Controller* controller, u32 port)
{
    void* secondary = (void*) SECONDARY_CONTROLLER(port);

    *((float*) secondary + 0) = controller->stickX;
    *((float*) secondary + 1) = controller->stickY;
    *((float*) secondary + 2) = controller->prevStickX;
    *((float*) secondary + 3) = controller->prevStickY;
    *((float*) secondary + 6) = controller->cStickX;
    *((float*) secondary + 7) = controller->cStickY;

    *((u32*) secondary + 15) = controller->buttons;
    *((u32*) secondary + 16) = controller->prevButtons;
}

void writeController(Controller* controller, u32 port, bool pData)
{
    if (controller->lastUpdate != CURRENT_FRAME)
    {
        storeControllerInputs(controller);
    }

    writePrimaryController(controller, port);

    if (pData && playerData(port))
    {
        writeSecondaryController(controller, port);
    }
}

