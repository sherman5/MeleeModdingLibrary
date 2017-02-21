#include <unit_test.h>
#include <system.h>
#include <math.h>
#include <string.h>
#include <random.h>
#include <gctypes.h>

UNIT_TEST;

static bool init = false;
static char heap[21000];

static bool tests_run = false;

static float min1 = 1.0, max1 = 0.0;
static float min2 = 9.5, max2 = 9.3;
static int min3 = 4, max3 = 0, sum = 0;

void _init(void)
{
    initHeap(heap, heap + sizeof(heap));
}

void _main(void)
{
    if (!init) { _init(); init = true;}

    if (!tests_run)
    {
        float probs[5] = {0.1, 0.3, 0.4, 0.1, 0.1};

        for (unsigned i = 0; i < 10000; ++i)
        {
            REQUIRE(rand() >= 0);
            REQUIRE(rand() <= 1);

            min1 = fmin(rand(), min1);
            max1 = fmax(rand(), max1);

            min2 = fmin(uniform(9.3, 9.5), min2);
            max2 = fmax(uniform(9.3, 9.5), max2);

            min3 = imin(sample(probs, 5), min3);
            max3 = imax(sample(probs, 5), max3);
            sum += sample(probs, 5);
        }
        
        REQUIRE(min1 >= 0);
        REQUIRE(max1 <= 1); 

        REQUIRE(min2 >= 9.3);
        REQUIRE(max2 <= 9.5);

        REQUIRE(min3 == 0);
        REQUIRE(max3 == 4);

        REQUIRE(sum > 17650);
        REQUIRE(sum < 18350);

        END_TEST;
        tests_run = true;
    }
}


