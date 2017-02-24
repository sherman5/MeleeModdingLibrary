#include <mml/AI.h>
#include <mml/logic.h>
#include <mml/state_check.h>
#include <mml/action_state.h>
#include <mml/gctypes.h>

#include "cpuLogic.h"
#include "teching.h"
#include "DI.h"

AI cpuPlayer = {.port = 2, .active = false,
    .characters = FALCO | FOX | MARTH | FALCON};

Logic hitTechLogic = 
{
    {&techSituation, .arg1.u = 2},
    {&hitTech, .arg1.p = &cpuPlayer}
};

Logic getOffGroundLogic = 
{
    {&fallenDown, .arg1.u = 2},
    {&getUpFromGround, .arg1.p = &cpuPlayer}
};

Logic hitDuringMoveLogic = 
{
    {&inHitlag, .arg1.u = 2},
    {&clearAI, .arg1.p = &cpuPlayer}
};

Logic actAfterTechLogic = 
{
    {&actionStateEq, .arg1.u = 2, .arg2.u = _AS_Wait},
    {&postTechOption, .arg1.p = &cpuPlayer}
};

Logic diLogic = 
{
    {&hitlagFrames, .arg1.u = 2, .arg2.u = 1},
    {&inputDI, .arg1.p = &cpuPlayer}
};


