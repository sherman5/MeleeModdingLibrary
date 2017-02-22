#include "random.h"
#include "native_functions.h"
#include "gctypes.h"

#ifdef PAL

#error random.c not compatible with PAL

#else

volatile u32* randSeed = (u32*) 0x804d5f90;

#endif

/*
    generate random 32-bit value using a linear-feedback shift
    register. The internal random value of the game is used as a
    seed. A second random value is generated and written to the 
    address of the internal random random value. This ensures that
    no random number is used twice.
*/
u32 randU32()
{
    /* used for calculations */
    u32 bit;

    /* get previous random 32-bit unsigned value */
    u32 old = *randSeed;

    /* generate new 32-bit unsigned value */
    bit = ((old >> 0) ^ (old >> 10) ^ (old >> 30) ^ (old >> 31) ) & 1;
    u32 rng = (old >> 1) | (bit << 31);

    /* generate another random value, write to address */
    bit = ((rng >> 0) ^ (rng >> 10) ^ (rng >> 30) ^ (rng >> 31) ) & 1;
    *randSeed = (rng >> 1) | (bit << 31);

    /* return random value */
    return rng;
}


float rand(void)
{
    return (float) randU32() / 0xffffffff;
}

float uniform(float a, float b)
{
    return rand() * (b - a) + a;
}

unsigned sample(const float* probs, size_t size)
{
    float unif = rand();
    float total = 0.0;
    for (unsigned i = 0; i < size; ++i)
    {
        total += probs[i];
        if (unif < total) { return i;}
    }
    return 0;
}
