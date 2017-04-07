#include <unit_test.h>
#include <system.h>
#include <gctypes.h>
#include <state_check.h>
#include <game_state.h>
#include <moves.h>
#include <ai.h>

UNIT_TEST;

static bool init = false;
static char heap[13000];

static AI cpuPlayer = INIT_AI(2, FALCO | FOX | MARTH | FALCON);

static Logic moveLogic = 
{
    {&pastFrame},
    {&addMove, .arg1.p = &cpuPlayer, .arg2.p = &_mv_dash}
};

void _init(void)
{
    initHeap(heap, heap + sizeof(heap));
    SET_DASH_DIR(180.f);
}

void _main(void)
{
    if (!init) {_init(); init = true;}
    
    if (needLogic(&cpuPlayer))
    {
        moveLogic.condition.arg1.u = CURRENT_FRAME + 120;
        addLogic(&cpuPlayer, &moveLogic);
    }
    
    updateAI(&cpuPlayer);
}


