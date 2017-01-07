#include "Random.h"

#define RAND_ADDRESS 0x804D5F90

/*
    generate random 32-bit value using a linear-feedback shift
    register. The internal random value of the game is used as a
    seed. A second random value is generated and written to the 
    address of the internal random random value. This ensures that
    no random number is used twice.
*/
uint32_t randUint32()
{
    /* used for calculations */
    uint32_t bit;

    /* get previous random 32-bit unsigned value */
    uint32_t old = *((uint32_t*) RAND_ADDRESS);

    /* generate new 32-bit unsigned value */
    bit = ((old >> 0) ^ (old >> 10) ^ (old >> 30) ^ (old >> 31) ) & 1;
    uint32_t rand = (old >> 1) | (bit << 31);

    /* generate another random value, write to address */
    bit = ((rand >> 0) ^ (rand >> 10) ^ (rand >> 30) ^ (rand >> 31) ) & 1;
    *((uint32_t*) RAND_ADDRESS) = (rand >> 1) | (bit << 31);

    /* return random value */
    return rand;

}

float rand()
{
    return (float) randUint32() / 0xFFFFFFFF;
}
