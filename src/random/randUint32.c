#include "../random.h"

uint32_t randUint32()
{
    uint32_t bit;
    uint32_t old = *((uint32_t*) RAND_ADDRESS);

    /* generate new 32-bit unsigned value */
    bit = ((old >> 0) ^ (old >> 10) ^ (old >> 30) ^ (old >> 31) ) & 1;
    uint32_t rand = (old >> 1) | (bit << 31);

    /* generate another random value, write to address */
    bit = ((rand >> 0) ^ (rand >> 10) ^ (rand >> 30) ^ (rand >> 31) ) & 1;
    *((uint32_t*) RAND_ADDRESS) = (rand >> 1) | (bit << 31);

    return rand;
}

