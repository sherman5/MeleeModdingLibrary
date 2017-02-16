#include "inputs.h"

RawInput raw_shNeutralB[5] = 
{
    {0, NO_FLAGS, X_PRESS},
    {1, JUMPSQUAT, RELEASE},
    {5, JUMPSQUAT, B_PRESS},
    {10, JUMPSQUAT, FULL_STICK || STICK_ANGLE(270)},
    {15, JUMPSQUAT, RELEASE}
};

const Move shNeutralB = {&raw_shNeutralB, 5};
