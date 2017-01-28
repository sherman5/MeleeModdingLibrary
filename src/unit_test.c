#include "unit_test.h"
#include <stdbool.h>

bool AZERO(float diff, float tol)
{
    return a > b ? a - b < tol : b - a < tol;
}

void requireInt(bool cond, int value)
{
    if (!cond) {*output = value;}
    ++output;
}

void requireFloat(bool cond, float value)
{
    if (!cond) {*output = value;}
    ++output;
}

void runTest();

uint32_t* output = (uint32_t*) 0x80001804;
static bool init = false;
static int runs = 0;

void _main()
{
    /* intialize memory */
    if (!init)
    {
        *((uint32_t*) 0x80001800) = 0xAAAAAAAA;
        for (int i = 0; i < numTests; ++i)
        {
            *(output++) = 0xAAAA0000;
        }
        init = true;
    }

    /* run tests, reset output address */
    output = (uint32_t*) 0x80001804;
    runTest();
    runs++;
 
    /* check if all tests are passing */
    output = (uint32_t*) 0x80001804;
    for (int i = 0; i < numTests; ++i)
    {
        if ((*(output++) & 0xFFFF0000) != 0xAAAA0000)
        {
            *((uint32_t*) 0x80001800) = 0xFFFFFFFF;
        }   
    }
}
