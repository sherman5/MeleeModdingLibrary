#include <mml/AI.h>
#include <mml/logic.h>
#include <mml/state_check.h>
#include <mml/action_state.h>
#include <mml/gctypes.h>
#include <mml/moves.h>

#include "cpuLogic.h"
#include "teching.h"
#include "recovery.h"
#include "DI.h"

AI cpuPlayer = INIT_AI(2, FALCO | FOX | MARTH | FALCON);

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

Logic hitDiLogic = 
{
    {&hitlagFrames, .arg1.u = 2, .arg2.u = 1},
    {&hitDI, .arg1.p = &cpuPlayer}
};

Logic throwDiLogic =
{
    {&actionStateEq, .arg1.u = 2, .arg2.u = _AS_CaptureWaitLw},
    {&throwDI, .arg1.p = &cpuPlayer}
};

Logic stopThrowDiLogic = 
{
    {&breakoutFrame, .arg1.u = 2, .arg2.u = 0},
    {&stopThrowDI, .arg1.p = &cpuPlayer}
};

Logic clearAfterFrameLogic = 
{
    {&pastFrame},
    {&clearAI, .arg1.p = &cpuPlayer}
};

Logic recoveryStartLogic = 
{
    {&recoverySituation, .arg1.u = 2},
    {&recovery, .arg1.p = &cpuPlayer}
};

Logic clearWhenWaitLogic = 
{
    {&actionStateEq, .arg1.u = 2, .arg2.u = _AS_Wait},
    {&clearAI, .arg1.p = &cpuPlayer}
};

Logic onLedgeLogic = 
{
    {&actionStateEq, .arg1.u = 2, .arg2.u = _AS_CliffWait},
    {&ledgeOption, .arg1.p = &cpuPlayer}
};    

Logic respawnLogic = 
{
    {&actionStateEq, .arg1.u = 2, .arg2.u = _AS_RebirthWait},
    {&addMove, .arg1.p = &cpuPlayer, .arg2.p = &_mv_shortHop}
};

Logic sideBLogic = 
{
    {&belowHeight, .arg1.u = 2, .arg2.f = 0.f},
    {&addMove, .arg1.p = &cpuPlayer, .arg2.p = &_mv_sideB}
};

Logic upBLogic = 
{
    {&belowHeight, .arg1.u = 2, .arg2.f = 0.f},
    {&addMove, .arg1.p = &cpuPlayer, .arg2.p = &_mv_upB}
};

Logic recoveryJumpLogic = 
{
    {&belowHeight, .arg1.u = 2, .arg2.f = 0.f},
    {&addMove, .arg1.p = &cpuPlayer, .arg2.p = &_mv_doubleJump}
};

Logic addMoveAtHeightLogic = 
{
    {&belowHeight, .arg1.u = 2},
    {&addMove, .arg1.p = &cpuPlayer}
};


