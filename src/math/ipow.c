#include "../math.h"
#include <stdint.h>

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