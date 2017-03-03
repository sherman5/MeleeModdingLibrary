#include <mml/game_state.h>
#include <mml/AI.h>
#include <mml/moves.h>
#include <mml/random.h>

#include "marthRecovery.h"
#include "recovery.h"
#include "cpuLogic.h"

#define SIDE_B_HEIGHT      0.f
#define SIDE_B_DIST       20.f
#define LOWER_LIMIT      -60.f

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
}

static void marthUpB(AI* ai, float target)
{
    float dir = rInfo.dist > target + 20.f ? rInfo.stageDir : 90.f;
    SET_UP_B_DIR(dir);
    addMove(ai, &_mv_upB);
    addCleanUpLogic(ai);
}

static bool commitToStage = false;

void marthRecovery(AI* ai)
{
    bool landOnStage = chance(0.1f);

    if (rInfo.coords.y > SIDE_B_HEIGHT && rInfo.dist > SIDE_B_DIST)
    {
        marthSideB(ai);
    }
    else if (landOnStage && rInfo.jumps > 0 && rInfo.coords.y < LOWER_LIMIT)
    {
        commitToStage = true;
        doubleJump(ai, 13.f);
    }
    else if ((commitToStage || landOnStage) && rInfo.coords.y < -50.f
    && rInfo.coords.y > -55.f && rInfo.dist < 20.f && rInfo.dist > 0.f)
    {
        commitToStage = false;
        marthUpB(ai, -10.f);
    }
    else if (rInfo.jumps > 0 && rInfo.coords.y < LOWER_LIMIT)
    {
        doubleJump(ai, 20.f);
    }
    else if (rInfo.coords.y < LOWER_LIMIT)
    {
        marthUpB(ai, 0.f);
    }
}
