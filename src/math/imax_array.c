#include "../math.h"
#include <stdint.h>

int32_t imax_array(int32_t ra[])
{
    int32_t max = ra[0];
    for (unsigned int i = 0; i < sizeof(ra) / sizeof(ra[0]); ++i)
    {
        if (max < ra[i]) {max = ra[i];}
    }
}