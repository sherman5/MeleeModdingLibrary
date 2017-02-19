#include "system.h"
#include "native_functions.h"
#include "string.h"
#include "math.h"
#include "gctypes.h"

typedef u32 handle_t;

/*************************** native functions **************************/
handle_t (*OSCreateHeap)(void*, void*)     = OS_CREATE_HEAP_FPTR;
void* (*OSAllocFromHeap)(handle_t, size_t) = OS_ALLOC_FROM_HEAP_FPTR;
void (*OSFreeToHeap)(handle_t, void*)      = OS_FREE_TO_HEAP_FPTR;
/*************************************************************************/

#define ARENA_HI_ADDRESS 0x80000034

static handle_t heapHandle;
static bool init = false;
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

