#include "state_check.h"
#include "math.h"
#include "random.h"
#include "game_state.h"
#include "gctypes.h"
#include "logic.h"

bool offstage(FunctionArg player)
{
    return fabs(gameState.playerData[player.u]->coordinates.x)
        > gameState.stage.ledge;        
}

bool chance(FunctionArg prob)
{
    //return rand() < prob.f;
//    return prob.f < 0.01;    
//    return rand() < 1.0f / 180.0f;
    return true;
}
