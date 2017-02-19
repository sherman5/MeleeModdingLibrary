/**
 * @file system.h
 * @brief System level functions.
 *
 */

#ifndef SYSTEM_H
#define SYSTEM_H

#include "gctypes.h"

/** @cond */

extern u32 (*OSCreateHeap)(void*, void*);
extern void* (*OSAllocFromHeap)(u32, size_t);
extern void (*OSFreeToHeap)(u32, void*);

#if 0
/** @endcond */

/** @cond */
#endif
/** @endcond */

/**
 * Initialize heap
 *
 * Initializes the heap that is used for all calls to @c malloc,
 * @c calloc, and @c realloc. 
 *
 * @param lo - lower address of the heap
 * @param hi - upper address of the heap
 *
 * @return none 
 */
void initHeap(void* lo, void* hi);

/**
 * Get the size of the heap
 *
 * Returns the size (in bytes) of the heap that was allocated 
 * with @c initHeap.
 *
 * @return size of the heap in bytes.
 */
size_t getHeapSize();

/**
 * @brief limit size of game heap
 *
 * Restricts the size of the heap that the game can use. The game will
 * not touch any memory between @p limit and 0x817f8ab0. This is not
 * guaranteed to be stable. 
 *
 * @param limit - address that marks the top of the game heap.
 *
 * @return none
 *
 * @note 0x81780000 seems to be reasonably stable - recommended that
 *      values less than this are not used
 */
void limitGameMemory(void* limit);

/**
 * @brief Allocate memory block
 *
 * Allocates a block of @p size bytes of memory, returning a pointer
 * to the beginning of the block. The content of the newly allocated
 * block of memory is not initialized. If @c malloc fails to allocate
 * the memory, a @c NULL pointer is returned.
 *
 * @param size - Size of memory block in bytes.
 *
 * @return On success, a pointer to the memory block allocated by
 * the function. If the function failed to allocate the requested
 * block of memory, a null pointer is returned.
 *
 * @see http://www.cplusplus.com/reference/cstdlib/malloc/
 */
void* malloc(size_t size);

/**
 * @brief Allocate and zero-initialize array
 *
 * Allocates a block of memory for an array of @p num elements, each of
 * them @p size bytes long, and initializes all its bits to zero.
 *
 * The effective result is the allocation of a zero-initialized memory
 * block of @c (num*size) bytes.
 *
 * @param num - Number of elements to allocate
 * @param size - Size of each element
 *
 * @return On success, a pointer to the memory block allocated by
 * the function. If the function failed to allocate the requested
 * block of memory, a null pointer is returned.
 *
 * @see http://www.cplusplus.com/reference/cstdlib/calloc/
 */
void* calloc(size_t num, size_t size);

/**
 * @brief Reallocate memory block
 *
 * Changes the size of the memory block pointed to by @p ptr. The function
 * may move the memory block to a new location (whose address is returned
 * by the function). The content of the memory block is preserved up to
 * the lesser of the new and old sizes, even if the block is moved to a
 * new location. 
 *
 * @param ptr - Pointer to a memory block previously allocated with
 * @c malloc or @c realloc. Alternatively, this can be a null pointer,
 * in which case a new block is allocated (as if @c malloc was called).
 * @param size - New size for the memory block, in bytes.
 *
 * @return A pointer to the reallocated memory block, which may be
 * either the same as @p ptr or a new location. A null-pointer indicates
 * either that @p size was zero (an thus ptr was deallocated), or that the
 * function did not allocate storage (and thus the block pointed by @p ptr
 * was not modified).
 *
 * @see http://www.cplusplus.com/reference/cstdlib/realloc/
 */
void* realloc(void* ptr, size_t new_size);

/**
 * @brief Deallocate memory block
 *
 * A block of memory previously allocated by a call to @c malloc
 * or @c realloc is deallocated, making it available again for
 * further allocations.
 *
 * @param ptr - Pointer to a memory block previously allocated with
 * @c malloc or @c realloc.
 *
 * @return none
 *
 * @see http://www.cplusplus.com/reference/cstdlib/free/
 */
void free(void* ptr);

#endif
