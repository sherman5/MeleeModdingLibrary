#include "inputs.h"

const Input shNeutralB[5] = {
    JUMP(0, NO_FLAGS),
    RELEASE_BUTTONS(1, JUMPSQUAT),
    NEUTRAL_B(5, JUMPSQUAT),
    SET_STICK(10, 255, -90, JUMPSQUAT),
    RELEASE_STICK(15, JUMPSQUAT)
};