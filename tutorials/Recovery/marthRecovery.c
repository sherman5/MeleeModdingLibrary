#include <mml/game_state.h>
#include <mml/AI.h>
#include <mml/moves.h>
#include <mml/random.h>
#include <mml/state_check.h>

#include "marthRecovery.h"
#include "recovery.h"
#include "cpuLogic.h"

#define SIDE_B_HEIGHT      0.f
#define SIDE_B_DIST       70.f
#define SWEET_SPOT_PROB  0.55f

static RawInput raw_marthSideB[2] = 
{
    {OVERWRITE, 0, NO_FLAGS},
    {OVERWRITE, 15, NO_FLAGS}
};
static Move mv_marthSideB = {.inputs = raw_marthSideB, .size = 2};

static void marthSideB(AI* ai)
{
    raw_marthSideB[0].controller =
        FULL_STICK | STICK_ANGLE(rInfo.stageDir);
    raw_marthSideB[1].controller = 
        B_BUTTON | FULL_STICK | STICK_ANGLE(rInfo.stageDir);
                
    addMove(ai, &mv_marthSideB);

    resetAfterFrameLogic.condition.arg1.u = CURRENT_FRAME + 40;
    addLogic(ai, &resetAfterFrameLogic);
    addCleanUpLogic(ai);
}

static float jumpDist = 0.f;
static float upBdist = 0.f;
static float upBheight = 0.f;

void marthDoubleJump(AI* ai)
{
    if (rInfo.jumps > 0) {doubleJump(ai, jumpDist);}
    marthUpBLogic.condition.arg2.f = upBheight;
    addLogic(ai, &marthUpBLogic);
    addCleanUpLogic(ai);
}

void marthUpB(AI* ai)
{
    setGlobalVariables(ai);
    float dir = rInfo.dist > upBdist + 25.f ? rInfo.stageDir : 90.f;
    SET_UP_B_DIR(dir);
    addMove(ai, &_mv_upB);
    addCleanUpLogic(ai);
}

void marthRecovery(AI* ai)
{
    if (rInfo.coords.y > SIDE_B_HEIGHT && rInfo.dist > SIDE_B_DIST)
    {
        marthSideB(ai);
    }
    else if (chance(SWEET_SPOT_PROB) || rInfo.dist > 50.f)
    {
        jumpDist = 25.f;
        upBdist = 0.f;
        upBheight = -63.f;
        marthDoubleJumpLogic.condition.arg2.f = -60.f;
        addLogic(ai, &marthDoubleJumpLogic);
        addCleanUpLogic(ai);
    }
    else
    {
        jumpDist = 13.f;
        upBdist = -20.f;
        upBheight = -45.f;

        if (rInfo.jumps > 0)
        {
            marthDoubleJumpLogic.condition.arg2.f = -65.f;
            marthUpBLogic.condition.function = &aboveHeight;
        }
        else
        {
            marthDoubleJumpLogic.condition.arg2.f = -40.f;
            marthUpBLogic.condition.function = &belowHeight;            
        }

        addLogic(ai, &marthDoubleJumpLogic);
        addCleanUpLogic(ai);
    }
}

