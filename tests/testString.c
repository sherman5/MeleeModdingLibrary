#include <math.h>
#include <string.h>
#include <system.h>
#include <print.h>
#include <gctypes.h>
#include <error.h>

static char heap[15000];
static bool initRun = false, testRun = false;
static char str[100] = {0};

static void init()
{
    initHeap(heap, heap + sizeof(heap));
}

static void test()
{
    sprintf(str, "test of sprintf, int: %d and float: %f", 5, 4.506);
    print(str);
}

void _main()
{
    if (!initRun) { init(); initRun = true; }
    if (!testRun) { test(); testRun = true; }
}

