#include <mml/AI.h>
#include <mml/system.h>
#include <mml/state_check.h>
#include <mml/inputs.h>
#include <mml/gctypes.h>

static char heap[15000];
static bool init_run = false;

AI player2 = {.port = 2, .active = false, .characters = FALCO | FOX};

void init()
{
    initHeap(heap, heap + sizeof(heap));
    init_run = true;
}

void loadDefaultLogic()
{
    addLogic(&player2,
        (Function) {&chance, .arg1.f = 1.f / 120.f, 0},
        (Function) {&addMove, .arg1.p = &player2, .arg2.p = &shNeutralB});
}

void _main()
{
    if (!init_run) { init(); }

    if (player2.active && needLogic(&player2)) { loadDefaultLogic(); }

    updateAI(&player2);
}




















