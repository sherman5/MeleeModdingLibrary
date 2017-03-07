#include <mml/state_check.h>
#include <mml/ai.h>
#include <mml/moves.h>
#include <mml/action_state.h>
#include <mml/random.h>

#include "teching.h"
#include "cpuLogic.h"

#define HIT_TECH_PROB 0.8f
#define TECH_ROLL_PROB 0.5f
#define GET_UP_ATTACK_PROB 0.25f

static float getRandomTechDirection()
{
    if (chance(TECH_ROLL_PROB))
    {
        return chance(0.5f) ? 0.f : 180.f;
    }
    else
    {
        return 90.f;
    }
}

void postTechOption(AI* ai)
{
    if (chance(GET_UP_ATTACK_PROB))
    {
        addMove(ai, &_mv_jab);
    }
    else
    {
        addMove(ai, &_mv_spotDodge);
    }
}

void hitTech(AI* ai)
{
    addLogic(ai, &getOffGroundLogic);
    addLogic(ai, &resetOnHitLogic);

    if (chance(HIT_TECH_PROB))
    {
        SET_TECH_DIR(getRandomTechDirection()); 
        addMove(ai, &_mv_tech);   
        addLogic(ai, &actAfterTechLogic);
    }
}

void getUpFromGround(AI* ai)
{
    if (chance(GET_UP_ATTACK_PROB))
    {
        addMove(ai, &_mv_getUpAttack);
    }
    else
    {
        hitTech(ai);
    }
}




















