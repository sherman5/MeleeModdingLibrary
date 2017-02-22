#include "state_check.h"
#include "math.h"
#include "random.h"
#include "game_state.h"
#include "gctypes.h"
#include "logic.h"

static float* fptr = (float*) 0x80001800;

bool offstage(FunctionArg player)
{
    return fabs(gameState.playerData[player.u]->coordinates.x)
        > gameState.stage.ledge;        
}

bool chance(FunctionArg prob)
{
/*    if (fptr < (float*) 0x80002400)
    {
        *fptr = rand();
        return *(fptr++) < prob.f;
    }
    else
    {*/
        return rand() < prob.f;
    //}
}
