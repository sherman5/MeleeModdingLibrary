#include "math.h"
#include "melee102.h"
#include <stdint.h>

float (*sin)(float x) = (void*) SINE_ADDRESS;
float (*cos)(float x) = (void*) COSINE_ADDRESS;
float (*tan)(float x) = (void*) TANGENT_ADDRESS;
float (*fabs)(float x) = (void*) ABS_VAL_ADDRESS;

int32_t imax_array(int32_t ra[])
{
    int32_t max = ra[0];
    for (unsigned int i = 0; i < sizeof(ra) / sizeof(ra[0]); ++i)
    {
        if (max < ra[i]) {max = ra[i];}
    }
}

int32_t imin_array(int32_t ra[])
{
    int32_t min = ra[0];
    for (unsigned int i = 0; i < sizeof(ra) / sizeof(ra[0]); ++i)
    {
        if (min > ra[i]) { min = ra[i];}        
    }
}

int32_t imax(int32_t a, int32_t b)
{
    return (a > b ? a : b);
}

int32_t imin(int32_t a, int32_t b)
{
    return (a < b ? a : b);
}

float fmax_array(float ra[])
{
    float max = ra[0];
    for (unsigned int i = 0; i < sizeof(ra) / sizeof(ra[0]); ++i)
    {
        if (max < ra[i]) {max = ra[i];}
    }
}

float fmin_array(float ra[])
{
    float min = ra[0];
    for (unsigned int i = 0; i < sizeof(ra) / sizeof(ra[0]); ++i)
    {
        if (min > ra[i]) { min = ra[i];}        
    }
}

float fmax(float a, float b)
{
    return (a > b ? a : b);
}

float fmin(float a, float b)
{
    return (a < b ? a : b);
}

int32_t ipow(int16_t base, uint8_t exp)
{
    int32_t result = 1;
    while (exp)
    {
        if (exp & 1)
        {
            result *= base;
        }
        exp >>= 1;
        base *= base;
    }
    return result;
}

float fpow(float base, uint8_t exp)
{
    float result = 1;
    while (exp)
    {
        if (exp & 1)
        {
            result *= base;
        }
        exp >>= 1;
        base *= base;
    }
    return result;
}

float sqrt(float x)
{
    __asm__ __volatile__ ("fsqrt %0, %1" : "=r" (x) : "r" (x));
    return x;
}

float atan2(float y, float x)
{
    float ax = fabs(x);
    float ay = fabs(y);
    float result;

    if (ay < ax) //first octant
    {
        result = (ax * ay) / (ax * ax + 0.28125f * ay * ay);
    }
    else //second octant
    {
        result = M_PI / 2 - (ax * ay) / (ay * ay + 0.28125f * ax * ax);
    }

    if (x < 0) { result = M_PI - result;} //reflect around y-axis
    if (y < 0) { result *= -1;} //reflect around x-axis
}

float magnitude(Point pt)
{
    return sqrt((pt.x * pt.x) + (pt.y * pt.y));
}

float distance(Point a, Point b) 
{
    b.x -= a.x;
    b.y -= a.y;
    return magnitude(a);
}

float angle(Point a, Point b)
{
    return atan2(b.y - a.y, b.x - a.x);
}