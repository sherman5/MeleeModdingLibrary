#include <mml/melee_info.h>
#include <mml/random.h>
#include <mml/math.h>
#include <mml/game_state.h>

#include "spacieRecovery.h"
#include "recovery.h"
#include "cpuLogic.h"

#define SQUARE(x) ((x) * (x))
/*
static float getFireHeight(AI* ai, float length)
{
    if (length < abs_x - ledge.x) {return coords.y;}

    float minHeight = sqrt(SQUARE(length) - SQUARE(abs_x - ledge.x));
    
}

static float getFireAngle(AI* ai, float length, float height)
{


}

static void fireRecovery(AI* ai)
{
    float fireLength = character == FALCO_ID ?
        70.f : 90.f;
    float height = getFireHeight(ai, fireLength);
    float angle = getFireAngle(ai, fireLength, height);
   
    upBLogic.condition.arg2.f = height;
    SET_UP_B_DIR(angle);
    addLogic(ai, &upBLogic);
}

static void illusionRecovery(AI* ai)
{
    float height;
    float u = rand();

    if (coords.y > _gameState.stage.side.height && u < 0.4f)
    {
        height = _gameState.stage.side.height;        
    }
    else if (u < 0.8f)
    {
        height = ledge.y;
    }
    else
    {
        height = uniform(ledge.y, coords.y);
    }

    sideBLogic.condition.arg2.f = height;
    SET_SIDE_B_DIR(stageDir);
    addLogic(ai, &sideBLogic);
}
*/
void spacieRecovery(AI* ai)
{
/*    float illusionLength = character == FALCO_ID ?
        78.f : 87.f;

    if (coords.y > ledge.y
        && abs_x - illusionLength < ledge.x
        && chance(0.25f))
    {
        illusionRecovery(ai);
    }
    else if (jumps > 0)
    {
        SET_DJ_DIR(stageDir);
        addMove(ai, &_mv_doubleJump);
        addLogic(ai, &hitDuringMoveLogic);

        clearAfterFrameLogic.condition.arg1.u = CURRENT_FRAME + 10;
        addLogic(ai, &clearAfterFrameLogic);
    }
    else
    {
        fireRecovery(ai);
    } */
}


