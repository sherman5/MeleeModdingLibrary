#include "testing.h"
#include <random.h>
#include <math.h>

/* buckets */
static uint32_t buckets[20] = {0};

void runTest(int numTests)
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


    }

    /* should be close to uniform after 1000 runs */
    if (numRuns > 1000)
    {
        uint32_t mx = imax(buckets);
        uint32_t mn = imin(buckets);

        REQUIRE((mx - mn) / (float) numRuns < 0.05);
    }
    else
    {
        REQUIRE(1); //jank, need to increment address
    }
}

END_TEST