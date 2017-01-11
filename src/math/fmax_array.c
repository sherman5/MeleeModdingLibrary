#include "../math.h"

float fmax_array(float ra[])
{
    float max = ra[0];
    for (unsigned int i = 0; i < sizeof(ra) / sizeof(ra[0]); ++i)
    {
        if (max < ra[i]) {max = ra[i];}
    }
}
