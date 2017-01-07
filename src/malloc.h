#ifndef MALLOC_H
#define MALLOC_H

#include <stdint.h>
#include <stddef.h>

//#define NULL 0

struct block {

    size_t size;
    int8_t free;

    struct block* next;

};

typedef struct heap {

    struct block* blockLL;
    size_t size;

} Heap;

void init_heap(Heap*, void*, size_t);

void* malloc(Heap*, size_t);

void free(void*);

void defragment(Heap*);

#endif
