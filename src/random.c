#include "random.h"
#include "native_functions.h"
#include "gctypes.h"

#define RAND_PRECISION 10000

float rand(void)
{
    u32 (*rng)(u32) = RAND_INT_FPTR;
    return (float) rng(RAND_PRECISION) / RAND_PRECISION;
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
