#include "inputs.h"

RawInput raw_shNeutralB[4] = 
{
    {0, NO_FLAGS, X_BUTTON},
    {-1, JUMPSQUAT, RELEASE},
    {11, JUMPSQUAT, B_BUTTON},
    {0, JUMPSQUAT | SH_LENGTH, RELEASE}
};

Move shNeutralB = {.inputs = raw_shNeutralB, .size = 4};

RawInput raw_shortHop[2] = 
{
    {0, NO_FLAGS, X_BUTTON},
    {-1, JUMPSQUAT, RELEASE}
};

Move shortHop = {.inputs = raw_shortHop, .size = 2};
