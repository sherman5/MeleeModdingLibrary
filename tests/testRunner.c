#include "testing.h"

/* declare test functions */
void testRandom(uint32_t);
void testMath(uint32_t);

//const uint32_t numTests = __COUNTER__;
static uint32_t runs = 0;
static uint32_t* init_key = (uint32_t*) 0x80001800;

int _main()
{
    if (*init_key != 0xabcdabcd)
    {
        /* zero out memory for test results */
        /*for (uint32_t i = 1; i <= numTests; ++i)
        {
            *(init_key + i) = 0x000EEEE000;
        }*/

        /* store key value */
        *init_key = 0xabcdabcd;
    }

    /* run tests, reset output address */
    outputAddress = (uint32_t*) 0x80001804;
    //testRandom(runs);
    //testMath(runs);
    //runs++;
}