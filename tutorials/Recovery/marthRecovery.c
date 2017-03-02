#include <mml/game_state.h>
#include <mml/AI.h>
#include <mml/moves.h>
#include <mml/random.h>

#include "marthRecovery.h"
#include "recovery.h"
#include "cpuLogic.h"

#define SIDE_B_HEIGHT      0.f
#define SIDE_B_DIST       20.f
#define DJ_HEIGHT        -60.f

static RawInput raw_marthSideB[2] = 
{
    {OVERWRITE, 0, NO_FLAGS},
    {OVERWRITE, 15, NO_FLAGS}
};

static Move marthSideB = {.inputs = raw_marthSideB, .size = 2};

void marthRecovery(AI* ai)
{
    float dist = rInfo.abs_x - rInfo.ledge.x;
    bool goHigh = chance(0.01f + (1 - rInfo.jumps) * 0.99f);
    float upBheight = DJ_HEIGHT + (goHigh ? 50.f : 0.f);
    float upBdist = 20.f - (goHigh ? 10.f : 0.f);

    if (rInfo.coords.y > SIDE_B_HEIGHT && dist > SIDE_B_DIST)
    {
        raw_marthSideB[0].controller =
            FULL_STICK | STICK_ANGLE(rInfo.stageDir);
        raw_marthSideB[1].controller = 
            B_BUTTON | FULL_STICK | STICK_ANGLE(rInfo.stageDir);
                    
        addMove(ai, &marthSideB);

        resetAfterFrameLogic.condition.arg1.u = CURRENT_FRAME + 40;
        addLogic(ai, &resetAfterFrameLogic);
    }
    else if (rInfo.jumps > 0 && rInfo.coords.y < DJ_HEIGHT)
    {
        dist = fmax(dist, -10.f);
        dist = fmin(dist,  50.f);

        float dir = (dist + 10.f) * 180.f / 60.f;
        dir = rInfo.leftSide ? 180.f - dir : dir;

        SET_DJ_DIR(dir);
        addMove(ai, &_mv_doubleJump);
    }
    else if (rInfo.coords.y < upBheight
        && (rInfo.jumps < 1 || (dist <= upBdist && dist > 5.f)))
    {
        float dir = dist > upBdist ? rInfo.stageDir : 90.f;
        SET_UP_B_DIR(dir);
        addMove(ai, &_mv_upB);
        addCleanUpLogic(ai);
    }
}
