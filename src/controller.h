#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <stdint.h>

typedef struct controller {

    uint32_t buttons;
    float stick_x;
    float stick_y;
    uint8_t player_num;
    
} Controller;

void initController(Controller*, uint8_t);
void press(Controller*, char);
void release(Controller*);
void setStick(Controller*, float, float);
void writeControllerState(Controller*);

#endif
