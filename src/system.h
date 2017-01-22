#ifndef SYSTEM_H
#define SYSTEM_H

#include <stddef.h>


/** @cond */
extern void* (*malloc)(size_t size);
extern void* (*memcpy)(void* destination, const void* source, size_t num);
extern void* (*memset)(void* ptr, int value, size_t num);
extern void* (*memchr)(const void* ptr, int value, size_t num);
extern int (*memcmp)(const void* ptr1, const void* ptr2, size_t num);

#if 0
/** @endcond */

/**
 * @brief Allocate memory block
 *
 * Allocates a block of @p size bytes of memory, returning a pointer
 * to the beginning of the block.
 *
 * The content of the newly allocated block of memory is not initialized, remaining with indeterminate values.
 *
 * The underlying type of the objects pointed to by both the source
 * and destination pointers are irrelevant for this function; The
 * result is a binary copy of the data.
 *
 * To avoid overflows, the size of the arrays pointed to by both the
 * destination and source parameters, shall be at least num bytes, and
 * should not overlap (for overlapping memory blocks, memmove is a safer
 * approach).
 *
 * @param destination - Pointer to the destination array where the content
 *      is to be copied, type-casted to a pointer of type @c void*.
 * @param source - Pointer to the source of data to be copied,
 *      type-casted to a pointer of type @c const @c void*.
 * @param num - Number of bytes to copy.
 *
 * @return @p destination is returned.
 *
 * @see http://www.cplusplus.com/reference/cstring/memcpy/
 */
void* memcpy (void* destination, const void* source, size_t num);

/**
 * @brief Copy block of memory
 *
 * Copies the values of @p num bytes from the location pointed to by
 * @p source directly to the memory block pointed to by @p destination.
 *
 * The underlying type of the objects pointed to by both the source
 * and destination pointers are irrelevant for this function; The
 * result is a binary copy of the data.
 *
 * To avoid overflows, the size of the arrays pointed to by both the
 * destination and source parameters, shall be at least num bytes, and
 * should not overlap (for overlapping memory blocks, memmove is a safer
 * approach).
 *
 * @param destination - Pointer to the destination array where the content
 *      is to be copied, type-casted to a pointer of type @c void*.
 * @param source - Pointer to the source of data to be copied,
 *      type-casted to a pointer of type @c const @c void*.
 * @param num - Number of bytes to copy.
 *
 * @return @p destination is returned.
 *
 * @see http://www.cplusplus.com/reference/cstring/memcpy/
 */
void* memcpy (void* destination, const void* source, size_t num);

/**
 * @brief Fill block of memory
 *
 * Sets the first @p num bytes of the block of memory pointed by
 * @p ptr to the specified @p value (interpreted as an @c unsigned @c char).
 *
 * @param ptr - Pointer to the block of memory to fill.
 * @param value - Value to be set. The value if passed as an @c int, but the
 *      function fills the block of memory using the @c unsigned @c char
 *      conversion of this value.
 * @param num - Number of bytes to be set to the @p value
 * 
 * @return @p ptr is returned
 *
 * @see http://www.cplusplus.com/reference/cstring/memset/
 */
void* memset (void* ptr, int value, size_t num);

/**
 * @brief Locate character in block of memory
 * 
 * Searches within the first @p num bytes of the block of memory pointed
 * by @p ptr for the first occurrence of @p value (interpreted as an
 * @c unsigned @c char), and returns a pointer to it.
 * 
 * Both @p value and each of the bytes checked on the the @p ptr array
 * are interpreted as @c unsigned @c char for the comparison.
 *
 * @param ptr - Pointer to the block of memory where the search
 *      is performed.
 * @param value - Value to be located. The value is passed as an @c int,
 *      but the function performs a byte per byte search using the
 *      @c unsigned @c char conversion of this value.
 * @param num - Number of bytes to be analyzed.
 *
 * @return A pointer to the first occurrence of @p value in the block
 *      of memory pointed by @p ptr. If the value is not found, the
 *      function returns a null pointer.
 *
 * @see http://www.cplusplus.com/reference/cstring/memchr/
 */
void* memchr(const void* ptr, int value, size_t num);

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
