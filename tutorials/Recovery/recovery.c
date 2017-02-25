#include <mml/print.h>
#include <mml/state_check.h>
#include <mml/AI.h>
#include <mml/inputs.h>
#include <mml/action_state.h>
#include <mml/game_state.h>
#include <mml/math.h>
#include <mml/melee_info.h>

#include "recovery.h"
#include "cpuLogic.h"


//attempt to recover with DJ, airdodge
static bool closeRecovery(AI* ai)
{

} 

static void spacieRecovery(AI* ai)
{

}

static void marthRecovery(AI* ai)
{

}

static void falconRecovery(AI* ai)
{

}

void recovery(AI* ai)
{
    if (!closeRecovery(ai))
    {
        switch (CHAR_SELECT(ai->port))
        {
            case: FALCO_ID
            case: FOX_ID
                spacieRecovery(ai);
                break;
            case: MARTH_ID
                marthRecovery(ai);
                break;
            case: FALCON_ID
                falconRecovery(ai);
                break;
        }
    }
}


