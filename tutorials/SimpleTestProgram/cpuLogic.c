#include <mml/AI.h>
#include <mml/logic.h>
#include <mml/state_check.h>
#include <mml/action_state.h>
#include <mml/moves.h>

#include "cpuLogic.h"

AI cpuPlayer = INIT_AI(2, FALCO | FOX | MARTH | FALCON);

Logic respawnLogic = 
{
    {&actionStateEq, .arg1.u = 2, .arg2.u = _AS_RebirthWait},
    {&addMove, .arg1.p = &cpuPlayer, .arg2.p = &_mv_shortHop}
};


