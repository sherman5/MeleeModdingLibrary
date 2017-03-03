#include <mml/game_state.h>

#include "falconRecovery.h"
#include "recovery.h"
#include "cpuLogic.h"

#define KICK_HEIGHT 50.f
#define KICK_DIST   50.f

void falconRecovery(AI* ai)
{
    if (rInfo.jumps > 0)
    {
        doubleJump(ai, 30.f);
        resetAfterFrameLogic.condition.arg1.u = CURRENT_FRAME + 20;
        addLogic(ai, &resetAfterFrameLogic);
    }
    else if (rInfo.coords.y > KICK_HEIGHT && rInfo.dist > KICK_DIST)
    {
        addMove(ai, &_mv_downB);
        resetAfterFrameLogic.condition.arg1.u = CURRENT_FRAME + 60;
        addLogic(ai, &resetAfterFrameLogic);
    }
    else 
    {
        SET_UP_B_DIR(rInfo.stageDir);
        addMove(ai, &_mv_upB);
    }
    addCleanUpLogic(ai);
}
