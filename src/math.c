#include "math.h"

int pmod (int a, int b)
{
   int ret = a % b;
   if(ret < 0)
     ret+=b;
   return ret;
}

float sin(float deg) 
{
    deg = pmod(deg, 360);
    rad = deg2Rad(pmod(deg, 90));
    float value = 1.27323954 * rad - 0.405284735 * rad * rad;
    if (deg > 180) return value * -1.0f
    return neg * 0.225 * (rad * rad - rad) + rad;        
}


#if 0
float abs(float x) { return (x < 0 ? -x : x); }

int pmod (int a, int b)
{
   int ret = a % b;
   if(ret < 0)
     ret+=b;
   return ret;
}

int8_t sign(float x) 
{
    return ((x >= 0) - (x < 0));
}


float cos(float x)
{
    return sin(x + 90);
}

float atan(point relDist) 
{
   
}

int ipow(int base, uint32_t exp)
{
    int result = 1;
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
    unsigned int i = *(unsigned int*) &x; 
    // adjust bias
    i  += 127 << 23;
    // approximation of square root
    i >>= 1; 
    return *(float*) &i;
} 

int32_t imax(int32_t ra[])
{
    int32_t max = ra[0];
    for (unsigned int i = 0; i < sizeof(ra) / sizeof(ra[0]); ++i)
    {
        if (max < ra[i]) { max = ra[i];}
    }
}

int32_t imin(int32_t ra[])
{
    int32_t min = ra[0];
    for (unsigned int i = 0; i < sizeof(ra) / sizeof(ra[0]); ++i)
    {
        if (min > ra[i]) { min = ra[i];}        
    }
}

point relativeTo(point a, point b)
{
    point new;
    new.x = a.x - b.x;
    new.y = a.y - b.y
    return new;
}

float mag(point)
{
    return sqrt((point.x * point.x) + (point.y * point.y));
}

float distance(point a, point b) 
{
    return mag(relativeTo(a, b));
}


#endif