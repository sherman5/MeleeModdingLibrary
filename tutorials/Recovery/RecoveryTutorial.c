#include <mml/AI.h>
#include <mml/system.h>
#include <mml/gctypes.h>

#include "cpuLogic.h"

static char heap[7000];
static bool init_run = false;

static void init()
{
    initHeap(heap, heap + sizeof(heap));
    init_run = true;
}

static void loadDefaultLogic()
{
    addLogic(&cpuPlayer, &hitTechLogic);
    addLogic(&cpuPlayer, &getOffGroundLogic);
    addLogic(&cpuPlayer, &hitDiLogic);
    addLogic(&cpuPlayer, &throwDiLogic);
    addLogic(&cpuPlayer, &recoveryStartLogic);
}

void _main()
{
    if (!init_run) { init(); }

    if (cpuPlayer.active && needLogic(&cpuPlayer)) { loadDefaultLogic(); }

    updateAI(&cpuPlayer);
}




















