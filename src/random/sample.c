#include "../random.h"

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