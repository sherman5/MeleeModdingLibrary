#include <mml/AI.h>
#include <mml/system.h>
#include <mml/gctypes.h>

#include "cpuLogic.h"

static char heap[15000];
static bool init_run = false;

void init()
{
    initHeap(heap, heap + sizeof(heap));
    init_run = true;
}

void loadDefaultLogic()
{
    addLogic(&cpuPlayer, &hitTechLogic);
    addLogic(&cpuPlayer, &getOffGroundLogic);
}

void _main()
{
    if (!init_run) { init(); }

    if (cpuPlayer.active && needLogic(&cpuPlayer)) { loadDefaultLogic(); }

    updateAI(&cpuPlayer);
}




















