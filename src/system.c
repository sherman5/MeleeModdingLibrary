#include "system.h"
#include "native_functions.h"
#include "string.h"
#include "math.h"
#include "gctypes.h"

/*************************** native functions **************************/
u32 (*OSCreateHeap)(void*, void*) = OS_CREATE_HEAP_FPTR;
void* (*OSAllocFromHeap)(u32, size_t) = OS_ALLOC_FROM_HEAP_FPTR;
void (*OSFreeToHeap)(u32, void*) = OS_FREE_TO_HEAP_FPTR;
/*************************************************************************/

#define ARENA_HI_ADDRESS 0x80000034

static u32 heapHandle;
static bool init = 0;
static size_t heapSize = 0;

void initHeap(void* lo, void* hi)
{
    heapSize = (u32) hi - (u32) lo;
    heapHandle = OSCreateHeap(lo, hi);
    init = true;
}

void limitGameMemory(void* limit)
{
    *((void**) ARENA_HI_ADDRESS) = limit;
}

void* malloc(size_t size)
{
    if (!init) {return NULL;}
    return OSAllocFromHeap(heapHandle, size);
}

void* calloc(size_t num, size_t size)
{
    void* ptr = malloc(num * size);
    memset(ptr, 0, num * size);
    return ptr;
}

void* realloc(void* ptr, size_t new_size)
{
    if (!ptr) {return malloc(new_size);}

    void* new_ptr = malloc(new_size);
    if (!new_ptr) {return new_ptr;}

    memcpy(new_ptr, ptr, new_size);
    free(ptr);
    return new_ptr;
}

void free(void* ptr)
{
    OSFreeToHeap(heapHandle, ptr);
}

size_t getHeapSize()
{
    return heapSize;
}

