#include <unit_test.h>
#include <system.h>
#include <math.h>

UNIT_TEST;

static int init = 0;
static char heap[5000];

static int tests_run = 0;

void _boot(void)
{
    limitGameMemory((void*) 0x81780000);
}

void _init(void)
{
    initHeap(heap, heap + sizeof(heap));
}

void _main(void)
{
    if (!init) { _init(); init = 1;}

    if (!tests_run)
    {
        MML_ASSERT(getHeapSize() == sizeof(heap));

        tests_run = 1;
        END_TEST;
    }
}


