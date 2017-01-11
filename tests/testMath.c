#include "testing.h"
#include <math.h>

#define NUM_MATH_TESTS 2

#define DEG_TO_RAD(x) (x * M_PI / 180.f)

void testTrig(uint32_t numRuns)
{
    REQUIRE_AEQ(sin(DEG_TO_RAD(0.0)), 0, 0.001);
    REQUIRE_AEQ(sin(DEG_TO_RAD(90.0)), 0, 0.001);
}

void testMath(uint32_t numRuns)
{
    testTrig(numRuns);
}
