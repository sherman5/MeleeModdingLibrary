#include "moves.h"

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
    {OVERWRITE, 0, NO_FLAGS},
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

RawInput _raw_hitDI[2] = 
{
    {OVERWRITE, 0, NO_FLAGS},
    {RELEASE, 1, NO_FLAGS}
};
Move _mv_hitDI = {.inputs = _raw_hitDI, .size = 2};

RawInput _raw_holdDirection[1] = 
{
    {OVERWRITE, 0, NO_FLAGS}
};
Move _mv_holdDirection = {.inputs = _raw_holdDirection, .size = 1};
Move _mv_throwDI = {.inputs = _raw_holdDirection, .size = 1};

RawInput _raw_upB[2] = 
{
    {B_BUTTON | FULL_STICK | STICK_ANGLE(90.f), 0, NO_FLAGS},
    {OVERWRITE, 2, NO_FLAGS}
};
Move _mv_upB = {.inputs = _raw_upB, .size = 2};

RawInput _raw_doubleJump[1] = 
{
    {OVERWRITE, 0, NO_FLAGS}
};
Move _mv_doubleJump = {.inputs = _raw_doubleJump, .size = 1};

RawInput _raw_ledgeDash[4] = 
{
    {FULL_STICK | STICK_ANGLE(270.f), 2, NO_FLAGS},
    {X_BUTTON, 3, NO_FLAGS},
    {OVERWRITE, 3, LEDGEDASH},
    {RELEASE, 14, LEDGEDASH}
};
Move _mv_ledgeDash = {.inputs = _raw_ledgeDash, .size = 4};
    
RawInput _raw_sideB[1] = 
{
    {OVERWRITE, 0, NO_FLAGS}
};
Move _mv_sideB = {.inputs = _raw_sideB, .size = 1};

RawInput _raw_downB[2] = 
{
    {B_BUTTON | FULL_STICK | STICK_ANGLE(270.f), 0, NO_FLAGS},
    {RELEASE, 2, NO_FLAGS}
};
Move _mv_downB = {.inputs = _raw_downB, .size = 2};

RawInput _raw_wavedash[3] = 
{
    {X_BUTTON, 0, NO_FLAGS},
    {OVERWRITE, 0, JUMPSQUAT},
    {RELEASE, 2, JUMPSQUAT}
};
Move _mv_wavedash = {.inputs = _raw_wavedash, .size = 3};
   