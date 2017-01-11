#include "testing.h"

#define NUM_TESTS 3 //jank

/* declare test functions */
void testRandom(uint32_t);
void testMath(uint32_t);

static uint32_t runs = 0;
static uint32_t* init_key = (uint32_t*) 0x80001800;
uint32_t* outputAddress = 0; //need to initialize extern variable (sbss)

int _main()
{
    if (*init_key != 0xabcdabcd)
    {
        /* zero out memory for test results */
        for (uint32_t i = 1; i <= NUM_TESTS; ++i)
        {
            *(init_key + i) = 0x000EEEE000;
        }

        /* store key value */
        *init_key = 0xabcdabcd;
    }

    /* run tests, reset output address */
    outputAddress = (uint32_t*) 0x80001804;
    //testRandom(runs);
    testMath(runs);
    runs++;
}