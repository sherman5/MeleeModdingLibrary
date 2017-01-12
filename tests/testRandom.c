#include "testing.h"
#include <random.h>
#include <math.h>

/* buckets */
static uint32_t buckets[20] = {0};

void runTest(int numRuns)
{
    if (numRuns <= 1000) // gather data
    {
        float f = rand(); // store results of random values 

        /* put random numbers into buckets */
        for (int i = 0; i < 20; ++i)
        {
            if (f >= (float) i / 20 && f < (float) (i + 1) / 20)
            {
                buckets[i] += 1;
            }
        }
    }
    else // test data
    {
        *((uint32_t*) 0x80001804) = *((uint32_t*) 0x80001804) | 0x0E;
        uint32_t mx = imax_array(buckets);
        uint32_t mn = imin_array(buckets);

        REQUIRE_FLT_LESS((mx - mn) / (float) numRuns, 0.05);
    }
}

END_TEST