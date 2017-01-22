#include <unit_tests.h>
#include <system.h>
#include <math.h>

TEST_CASE("<system.h>")
{
    uint32_t* ra_1 = (uint32_t*) 0x80002200;
    uint32_t* ra_2 = (uint32_t*) 0x80002220;

    memset(ra_1, 0xCC, 16);
    memcpy(ra_2, ra_1, 16);
    REQUIRE_INT_EQ((uint32_t) memchr(ra_2 + 1, 0xC, 12), 0x80002224);


} END_TEST
