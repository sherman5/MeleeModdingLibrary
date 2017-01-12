#include "testing.h"
#include <stdbool.h>

void fltEq(float L, float R)
{
    float val = L - R;
    if (!AZERO(val, 0.001)) {*((float*) output) = L;}
    ++output;
}

void intEq(uint32_t L, uint32_t R)
{
    if (L != R) {*output = L;}
    ++output;
}

void intNeq(uint32_t L, uint32_t R)
{
    if (L == R) {*output = L;}
    ++output;
}

void fltLess(float L, float R)
{
    if (L > R) {*output = L;}
    ++output;
}

void runTest(int);

uint32_t* output = (uint32_t*) 0x80001804;
bool init = false;
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
    runTest(runs++);

    /* check if all tests are passing */
    output = (uint32_t*) 0x80001804;
    for (int i = 0; i < numTests; ++i)
    {
        if (*(output++) & 0xFFFF0000 != 0xAAAA0000)
        {
            *((uint32_t*) 0x80001800) = 0xFFFFFFFF;
        }   
    }
}