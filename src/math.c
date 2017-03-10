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
float (*native_acos)(float x)           = ACOS_FPTR;
float (*native_asin)(float x)           = ASIN_FPTR;
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

float sin(float x)
{
    return native_sin(DEG_TO_RAD(x));
}

float cos(float x)
{
    return native_cosine(DEG_TO_RAD(x));
}

float tan(float x)
{
    return native_tangent(DEG_TO_RAD(x));
}

//http://http.developer.nvidia.com/Cg/asin.html
float asin(float x)
{
    float negate = x < 0.f ? 1.f : 0.f;
    x = fabs(x);
    float ret = -0.0187293f;
    ret *= x;
    ret += 0.0742610f;
    ret *= x;
    ret -= 0.2121144f;
    ret *= x;
    ret += M_HALF_PI;
    ret = M_PI * 0.5f - sqrt(1.f - x) * ret;
    ret -= 2 * negate * ret;
    ret = RAD_TO_DEG(ret);
    return ret < 0 ? ret + 360.f : ret;
}

//http://http.developer.nvidia.com/Cg/acos.html
float acos(float x)
{
    float negate = x < 0.f ? 1.f : 0.f;
    x = fabs(x);
    float ret = -0.0187293f;
    ret *= x;
    ret += 0.0742610f;
    ret *= x;
    ret -= 0.2121144f;
    ret *= x;
    ret += M_HALF_PI;
    ret *= sqrt(1.f - x);
    ret -= 2 * negate * ret;
    return RAD_TO_DEG(negate * M_PI + ret);
}

float atan(float x)
{
    return atan2(x, 1);
}

float atan2(float y, float x)
{
    float ax = fabs(x);
    float ay = fabs(y);
    float ret;

    if (ay < ax) //first octant
    {
        ret = (ax * ay) / (ax * ax + 0.28125f * ay * ay);
    }
    else //second octant
    {
        ret = M_PI / 2 - (ax * ay) / (ay * ay + 0.28125f * ax * ax);
    }

    ret = RAD_TO_DEG(ret);
    if (x < 0) { ret = 180.f - ret;} //reflect around y-axis
    if (y < 0) { ret = 360.f - ret;} //reflect around x-axis

    return ret;
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



