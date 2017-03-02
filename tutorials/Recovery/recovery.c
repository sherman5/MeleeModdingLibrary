#include <mml/state_check.h>
#include <mml/AI.h>
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

Point ledge;
Point coords;
float abs_x;
bool leftSide;
float stageDir;
u32 jumps;
u32 character;
s32 horizJump, vertJump;
s32 charHeight;

static void setGlobalVariables(AI* ai)
{
    ledge.x = _gameState.stage.ledge;
    ledge.y = -10.f;

    coords.x = _gameState.playerData[ai->port]->coordinates.x;
    coords.y = _gameState.playerData[ai->port]->coordinates.y;
    abs_x = fabs(coords.x);

    leftSide = coords.x < 0;
    stageDir = leftSide ? 0.f : 180.f;

    jumps = _gameState.playerData[ai->port]->jumpsUsed;

    character = CHAR_SELECT(ai->port);

    horizJump = ((s32) _dj_horizontal[character]);
    vertJump = ((s32) _dj_vertical[character]);
    charHeight = ((s32) _char_height[character]);
}

static bool closeRecovery(AI* ai)
{
    if (coords.y < -(vertJump + charHeight)
    || abs_x > ledge.x + horizJump
    || jumps < 1)
    {
        return false;
    }
    else if (coords.y > _gameState.stage.side.height - vertJump
    && abs_x < _gameState.stage.side.right + horizJump
    && jumps > 0
    && chance(0.5f))
    {
        addMoveAtHeightLogic.condition.arg2.f = _gameState.stage.side.height
            - vertJump;
    }
    else
    {
        recoveryJumpLogic.condition.arg2.f = -(vertJump + charHeight);
    }

    SET_DJ_DIR(stageDir);
    addLogic(ai, &recoveryJumpLogic);
    return true;
} 

void recovery(AI* ai)
{
    setGlobalVariables(ai);

    SET_HOLD_DIR(stageDir);
    addMove(ai, &_mv_holdDirection);

    if (!closeRecovery(ai))
    {
        switch (character)
        {
            case FALCO_ID:
            case FOX_ID:
                spacieRecovery(ai);
                break;
            case MARTH_ID:
                marthRecovery(ai);
                break;
            case FALCON_ID:
       //         falconRecovery(ai);
                break;
        }
    }
}

void ledgeOption(AI* ai)
{
    addMove(ai, &_mv_ledgeDash);
    addLogic(ai, &clearWhenWaitLogic);
}
