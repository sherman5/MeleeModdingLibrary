#include <stdbool.h>
#include "system.h"
#include "melee.h"
#include "string.h"
#include "math.h"

/*************************** built in functions **************************/
int (*OSCreateHeap)(void*, void*) = OS_CREATE_HEAP_FPTR;
void* (*OSAllocFromHeap)(int, size_t) = OS_ALLOC_FROM_HEAP_FPTR;
void (*OSFreeToHeap)(int, void*) = OS_FREE_TO_HEAP_FPTR;
/*************************************************************************/

static int heap_handle;
static int init = 0;
static uint32_t heapSize = 0;

void initHeap(void* lo, void* hi)
{
    heapSize = (uint32_t) hi - (unsigned) lo;
    heap_handle = OSCreateHeap(lo, hi);
    init = 1;
}

// 0x81710000 seems safe
void limitGameMemory(uint32_t limit)
{
    uint32_t FST_location = *((uint32_t*) 0x80000038);
    uint32_t FST_size = *((uint32_t*) 0x8000003c);
    uint32_t new_FST_location = limit - FST_size;

    *((uint32_t*) 0x80000034) = (uint32_t) new_FST_location;
    *((uint32_t*) 0x80000038) = (uint32_t) new_FST_location;

    memcpy((void*) new_FST_location, (void*) FST_location, FST_size);
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

// TODO: does this fail if new_size is used for copying?
// could remove old_size requirement if not
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

