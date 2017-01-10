#include "math.h"

float abs(float x)
{
    return (x < 0 ? -x : x);
}

int8_t sign(float x)
{
    return ((x >= 0) - (x < 0));
}

/* return sin(x), x is given in degress, error within 0.001 */
float sin(float x)
{
    x *= M_PI / 180.0;

    signed int neg = 1;

    if (x < 0)
    {
        x = -x;
        neg = -1;
    }

    while (x > 180)
    {
        x -= 360;
    }

    if (x < 0)
    {
        x = -x;
        neg *= -1;
    }

    float value = 1.27323954 * x - 0.405284735 * x * x;
    return neg * 0.225 * (value * value - value) + value;    
}

/* return cos(x), x is given in degress, error within 0.001 */
float cos(float x)
{
    return sin(x + 90);
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

/* shitty sqrt, http://bits.stephan-brumme.com/squareRoot.html */
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

