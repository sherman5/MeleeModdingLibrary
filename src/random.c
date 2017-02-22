#include "random.h"
#include "native_functions.h"
#include "gctypes.h"

#ifdef PAL

#error random.c not compatible with PAL

#else

static volatile u32* randSeed = (u32*) 0x804d5f90;

#endif

float rand(void)
{
    u32 (*rng)(u32) = RAND_INT_FPTR;
    rng(2); //reset seed
    return (float) *randSeed / (u32) 0xffffffff;
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
