#include <mml/state_check.h>
#include <mml/ai.h>
#include <mml/moves.h>
#include <mml/game_state.h>
#include <mml/math.h>
#include <mml/melee_info.h>
#include <mml/random.h>
#include <mml/gctypes.h>

#include "recovery.h"
#include "marthRecovery.h"
#include "falconRecovery.h"
#include "spacieRecovery.h"
#include "cpuLogic.h"

RecoveryInfo rInfo = {0};

void addCleanUpLogic(AI* ai)
{
    addLogic(ai, &onLedgeLogic);    
    addLogic(ai, &resetOnHitLogic);
    addLogic(ai, &resetOnWaitLogic);
    addLogic(ai, &resetOnDeathLogic);
    addLogic(ai, &resetOnStageLogic);
}

void doubleJump(AI* ai, float target)
{
    setGlobalVariables(ai);
    float dist = fmax(rInfo.dist, target - 30.f);
    dist = fmin(dist, target + 30.f);

    float dir = (dist - (target - 30.f)) * 180.f / 60.f;
    dir = rInfo.leftSide ? 180.f - dir : dir;

    SET_DJ_DIR(dir);
    addMove(ai, &_mv_doubleJump);
}

void setGlobalVariables(AI* ai)
{
    rInfo.ledge.x = _gameState.stage.ledge.x;
    rInfo.ledge.y = _gameState.stage.ledge.y;

    rInfo.coords.x = _gameState.playerData[ai->port]->coordinates.x;
    rInfo.coords.y = _gameState.playerData[ai->port]->coordinates.y;
    rInfo.abs_x = fabs(rInfo.coords.x);
    rInfo.dist = rInfo.abs_x - rInfo.ledge.x;

    rInfo.leftSide = rInfo.coords.x < 0;
    rInfo.stageDir = rInfo.leftSide ? 0.f : 180.f;

    rInfo.jumps = 2 - (u32) _gameState.playerData[ai->port]->jumpsUsed;

    rInfo.character = CHAR_SELECT(ai->port);

    rInfo.horizJump = _dj_horizontal[rInfo.character];
    rInfo.vertJump = _dj_vertical[rInfo.character];
    rInfo.charHeight = _char_height[rInfo.character];
}

#define CANT_CLOSE_RECOVER  \
    rInfo.jumps < 1 || \
    rInfo.dist > rInfo.horizJump || \
    rInfo.coords.y < -(rInfo.vertJump + rInfo.charHeight - rInfo.ledge.y)

#define JUMP_TO_PLATFORM \
    chance(0.5f) && \
    rInfo.jumps > 0 && \
    rInfo.abs_x < _gameState.stage.side.right + rInfo.horizJump && \
    rInfo.coords.y > _gameState.stage.side.height - rInfo.vertJump

static bool closeRecovery(AI* ai)
{
    if (CANT_CLOSE_RECOVER)
    {
        return false;
    }
    else if (JUMP_TO_PLATFORM)
    {
        doubleJumpRecoveryLogic.condition.arg2.f = 
            _gameState.stage.side.height - rInfo.vertJump;

    }
    else //jump to ledge
    {
        doubleJumpRecoveryLogic.condition.arg2.f = 
            -(rInfo.vertJump + rInfo.charHeight - rInfo.ledge.y);
    }

    if (JUMP_TO_PLATFORM || rInfo.dist > 20.f)
    {
        SET_HOLD_DIR(rInfo.stageDir);
        addMove(ai, &_mv_holdDirection);
    }

    addLogic(ai, &doubleJumpRecoveryLogic);
    addCleanUpLogic(ai);
    return true;
}

void doubleJumpRecovery(AI* ai)
{
    doubleJump(ai, 5.f);
    
    resetAfterFrameLogic.condition.arg1.u = CURRENT_FRAME + 40;
    addLogic(ai, &resetAfterFrameLogic);
    addCleanUpLogic(ai);
}

void recover(AI* ai)
{
    setGlobalVariables(ai);

    if (!closeRecovery(ai))
    {
        switch (rInfo.character)
        {
            case FALCO_ID:
            case FOX_ID:
                spacieRecovery(ai);
                break;
            case MARTH_ID:
                marthRecovery(ai);
                break;
            case FALCON_ID:
                falconRecovery(ai);
                break;
        }
    }
}

void ledgeOption(AI* ai)
{
    setGlobalVariables(ai);
    float ang = rInfo.stageDir > 90.f ? 200.f : 340.f;
    SET_LEDGEDASH_ANGLE(ang);
    addMove(ai, &_mv_ledgeDash);
}
