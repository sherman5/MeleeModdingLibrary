#include "system.h"
#include "native_functions.h"
#include "string.h"
#include "math.h"
#include "bool.h"

/*************************** native functions **************************/
int (*OSCreateHeap)(void*, void*) = OS_CREATE_HEAP_FPTR;
void* (*OSAllocFromHeap)(int, size_t) = OS_ALLOC_FROM_HEAP_FPTR;
void (*OSFreeToHeap)(int, void*) = OS_FREE_TO_HEAP_FPTR;
/*************************************************************************/

#define ARENA_HI_ADDRESS 0x80000034

static int heap_handle;
static bool init = 0;
static uint32_t heapSize = 0;

void initHeap(void* lo, void* hi)
{
    heapSize = (unsigned) hi - (unsigned) lo;
    heap_handle = OSCreateHeap(lo, hi);
    init = true;
}

void limitGameMemory(void* limit)
{
    *((void**) ARENA_HI_ADDRESS) = limit;
}

void* malloc(size_t size)
{
    if (!init) {return NULL;}
    return OSAllocFromHeap(heap_handle, size);
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
    OSFreeToHeap(heap_handle, ptr);
}

size_t getHeapSize()
{
    return heapSize;
}

