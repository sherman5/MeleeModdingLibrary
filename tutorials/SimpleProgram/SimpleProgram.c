#include <mml/ai.h>
#include <mml/system.h>
#include <mml/gctypes.h>
#include <mml/logic.h>
#include <mml/action_state.h>
#include <mml/state_check.h>
#include <mml/moves.h>

static char heap[2000];
static bool init_run = false;

static AI cpuPlayer = INIT_AI(2, FALCO | FOX | MARTH | FALCON);

static Logic respawnLogic = 
{
    {&actionStateEq, .arg1.u = 2, .arg2.u = _AS_RebirthWait},
    {&addMove, .arg1.p = &cpuPlayer, .arg2.p = &_mv_shortHop}
};

static void init()
{
    initHeap(heap, heap + sizeof(heap));
    init_run = true;
}

static void loadDefaultLogic()
{
    addLogic(&cpuPlayer, &respawnLogic);
}

void _main()
{
    if (!init_run) { init(); }

    if (needLogic(&cpuPlayer)) { loadDefaultLogic(); }

    updateAI(&cpuPlayer);
}

