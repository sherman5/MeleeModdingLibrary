#include <unit_test.h>
#include <system.h>
#include <inputs.h>

UNIT_TEST;

static bool init = false;
static char heap[21000];

void _init(void)
{
    initHeap(heap, heap + sizeof(heap));
}

void _main(void)
{
    if (!init) { _init(); init = true;}

    void* p1 = &shNeutralB;
    void* p2 = &shortHop;

    END_TEST;
}


