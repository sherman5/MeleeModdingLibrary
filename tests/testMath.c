#include "testing.h"
#include <math.h>

#define NUM_MATH_TESTS 2

void testTrig(uint32_t numRuns)
{
    REQUIRE(APPROX_EQ(sin(0.0), 0.0, 0.001));
    REQUIRE(APPROX_EQ(cos(0.0), 1.0, 0.001));
}

void testMath(uint32_t numRuns)
{
    testTrig(numRuns);
}
