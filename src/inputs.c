#include "inputs.h"

RawInput _raw_shNeutralB[4] = 
{
    {X_BUTTON, 0, NO_FLAGS},
    {RELEASE, -1, JUMPSQUAT},
    {B_BUTTON, 11, JUMPSQUAT},
    {RELEASE, 0, JUMPSQUAT | SH_LENGTH}
};
Move _mv_shNeutralB = {.inputs = _raw_shNeutralB, .size = 4};

RawInput _raw_shortHop[2] = 
{
    {X_BUTTON, 0, NO_FLAGS},
    {RELEASE, -1, JUMPSQUAT}
};
Move _mv_shortHop = {.inputs = _raw_shortHop, .size = 2};

RawInput _raw_tech[2] = 
{
    {0, 0, 0}, //overwritten when direction is set
    {RELEASE, 26, NO_FLAGS}
};
Move _mv_tech = {.inputs = _raw_tech, .size = 2};

RawInput _raw_spotDodge[3] = 
{
    {L_BUTTON, 0, NO_FLAGS},
    {CSTICK_DOWN, 1, NO_FLAGS},
    {RELEASE, 2, NO_FLAGS}
};
Move _mv_spotDodge = {.inputs = _raw_spotDodge, .size = 3};

RawInput _raw_aPress[2] = 
{
    {A_BUTTON, 0, NO_FLAGS},
    {RELEASE, 2, NO_FLAGS}
};
Move _mv_getUpAttack = {.inputs = _raw_aPress, .size = 2};
Move _mv_jab = {.inputs = _raw_aPress, .size = 2};

RawInput _raw_DI[2] = 
{
    {0, 0, 0},
    {RELEASE, 1, NO_FLAGS}
};
Move _mv_DI = {.inputs = _raw_DI, .size = 2};








