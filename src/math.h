#ifndef MATH_H
#define MATH_H

#include <stdint.h>

#define M_PI 3.14159265359

typedef struct point
{
    float x, y;
} Point;

float abs(float);
int8_t sign(float);
float sin(float);
float cos(float);
int ipow(int, uint32_t);
float sqrt(float);
int32_t imax(int32_t ra[]);
int32_t imin(int32_t ra[]);

#endif
