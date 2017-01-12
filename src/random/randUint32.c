#include "../random.h"
#include "../melee.h"

uint32_t randUint32()
{
    void (*randu)() = RANDU_FPTR;    
    randu();
    return *((uint32_t*) RAND_ADDRESS);
}
