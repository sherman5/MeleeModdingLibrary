#include "../math.h"

float sqrt(float x)
{
    __asm__ __volatile__ ("fsqrt %0, %1" : "=r" (x) : "r" (x));
    return x;
}
