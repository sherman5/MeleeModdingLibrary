#include <mml/state_check.h>
#include <mml/AI.h>
#include <mml/moves.h>
#include <mml/action_state.h>
#include <mml/game_state.h>
#include <mml/math.h>
#include <mml/random.h>

#include "hitstun.h"
#include "recovery.h"
#include "cpuLogic.h"

void exitHitstun(AI* ai)
{
    float minDelay = 20 - 2 * _gameState.playerData[ai->port]->aiLevel;
    u32 delay = (u32) uniform(minDelay, minDelay + 10.f);

    actOutOfHitstunLogic.condition.arg1.u = CURRENT_FRAME + delay;
    addLogic(ai, &actOutOfHitstunLogic);

    addLogic(ai, &onLedgeLogic);    
    addLogic(ai, &resetOnHitLogic);
    addLogic(ai, &resetOnWaitLogic);
    addLogic(ai, &resetOnGroundLogic);
    addLogic(ai, &resetOnDeathLogic);
    addLogic(&cpuPlayer, &hitTechLogic);
    addLogic(&cpuPlayer, &recoveryLogic);
}

void actOutOfHitstun(AI* ai)
{
    doubleJump(ai, -40.f);
    resetAfterFrameLogic.condition.arg1.u = CURRENT_FRAME + 10;
    addLogic(ai, &resetAfterFrameLogic);
    addLogic(ai, &onLedgeLogic);    
    addLogic(ai, &resetOnHitLogic);
}
