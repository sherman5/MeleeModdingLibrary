#include "random.h"
#include "melee.h"

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

unsigned sample(float probs[])
{
    float unif = rand();
    float total = 0.0;
    for (unsigned i = 0; i < sizeof(probs) / sizeof(probs[0]); ++i)
    {
        total += probs[i];
        if (unif < total) { return i;}
    }
    return 0;
}
