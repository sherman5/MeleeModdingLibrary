#include "Math.h"
#include "Controller.h"

void initController(Controller* contr, uint8_t player) {

    contr->player_num = player;

}

void press(Controller* contr, char button) {

    if (button == 'A') {contr->buttons = 0x00000100;}
    else if (button == 'B') {contr->buttons = 0x00000200;}
    else if (button == 'X') {contr->buttons = 0x00000400;}
    else if (button == 'Z') {contr->buttons = 0x00000010;}
    else {contr->buttons = 0x00000040;}

}

void release(Controller* contr) {

    contr->buttons = 0;

}


void setStick(Controller* contr, float rad, float ang) {

    contr->stick_x = rad * cos(ang);
    contr->stick_y = rad * sin(ang);

}

void writeControllerState(Controller* contr) {

    void* controller_data_1 =
        (void*) (0x804C1FAC + 0x44 * (contr->player_num - 1));

    float* controller_data_2 = 
        (float*) (*((uint32_t*) (0x80453130 + 0xE90 * 
                                    (contr->player_num - 1))) + 0x680);

    *((uint32_t*) controller_data_1) = contr->buttons;
    *((float*) controller_data_1 + 8) = contr->stick_x;
    *((float*) controller_data_1 + 9) = contr->stick_y;
    
    controller_data_2[0] = contr->stick_x;
    controller_data_2[1] = contr->stick_y;
    
}

