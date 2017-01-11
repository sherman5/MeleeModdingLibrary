#include "testing.h"
#include <math.h>

#define NUM_MATH_TESTS 2

void testTrig(uint32_t numRuns)
{
    REQUIRE(APPROX_EQ(sin(0.0), 0.0, 0.001));
    REQUIRE(APPROX_EQ(sin(45.0), 0.707, 0.001));
    REQUIRE(APPROX_EQ(sin(90.0), 1.0, 0.001));    
    REQUIRE(APPROX_EQ(sin(135.0), 0.707, 0.001));
    REQUIRE(APPROX_EQ(sin(180.0), 0.0, 0.001));
}

void testMath(uint32_t numRuns)
{
    testTrig(numRuns);
}
