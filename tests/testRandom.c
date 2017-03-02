#include <unit_test.h>
#include <system.h>
#include <math.h>
#include <string.h>
#include <random.h>
#include <gctypes.h>

UNIT_TEST;

static bool init = false;
static char heap[13000];

static bool tests_run = false;

static float min1 = 1.0, max1 = 0.0;
static float min2 = 9.5, max2 = 9.3;
static int min3 = 4, max3 = 0, sample_sum = 0, chance_sum = 0;

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

        f32* a = (f32*) 0x80001800;
        for (; a < (f32*) 0x80002400; a++)
        {
            *a = rand();
        }

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
            sample_sum += sample(probs, 5);
            if (chance(0.3f)) { chance_sum++; }
        }
        
        REQUIRE(min1 >= 0);
        REQUIRE(max1 <= 1); 

        REQUIRE(min2 >= 9.3);
        REQUIRE(max2 <= 9.5);

        REQUIRE(min3 == 0);
        REQUIRE(max3 == 4);

        REQUIRE(sample_sum > 17650);
        REQUIRE(sample_sum < 18350);

        REQUIRE(chance_sum > 2000);
        REQUIRE(chance_sum < 4000);

        END_TEST;
        tests_run = true;
    }
}


