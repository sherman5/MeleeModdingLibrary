#include "math.h"
#include "native_functions.h"
#include "gctypes.h"

/*************************** built in functions **************************/
float (*recipSqrt)(float x)             = RECIP_SQRT_FPTR;
float (*fabs)(float x)                  = FABS_FPTR;
float (*exp)(float x)                   = EXP_FPTR;
float (*log)(float x)                   = LOG_FPTR;
float (*native_sin)(float x)            = SIN_FPTR;
float (*native_cos)(float x)            = COS_FPTR;
float (*native_tan)(float x)            = TAN_FPTR;
float (*native_asin)(float x)           = ASIN_FPTR;
float (*native_acos)(float x)           = ACOS_FPTR;
float (*native_atan)(float x)           = ATAN_FPTR;
float (*native_atan2)(float y, float x) = ATAN2_FPTR;
/*************************************************************************/

// see http://stackoverflow.com/a/6437076
float floor(float x)
{
    if (x >= 0)
    {
        return (u32) x;
    } 
    else
    {
        s32 y = (s32) x;
        return ((float) y == x) ? y : y - 1;
    }
}

float ceil(float x)
{
    return -floor(-x);
}

s32 imax(s32 a, s32 b)
{
    return (a > b ? a : b);
}

s32 imin(s32 a, s32 b)
{
    return (a < b ? a : b);
}

float fmax(float a, float b)
{
    return (a > b ? a : b);
}

float fmin(float a, float b)
{
    return (a < b ? a : b);
}

int imod(int a, int b)
{
    int r = a % b;
    return r < 0 ? r + b : r;
}

float fmod(float a, float b)
{
    while (a >= b) {a -= b;}
    while (a < 0) {a += b;}
    return a;
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

float sqrt(float x)
{
    return x == 0 ? 0 : 1 / recipSqrt(x);
}

float sin(float x)
{
    return native_sin(DEG_TO_RAD(x));
}

float cos(float x)
{
    return native_cos(DEG_TO_RAD(x));
}

float tan(float x)
{
    return native_tan(DEG_TO_RAD(x));
}

float asin(float x)
{
    return fmod(RAD_TO_DEG(native_asin(x)), 360.f);
}

float acos(float x)
{
    return RAD_TO_DEG(native_acos(x));
}

float atan(float x)
{
    return RAD_TO_DEG(native_atan(fabs(x)));
}

float atan2(float y, float x)
{
    return fmod(RAD_TO_DEG(native_atan2(y, x)), 360.f);
}

float angle(Point a, Point b)
{
    return atan2(b.y - a.y, b.x - a.x);
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



