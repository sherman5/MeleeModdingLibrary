#include "random.h"
#include "native_functions.h"
#include "gctypes.h"

u32 randUint32(void)
{
    void (*randu)() = RANDU_FPTR;    
    randu();
    return *((u32*) RAND_ADDRESS);
}

float rand(void)
{
//    return (((float) 0xaabbccdd) / ((float) 0xffffffff));
    return (float) randUint32() / 0xffffffff;
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
