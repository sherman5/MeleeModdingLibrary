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
        SET_DJ_DIR(rInfo.stageDir);
        addMove(ai, &_mv_doubleJump);
        resetAfterFrameLogic.condition.arg1.u = CURRENT_FRAME + 15;
        addLogic(ai, &resetAfterFrameLogic);
    }
    else if (rInfo.coords.y > KICK_HEIGHT
    && rInfo.abs_x - rInfo.ledge.x > KICK_DIST)
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
}
