#include <mml/state_check.h>
#include <mml/AI.h>
#include <mml/inputs.h>
#include <mml/action_state.h>
#include <mml/game_state.h>

#include "teching.h"
#include "DI.h"

#define SAKURAI_ANGLE 0x0169

static u32 knockback_test = 0;

static float getKnockBackAngle(u32 port)
{
    u32 rawAngle = _gameState.playerData[port]->knockbackAngle;
    float direction = _gameState.playerData[port]->damageDirection;

    if (rawAngle == SAKURAI_ANGLE)
    {
        return 45.f - (1.f + direction) * 90.f;
    }
    else
    {
        return (float) rawAngle - (1.f + direction) * 90.f;
    }
}

void inputDI(AI* player)
{
    float knockback = getKnockBackAngle(player->port);
    knockback_test = knockback;
}

