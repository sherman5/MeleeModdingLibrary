#include <mml/print.h>
#include <mml/state_check.h>
#include <mml/AI.h>
#include <mml/moves.h>
#include <mml/action_state.h>
#include <mml/game_state.h>
#include <mml/math.h>
#include <mml/melee_info.h>
#include <mml/random.h>

#include "recovery.h"
#include "cpuLogic.h"

static Point ledge;

#define X_COORD(p)          _gameState.playerData[p]->coordinates.x
#define Y_COORD(p)          _gameState.playerData[p]->coordinates.y
#define JUMPS_USED(p)       _gameState.playerData[p]->jumpsUsed

#define STAGE               _gameState.stage

#define HORIZONTAL_DJ       ((s32) _dj_horizontal[CHAR_SELECT(ai->port)])
#define VERTICAL_DJ         ((s32) _dj_vertical[CHAR_SELECT(ai->port)])

//attempt to recover with DJ, airdodge
static bool closeRecovery(AI* ai)
{
    float abs_x = fabs(X_COORD(ai->port));

    if (Y_COORD(ai->port) < -VERTICAL_DJ
        || abs_x > ledge.x + HORIZONTAL_DJ || JUMPS_USED(ai->port) > 1)
    {
        return false;
    }
    else if (Y_COORD(ai->port) > STAGE.side.height - VERTICAL_DJ
        && abs_x < STAGE.side.right + HORIZONTAL_DJ
        && chance(0.5f))
    {
        //jump to platform
    }
    else if (chance(0.25f))
    {
        //jump airdodge to stage
    }
    else
    {
        //jump to ledge
    }
    
} 

static void spacieRecovery(AI* ai)
{
}

static void marthRecovery(AI* ai)
{

}

static void falconRecovery(AI* ai)
{

}

void recovery(AI* ai)
{
    ledge.x = _gameState.stage.ledge;
    ledge.y = 0.f;

    if (!closeRecovery(ai))
    {
        switch (CHAR_SELECT(ai->port))
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


