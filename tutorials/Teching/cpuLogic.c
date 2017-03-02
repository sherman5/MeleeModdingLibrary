#include <mml/AI.h>
#include <mml/logic.h>
#include <mml/state_check.h>
#include <mml/action_state.h>
#include <mml/gctypes.h>
#include <mml/moves.h>

#include "cpuLogic.h"
#include "teching.h"

AI cpuPlayer = INIT_AI(2, FALCO | FOX | MARTH | FALCON);

Logic respawnLogic = 
{
    {&actionStateEq, .arg1.u = 2, .arg2.u = _AS_RebirthWait},
    {&addMove, .arg1.p = &cpuPlayer, .arg2.p = &_mv_shortHop}
};

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

Logic resetOnHitLogic = 
{
    {&inHitlag, .arg1.u = 2},
    {&clearAI, .arg1.p = &cpuPlayer}
};

Logic resetOnWaitLogic = 
{
    {&actionStateEq, .arg1.u = 2, _AS_Wait},
    {&clearAI, .arg1.p = &cpuPlayer}
};

Logic actAfterTechLogic = 
{
    {&actionStateEq, .arg1.u = 2, .arg2.u = _AS_Wait},
    {&postTechOption, .arg1.p = &cpuPlayer}
};




