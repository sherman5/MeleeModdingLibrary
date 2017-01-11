#include "../math.h"
#include "../controller.h"
#include "../melee.h"

void writeController(Controller* controller, uint8_t port)
{
    void* primary = PRIMARY_CONTROLLER(port);
    float* secondary = (float*) SECONDARY_CONTROLLER(port);

    *((uint32_t*) primary) = controller->buttons;
    *((float*) primary + 8) = controller->stickX;
    *((float*) primary + 9) = controller->stickY;
    
    secondary[0] = controller->stickX;
    secondary[1] = controller->stickY;  
}

