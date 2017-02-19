#include "math.h"
#include "native_functions.h"
#include "gctypes.h"

float (*sin)(float x) = SINE_FPTR;
float (*cos)(float x) = COSINE_FPTR;
float (*tan)(float x) = TANGENT_FPTR;
float (*recipSqrt)(float x) = RECIP_SQRT_FPTR;
float (*fabs)(float x) = ABS_VAL_FPTR;

// see http://stackoverflow.com/a/6437076
float floor(float x)
{
    if (x >= 0)
    {
        return (int) x;
    } 
    else
    {
        int y = (int) x;
        return ((float) y == x) ? y : y - 1;
    }
}

float ceil(float x)
{
    return -floor(-x);
}

float angle(Point a, Point b)
{
    return atan2(b.y - a.y, b.x - a.x);
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

    return result;
}

float magnitude(Point pt)
{
    return sqrt((pt.x * pt.x) + (pt.y * pt.y));
}

float distance(Point a, Point b) 
{
    b.x -= a.x;
    b.y -= a.y;
    return magnitude(b);
}

s32 ipow(s16 base, u8 exp)
{
    s32 result = 1;
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

s32 imin(s32 a, s32 b)
{
    return (a < b ? a : b);
}

s32 imax(s32 a, s32 b)
{
    return (a > b ? a : b);
}

float fmin(float a, float b)
{
    return (a < b ? a : b);
}

float fmax(float a, float b)
{
    return (a > b ? a : b);
}

float fpow(float base, u8 exp)
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



