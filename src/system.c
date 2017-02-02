#include <stdbool.h>
#include "system.h"
#include "melee.h"
#include "string.h"

/*************************** built in functions **************************/
int (*OSCreateHeap)(void*, void*) = OS_CREATE_HEAP_FPTR;
void* (*OSAllocFromHeap)(int, size_t) = OS_ALLOC_FROM_HEAP_FPTR;
void (*OSFreeToHeap)(int, void*) = OS_FREE_TO_HEAP_FPTR;
void* (*OSGetArenaHi)() = OS_GET_ARENA_HI_FPTR;
void* (*OSGetArenaLo)() = OS_GET_ARENA_LO_FPTR;
void (*OSDumpHeap)(int) = OS_DUMP_HEAP_FPTR;
/*
uint32_t (*OSRoundUp32B)(uint32_t) = OS_ROUND_UP_32B_FPTR;
uint32_t (*OSRoundDown32B)(uint32_t) = OS_ROUND_DOWN_32B_FPTR;
void* (*OSInitAlloc)(void*, void*, int) = OS_INIT_ALLOC_FPTR;
void (*OSSetArenaLo)(void*) = OS_SET_ARENA_LO_FPTR;
void (*OSSetCurrentHeap)(int) = OS_SET_CURRENT_HEAP_FPTR;
void (*OSAddToHeap)(int, void*, void*) = OS_ADD_TO_HEAP_FPTR;
*/
/*************************************************************************/

static int heap_handle;
bool init = false;

void DumpHeap(void)
{
    OSDumpHeap(heap_handle);
}

void initHeap (void)
{
    void* arenaLo;
    void* arenaHi;

//    arenaLo = OSGetArenaLo();
//    arenaHi = OSGetArenaHi();
    arenaLo = (void*) 0x80001800;
    arenaHi = (void*) 0x80002ff0;

    heap_handle = OSCreateHeap(arenaLo, arenaHi);
}

void* malloc(size_t size)
{
    if (!init) {initHeap(); init = true;}
    return OSAllocFromHeap(heap_handle, size);
}

void* calloc(size_t num, size_t size)
{
    void* ptr = malloc(num * size);
    memset(ptr, 0, num * size);
    return ptr;
}

void* realloc(void* ptr, size_t old_size, size_t new_size)
{
    if (!ptr) {return malloc(new_size);}

    void* new_ptr = malloc(new_size);
    if (!new_ptr) {return new_ptr;}

    memcpy(new_ptr, ptr, old_size);
    free(ptr);
    return new_ptr;
}

void free(void* ptr)
{
    OSFreeToHeap(heap_handle, ptr);
}


