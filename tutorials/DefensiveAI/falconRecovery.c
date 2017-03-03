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
        doubleJump(ai, 40.f);
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
        float dir = rInfo.dist > 30.f ? rInfo.stageDir : 90.f;
        if (rInfo.dist < 0.f) {dir = rInfo.stageDir + 180.f;}

        SET_UP_B_DIR(dir);
        addMove(ai, &_mv_upB);
    }
    addCleanUpLogic(ai);
}
