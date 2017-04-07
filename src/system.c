#include "system.h"
#include "native_functions.h"
#include "string.h"
#include "math.h"
#include "gctypes.h"

#define ARENA_HI_ADDRESS 0x80000034

typedef u32 handle_t;

static handle_t heapHandle;
static bool init = false;
static size_t heapSize = 0;

/*************************** native functions **************************/
handle_t (*OSCreateHeap)(void*, void*)     = OS_CREATE_HEAP_FPTR;
void* (*OSAllocFromHeap)(handle_t, size_t) = OS_ALLOC_FROM_HEAP_FPTR;
void (*OSFreeToHeap)(handle_t, void*)      = OS_FREE_TO_HEAP_FPTR;
/*************************************************************************/

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

//TODO: 8037f1e4 - malloc
void* malloc(size_t size)
{
    if (!init) {return NULL;}
    return OSAllocFromHeap(heapHandle, size);
}

void* calloc(size_t num, size_t size)
{
    void* ptr = malloc(num * size);
    if (!ptr) {return ptr;}
    memset(ptr, 0, num * size);
    return ptr;
}

void* realloc(void* ptr, size_t size)
{
    if (!ptr) {return malloc(size);}

    void* new_ptr = malloc(size);
    if (!new_ptr) {return new_ptr;}

    memcpy(new_ptr, ptr, size);
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

