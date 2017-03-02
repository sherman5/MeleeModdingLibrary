#include <mml/game_state.h>

#include "falconRecovery.h"
#include "recovery.h"
#include "cpuLogic.h"

#define KICK_HEIGHT 50.f
#define KICK_DIST   50.f

void falconRecovery(AI* ai)
{
    if (jumps > 0)
    {
        SET_DJ_DIR(stageDir);
        addMove(ai, &_mv_doubleJump);
        clearAfterFrameLogic.condition.arg1.u = CURRENT_FRAME + 10;
        addLogic(ai, &clearAfterFrameLogic);
    }
    else if (coords.y > KICK_HEIGHT && abs_x - ledge.x > KICK_DIST)
    {
        addMove(ai, &_mv_downB);
    }
    else 
    {
        SET_UP_B_DIR(stageDir);
        addMove(ai, &_mv_upB);
    }
}
