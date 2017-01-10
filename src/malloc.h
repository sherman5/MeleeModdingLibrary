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
 * Allocates a block of @p size bytes of memory, returning a pointer
 * to the beginning of the block. The content of the newly allocated
 * block of memory is not initialized. If @c malloc fails to allocate
 * the memory, a @c NULL pointer is returned.
 *
 * @param size Size of memory block in bytes.
 * @return 
 */
void* malloc(size_t size);

/**
 * @brief Standard call to @c free.
 */
void free(void* ptr);

#endif