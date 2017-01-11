#include "../math.h"
#include <stdint.h>

int32_t imin_array(int32_t ra[])
{
    int32_t min = ra[0];
    for (unsigned int i = 0; i < sizeof(ra) / sizeof(ra[0]); ++i)
    {
        if (min > ra[i]) { min = ra[i];}        
    }
}