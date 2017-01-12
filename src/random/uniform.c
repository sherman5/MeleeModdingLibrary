#include "../random.h"

float uniform(float a, float b)
{
    return rand() * (b - a) + a;
}