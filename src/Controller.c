#include "MeleeMath.h"
#include "Controller.h"

void Press(char button) {

    if (button == 'A') {*button_addr = 0x00000100;}
    else if (button == 'B') {*button_addr = 0x00000200;}
    else if (button == 'X') {*button_addr = 0x00000400;}
    else if (button == 'Z') {*button_addr = 0x00000010;}
    else {*button_addr = 0x00000040;} 

}

void Release() {

    *button_addr = 0;

}


void SetStick(float ang) {

    *stick_x_addr = mml_cos(ang);
    *stick_y_addr = mml_sin(ang);

}

void ResetStick() {

    *stick_x_addr = 0.0;
    *stick_y_addr = 0.0;

}

void WriteControllerState() {

    //not stored in a static block of memory
    float* p2_controller_data_2 = (float*) P2_CONTROLLER_DATA_2_ADDR;
    
    *((uint32_t*) p2_controller_data_1) = *button_addr;
    *((float*) p2_controller_data_1 + 8) = *stick_x_addr;
    *((float*) p2_controller_data_1 + 9) = *stick_y_addr;
    
    p2_controller_data_2[0] = *stick_x_addr;
    p2_controller_data_2[1] = *stick_y_addr;
    
}


