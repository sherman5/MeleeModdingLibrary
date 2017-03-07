#include <mml/melee_info.h>
#include <mml/random.h>
#include <mml/math.h>
#include <mml/game_state.h>

#include "spacieRecovery.h"
#include "recovery.h"
#include "cpuLogic.h"

#define SQUARE(x) ((x) * (x))

static void fireRecovery(AI* ai)
{
    float fireLength = rInfo.character == FALCO_ID ? 70.f : 90.f;

    if (fireLength < rInfo.dist)
    {
        fireRecoveryLogic.condition.arg2.f = 30.f;
    }
    else 
    {
        float maxHeight = sqrt(SQUARE(fireLength) - SQUARE(rInfo.dist));
        maxHeight = fmax(maxHeight - 10.f, 1.f);
        fireRecoveryLogic.condition.arg2.f = uniform(-maxHeight, maxHeight);
    }

    if (rInfo.dist > 50.f)
    {
        SET_HOLD_DIR(rInfo.stageDir);
        addMove(ai, &_mv_holdDirection);
    }

    addLogic(ai, &fireRecoveryLogic);
    addCleanUpLogic(ai);
}

static void illusionRecovery(AI* ai, float length)
{
    float u = rand();

    if (_gameState.stage.side.height > 1.f
        && rInfo.coords.y > _gameState.stage.side.height
        && rInfo.abs_x - _gameState.stage.side.left > length
        && u < 0.5f)
    {
        illusionRecoveryLogic.condition.arg2.f =
            _gameState.stage.side.height - 1.f;        
    }
    else if (u < 0.8f)
    {
        u32 maxError = 18 - 2 * _gameState.playerData[ai->port]->aiLevel;

        illusionRecoveryLogic.condition.arg2.f = rInfo.ledge.y - 15.f
            + uniform(0.f, (float) maxError);
    }
    else
    {
        illusionRecoveryLogic.condition.arg2.f = 
            uniform(rInfo.ledge.y, rInfo.coords.y);
    }

    SET_HOLD_DIR(rInfo.stageDir);
    addMove(ai, &_mv_holdDirection);

    addLogic(ai, &illusionRecoveryLogic);
    addCleanUpLogic(ai);
}

void spacieIllusion(AI* ai)
{
    SET_SIDE_B_DIR(rInfo.stageDir);
    addMove(ai, &_mv_sideB);
    addCleanUpLogic(ai);
}

static float reflectAngle(float ang)
{
    ang = 180.f - ang;
    return ang < 0.f ? ang + 360.f : ang;
}

void spacieFire(AI* ai)
{
    setGlobalVariables(ai); //called from logic

    Point ledge_pt = {rInfo.ledge.x, rInfo.ledge.y - 10.f};
    Point coord_pt = {rInfo.abs_x, rInfo.coords.y};
    float ledgeAngle = angle(coord_pt, ledge_pt);

    float fireLength = rInfo.character == FALCO_ID ? 70.f : 90.f;
    float highAngle = reflectAngle(acos(rInfo.dist / fireLength));

    float ang = chance(0.4f) ? ledgeAngle : uniform(ledgeAngle, highAngle);

    if (ang >  73.f && ang <  85.f) {ang = 73.f;}
    if (ang < 180.f && ang > 163.f) {ang = 163.f;}
    if (ang > 253.f && ang < 265.f) {ang = 253.f;}

    if (rInfo.dist > fireLength) {ang = 135.f;}

    if (rInfo.leftSide) {ang = reflectAngle(ang);}
    SET_UP_B_DIR(ang);
    addMove(ai, &_mv_upB);

    postFireLogic.condition.arg1.u = CURRENT_FRAME + 45;
    addLogic(ai, &postFireLogic);
    addCleanUpLogic(ai);
}

void spacieRecovery(AI* ai)
{
    float illusionLength = rInfo.character == FALCO_ID ? 85.f : 95.f;
    float illusionProb = 0.3f + (rInfo.jumps > 0 ? 0.2f : 0.f)
        + (rInfo.character == FALCO_ID ? 0.1f : 0.f);

    if (rInfo.coords.y > rInfo.ledge.y - 13.f && illusionLength > rInfo.dist
        && chance(illusionProb))
    {
        illusionRecovery(ai, illusionLength);
    }
    else if (rInfo.jumps > 0)
    {
        doubleJump(ai, 40.f);

        resetAfterFrameLogic.condition.arg1.u = CURRENT_FRAME + 20;
        addLogic(ai, &resetAfterFrameLogic);
        addCleanUpLogic(ai);
    }
    else
    {
        fireRecovery(ai);
    }
}


