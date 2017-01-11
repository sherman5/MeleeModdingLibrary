#include "../random.h"

float rand()
{
    return (float) randUint32() / 0xFFFFFFFF;
}
