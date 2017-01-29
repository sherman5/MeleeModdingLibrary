#ifndef SYSTEM_H
#define SYSTEM_H

#include <stddef.h>


/** @cond */
extern void* (*malloc)(size_t size);

#if 0
/** @endcond */


/** @cond */
#endif
/** @endcond */

/**
 * @brief Allocate memory block
 *
 * Allocates a block of @p size bytes of memory, returning a pointer
 * to the beginning of the block. The content of the newly allocated
 * block of memory is not initialized. If @c malloc fails to allocate
 * the memory, a @c NULL pointer is returned.
 *
 * @param size Size of memory block in bytes.
 *
 * @return On success, a pointer to the memory block allocated by
 * the function. If the function failed to allocate the requested
 * block of memory, a null pointer is returned.
 *
 * @see http://www.cplusplus.com/reference/cstdlib/malloc/
 */
void* malloc(size_t size);

/**
 * @brief Reallocate memory block
 *
 * Changes the size of the memory block pointed to by @p ptr. The function
 * may move the memory block to a new location (whose address is returned
 * by the function). The content of the memory block is preserved up to
 * the lesser of the new and old sizes, even if the block is moved to a
 * new location. 
 *
 * @param ptr Pointer to a memory block previously allocated with
 * @c malloc or @c realloc. Alternatively, this can be a null pointer,
 * in which case a new block is allocated (as if @c malloc was called).
 * @param size New size for the memory block, in bytes.
 *
 * @return A pointer to the reallocated memory block, which may be
 * either the same as @p ptr or a new location. A null-pointer indicates
 * either that @p size was zero (an thus ptr was deallocated), or that the
 * function did not allocate storage (and thus the block pointed by @p ptr
 * was not modified).
 *
 * @see http://www.cplusplus.com/reference/cstdlib/realloc/
 */
void* realloc(void* ptr, size_t size);

/**
 * @brief Deallocate memory block
 *
 * A block of memory previously allocated by a call to @c malloc
 * or @c realloc is deallocated, making it available again for
 * further allocations.
 *
 * @param ptr Pointer to a memory block previously allocated with
 * @c malloc or @c realloc.
 *
 * @return none
 *
 * @see http://www.cplusplus.com/reference/cstdlib/free/
 */
void free(void* ptr);

#endif
