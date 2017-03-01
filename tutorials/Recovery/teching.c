#include <mml/state_check.h>
#include <mml/AI.h>
#include <mml/moves.h>
#include <mml/action_state.h>

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

void postTechOption(AI* player)
{
    if (chance(GET_UP_ATTACK_PROB))
    {
        addMove(player, &_mv_jab);
    }
    else
    {
        addMove(player, &_mv_spotDodge);
    }
}

void hitTech(AI* player)
{
    addLogic(player, &getOffGroundLogic);
    if (chance(HIT_TECH_PROB))
    {
        SET_TECH_DIR(getRandomTechDirection()); 
        addMove(player, &_mv_tech);   

        addLogic(player, &actAfterTechLogic);
        addLogic(player, &hitDuringMoveLogic);  
    }
    else
    {
        addLogic(player, &getOffGroundLogic);
    }
}

void getUpFromGround(AI* player)
{
    if (chance(GET_UP_ATTACK_PROB))
    {
        addMove(player, &_mv_getUpAttack);
    }
    else
    {
        hitTech(player);
    }
}




















