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

/** records once the heap has been initialized */
static bool initialized = false;

/**
 * @brief A single block of memory 
 *
 */
typedef struct block {

    size_t size;
    bool free;

    struct block* next;

} Block;

/**
 * @brief Initialize the heap
 */
static void initMalloc();

/**
 * @brief Defragment the heap
 */
static void defragment();

/**
 * @brief Standard call to @c malloc.
 */
void* malloc(size_t);

/**
 * @brief Standard call to @c free.
 */
void free(void*);

#endif