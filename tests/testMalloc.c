#include "testing.h"
#include <malloc.h>

#include <stdbool.h>

bool init = false;
uint32_t* uint_ra;
float* flt_ra;

void runTest(int numRuns)
{
    if (!init)
    {
        uint_ra = (uint32_t*) malloc(3 * sizeof(uint32_t));
        //flt_ra = (float*) malloc(10 * sizeof(float));
        init = true;
    }
}

END_TEST
