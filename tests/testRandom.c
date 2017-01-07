#include <random.h>

int _main()
{
    /* output test results starting here */
    uint32_t* outputAddress = (uint32_t*) 0x80001800;

    /* initialize memory to zero */
    if (*outputAddress != 0xabcdabcd)
    {
        for (unsigned i = 1; i <= 10; ++i)
        {
            *(outputAddress + i) = 0;
        }

        *outputAddress = 0xabcdabcd;
    }

    /* store results of random values */
    float f = rand();

    /* put random numbers into buckets */
    unsigned index = 0;
    while (index < 20)
    {
        if (f > index / 20 && f < (index + 1) / 20)
        {
            *((uint32_t*) (0x80001804 + 0x04 * index)) += 1;
        }
        ++index;
    }    
}
