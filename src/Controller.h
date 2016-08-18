#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <stdint.h>

static uint32_t* button_addr = (uint32_t*) 0x80003FF0;
static float* stick_x_addr = (float*) 0x80003FF0;
static float* stick_y_addr = (float*) 0x80003FF0;
static void* p2_controller_data_1 = (void*) 0x804C1FF0;

#define P2_CONTROLLER_DATA_2_ADDR (*((uint32_t*) 0x80453FC0) + 0x680)

void Press(char);
void Release();
void SetStick(float);
void WriteControllerState();

#endif
