#include "statecheck.h"
#include "math.h"
#include "random.h"
#include "gamestate.h"
#include "gctypes.h"
#include "logic.h"

bool offstage(u8 player)
{
    return fabs(gameState.playerData[player]->coordinates.x)
        > gameState.stage.ledge;        
}

bool chance(FunctionArg prob)
{
    return randUint32() < prob.u;
}
