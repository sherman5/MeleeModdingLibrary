#include "statecheck.h"
#include "math.h"
#include "random.h"
#include "gamestate.h"

bool offstage(uint8_t player)
{
    return fabs(gameState.playerData[player]->coordinates.x)
        > gameState.stage.ledge;        
}

bool chance(float prob)
{
    return rand() < prob;
}
