#include <unit_tests.h>
#include <system.h>
#include <math.h>
#include <stdbool.h>

static initialized = false;
static char test_heap[1000];

void init(void)
{
    initHeap(&test_heap, &test_heap + 1000);

    testHeap();

    initHeap(0x80001800, 0x80002700);

    testHeap();

    limitGameMemory(0x81710000);
    initHeap(0x81710000, HIGH_MEM_ADDR);

    testHeap();
}

void testHeap(void)
{
    int* int_ra = malloc(10 * sizeof(int));
    int_ra[9] = 7;
    MML_ASSERT("malloc broken", int_ra[9] == 7);

}

void testSystem(void)
{
    if (!initialized) {init(); initialized = true;}
}

