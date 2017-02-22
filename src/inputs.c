#include "inputs.h"

RawInput raw_shNeutralB[4] = 
{
    {X_BUTTON, 0, NO_FLAGS},
    {RELEASE, -1, JUMPSQUAT},
    {B_BUTTON, 11, JUMPSQUAT},
    {RELEASE, 0, JUMPSQUAT | SH_LENGTH}
};

Move shNeutralB = {.inputs = raw_shNeutralB, .size = 4};

RawInput raw_shortHop[2] = 
{
    {X_BUTTON, 0, NO_FLAGS},
    {RELEASE, -1, JUMPSQUAT}
};

Move shortHop = {.inputs = raw_shortHop, .size = 2};
