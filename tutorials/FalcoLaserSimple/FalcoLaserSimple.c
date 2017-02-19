#include <mml/AI.h>
#include <mml/system.h>
#include <mml/statecheck.h>
#include <mml/inputs.h>
#include <mml/gctypes.h>

static char heap[10000];
static bool initialized = false;

AI player2 = {.port = 2, .active = false, .characters = FALCO};

void _init()
{
    initHeap(heap, heap + sizeof(heap));
    initialized = true;
}

void loadDefaultLogic()
{
    addLogic(&player2,
        (Function) {&chance, .arg1.f = 0.01, 0},
        (Function) {&addMove, .arg1.p = &player2, .arg2.p = &shNeutralB});
}

void _main()
{
    if (!initialized) { _init();}

    if (player2.active && needLogic(&player2)) { loadDefaultLogic();}

    updateAI(&player2);
}




















