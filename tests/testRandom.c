#include <random.h>

int _main()
{
    /* output test results starting here */
    uint32_t* outputAddress = (uint32_t*) 0x80001800;

    /* initialize memory to zero */
    if (*outputAddress != 0xabcdabcd)
    {
        for (unsigned i = 1; i <= 20; ++i)
        {
            *(outputAddress + i) = 0;
        }

        *outputAddress = 0xabcdabcd;
    }

    /* store results of random values */
    float f = rand();

    /* put random numbers into buckets */
    /* buckets range from 80001804-80001850 */
    unsigned index = 0;
    while (index < 20)
    {
        if (f >= (float) index / 20 && f < (float) (index + 1) / 20)
        {
            *(outputAddress + 1 + index) += 1;
        }
        ++index;
    }
}
