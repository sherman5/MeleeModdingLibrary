#include "random.h"
#include "native_functions.h"

uint32_t randUint32()
{
    void (*randu)() = RANDU_FPTR;    
    randu();
    return *((uint32_t*) RAND_ADDRESS);
}

float rand()
{
    return (float) randUint32() / 0xFFFFFFFF;
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
