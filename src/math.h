#ifndef MATH_H
#define MATH_H

#include <stdint.h>

#define M_PI 3.14159265359

struct Point {

	float x;
    float y;

};

float abs(float); 
int8_t sign(float);
float sin(float);
float cos(float);
float tan(float);
int ipow(int, uint32_t);
float sqrt(float);
int32_t imax(int32_t ra[]);
int32_t imin(int32_t ra[]);

//float distance(Point, Point);
//float angle(Point, Point);

#endif
