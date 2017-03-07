#include <mml/ai.h>
#include <mml/system.h>
#include <mml/gctypes.h>

#include "cpuLogic.h"

static char heap[2000];
static bool init_run = false;

static void init()
{
    initHeap(heap, heap + sizeof(heap));
    init_run = true;
}

static void loadDefaultLogic()
{
    addLogic(&cpuPlayer, &respawnLogic);
    addLogic(&cpuPlayer, &hitTechLogic);
    addLogic(&cpuPlayer, &getOffGroundLogic);
    addLogic(&cpuPlayer, &hitDiLogic);
    addLogic(&cpuPlayer, &throwDiLogic);
    addLogic(&cpuPlayer, &recoveryLogic);
    addLogic(&cpuPlayer, &onLedgeLogic);
}

void _main()
{
    if (!init_run) { init(); }

    if (needLogic(&cpuPlayer)) { loadDefaultLogic(); }

    updateAI(&cpuPlayer);
}




















