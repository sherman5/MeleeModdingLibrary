#include "state_check.h"
#include "math.h"
#include "random.h"
#include "game_state.h"
#include "action_state.h"
#include "gctypes.h"
#include "logic.h"

#define TECH_HEIGHT 3.f

#define ACTION_STATE(p)     (_gameState.playerData[p]->actionState)
#define FACING(p)           (_gameState.playerData[p]->facingDirection)
#define X_COORD(p)          (_gameState.playerData[p]->coordinates.x)
#define Y_COORD(p)          (_gameState.playerData[p]->coordinates.y)
#define DELTA_X(p)          (_gameState.playerData[p]->deltaCoordinates.x)
#define DELTA_Y(p)          (_gameState.playerData[p]->deltaCoordinates.y)
#define IN_AIR(p)           (_gameState.playerData[p]->inAir)
#define PERCENT(p)          (_gameState.playerData[p]->percent)
#define KNOCKBACK_ANGLE(p)  (_gameState.playerData[p]->knockbackAngle)
#define HITLAG(p)           (_gameState.playerData[p]->hitlag)
#define JUMPS_USED(p)       (_gameState.playerData[p]->jumpsUsed)
#define SHIELD_SIZE(p)      (_gameState.playerData[p]->shieldSize)
#define HITSTUN(p)          (_gameState.playerData[p]->hitstun)
#define BREAKOUT(p)         (_gameState.playerData[p]->breakoutCountdown)
#define STAGE               _gameState.stage

bool offstage(FunctionArg port)
{
    return fabs(X_COORD(port.u)) > STAGE.ledge;        
}

bool inHitstun(FunctionArg port)
{
    return (u32) HITSTUN(port.u) > 0;
}

bool pastFrame(FunctionArg frame)
{
    return CURRENT_FRAME >= frame.u;
}

bool inHitlag(FunctionArg port)
{
    return (u32) HITLAG(port.u) > 0;
}

bool hitlagFrames(FunctionArg port, FunctionArg frame)
{
    return (u32) HITLAG(port.u) == frame.u;
}

bool belowHeight(FunctionArg port, FunctionArg height)
{
    return Y_COORD(port.u) < height.f;
}

bool inAir(FunctionArg port)
{
    return IN_AIR(port.u);
}

bool onGround(FunctionArg port)
{
    return !IN_AIR(port.u);
}

bool chance(FunctionArg prob)
{
    return rand() < prob.f;
}

bool actionStateEq(FunctionArg port, FunctionArg state)
{
    return ACTION_STATE(port.u) == state.u;
}

bool actionStateGeq(FunctionArg port, FunctionArg state)
{
    return ACTION_STATE(port.u) >= state.u;
}

bool actionStateLeq(FunctionArg port, FunctionArg state)
{
    return ACTION_STATE(port.u) <= state.u;
}

bool fallenDown(FunctionArg port)
{
    return ACTION_STATE(port.u) == _AS_DownWaitU
        || ACTION_STATE(port.u) == _AS_DownWaitD;
}

bool nearSurface(FunctionArg port)
{
    float x = fabs(X_COORD(port.u));
    float y = Y_COORD(port.u);

    bool xSidePlat = x > STAGE.side.left && x < STAGE.side.right;

    bool ySidePlat = y > STAGE.side.height
        && y < STAGE.side.height + TECH_HEIGHT;

    bool topPlat = x < STAGE.top.right
        && y > STAGE.top.height && y < STAGE.top.height + TECH_HEIGHT;

    if (STAGE.side.height < 1.f) {xSidePlat = false;}
    if (STAGE.top.height  < 1.f) {topPlat = false;}

    bool stage = !offstage(port) && y < TECH_HEIGHT;

    return (xSidePlat && ySidePlat) || topPlat || stage;
}

bool techSituation(FunctionArg port)
{
    return DELTA_Y(port.u) < 0.f
        && nearSurface(port)
        && (ACTION_STATE(port.u) == _AS_DamageFall
            || (ACTION_STATE(port.u) >= _AS_DamageFlyHi
                && ACTION_STATE(port.u) <= _AS_DamageFlyRoll)
           );
}

bool recoverySituation(FunctionArg port)
{
    return offstage(port) && !inHitstun(port)
        && !actionStateEq(port, _AS_CliffWait);
}

bool breakoutFrame(FunctionArg port, FunctionArg frames)
{
    return (u32) BREAKOUT(port.u) == frames.u;
}


