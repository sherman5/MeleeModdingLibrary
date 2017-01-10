#ifndef MALLOC_H
#define MALLOC_H

#ifndef HEAP_ADDRESS

    #define HEAP_ADDRESS 0x80001800

#endif

#ifndef HEAP_SIZE

    #define HEAP_SIZE 0x17f0

#endif

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

bool initialized = 0;

typedef struct block {

    size_t size;
    bool free;

    struct block* next;

} Block;

static void initMalloc();

static void defragment();

void* malloc(size_t);

void free(void*);

#endif