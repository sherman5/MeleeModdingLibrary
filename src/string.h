/**
 * @file string.h
 * @brief Handle all string operations.
 *
 */

#ifndef _MML_STRING_H
#define _MML_STRING_H

#include <stddef.h>
#include <stdint.h>

/** @cond */
extern void*    (*memchr)  (const void*, int, size_t);
extern int      (*memcmp)  (const void*, const void*, size_t);
extern void*    (*memcpy)  (void*, const void*, size_t);
extern void*    (*memset)  (void*, int, size_t);
extern char*    (*strchr)  (const char*, int);
extern int      (*strcmp)  (const char*, const char*);
extern int      (*strncmp) (const char*, const char*, size_t);
extern char*    (*strcpy)  (char*, const char*);
extern char*    (*strncpy) (char*, const char*, size_t);
extern size_t   (*strlen)  (const char*);
extern uint32_t (*strtoul) (const char*, char**, int);
extern char*    (*itoa)    (int32_t, char*, int);

#if 0
/// @endcond

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

/**
 * @brief Compare two blocks of memory
 *
 * Compares the first @p num bytes of the block of memory pointed
 * @p by ptr1 to the first @p num bytes pointed by @p ptr2, returning
 * zero if they all match or a value different from zero representing
 * which is greater if they do not.
 *
 * Notice that, unlike strcmp, the function does not stop comparing
 * after finding a null character
 *
 * @param ptr1 - Pointer to block of memory
 * @param ptr2 - Point to block of memory
 * @param num - Number of bytes to compare
 *
 * @return Returns an integral value indicating the relationship
 * between the content of the memory blocks:
 * <0 - first byte that does not match has lower value in ptr1
 * 0 - contents of memory blocks are equal
 * >0 - first byte that does not match has higher value in ptr1
 *
 * @see http://www.cplusplus.com/reference/cstring/memcmp/
 */
int memcmp(const void* ptr1, const void* ptr2, size_t num);

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
 * @brief Locate first occurrence of character in string
 *
 * Returns a pointer to the first occurrence of @p character in the
 * C string str.
 *
 * The terminating null-character is considered part of the C string.
 * Therefore, it can also be located in order to retrieve a pointer
 * to the end of a string.
 *
 * @param str - C string
 * @param character - Character to be located. It is passed as its
 * @c int promotion, but it is internally converted back to @c char for
 * the comparison.
 *
 * @return A pointer to the first occurrence of @c character in @c str.
 * If the character is not found, the function returns a null pointer.
 *
 * @see http://www.cplusplus.com/reference/cstring/strchr/
 */
char* strchr(const char* str, int character);

/**
 * @brief Compare two strings
 *
 * Compares the C string @p str1 to the C string @p str2.
 *
 * This function starts comparing the first character of each string. If
 * they are equal to each other, it continues with the following pairs
 * until the characters differ or until a terminating null-character
 * is reached. 
 *
 * @param str1 - C string to be compared
 * @param str2 - C string to be compared
 *
 * @return Returns an integral value indicating the relationship
 * between the strings
 * <0 - first character that does not match has lower value in ptr1
 * 0 - contents of strings are equal
 * >0 - first character that does not match has higher value in ptr1
 *
 * @see http://www.cplusplus.com/reference/cstring/strcmp/
 */
int strcmp(const char* str1, const char* str2);

/**
 * @brief Compare characters of two strings
 *
 * Compares up to @p num characters of the C string @p str1 to those of
 * the C string @p str2. This function starts comparing the first
 * character of each string. If they are equal to each other, it
 * continues with the following pairs until the characters differ, 
 * until a terminating null-character is reached, or until @p num
 * characters match in both strings, whichever happens first.
 *
 * @param str1 - C string to be compared
 * @param str2 - C string to be compared
 * @param num - Maximum number of characters to compare
 * 
 * @return Returns an integral value indicating the relationship
 * between the strings
 * <0 - first character that does not match has lower value in ptr1
 * 0 - contents of strings are equal
 * >0 - first character that does not match has higher value in ptr1
 *
 * @see http://www.cplusplus.com/reference/cstring/strncmp/
 */
int strncmp(const char* str1, const char* str2, size_t num);

/**
 * Copy string
 *
 * Copies the C string pointed by @p source into the array pointed by
 * @p destination, including the terminating null character
 * (and stopping at that point).
 *
 * To avoid overflows, the size of the array pointed by @p destination
 * shall be long enough to contain the same C string as source
 * (including the terminating null character), and should not overlap
 * in memory with @p source.
 *
 * @param destination - Pointer to the destination array where the
 * content is to be copied.
 * @param source - C string to be copied.
 *
 * @return destination is returned.
 * 
 * @see http://www.cplusplus.com/reference/cstring/strcpy/
 */
char* strcpy(char* destination, const char* source);

/**
 * @brief Copy characters from string
 *
 * Copies the first @p num characters of source to @p destination.
 * If the end of the @p source C string (which is signaled by a
 * null-character) is found before @p num characters have been copied,
 * @p destination is padded with zeros until a total of @p num
 * characters have been written to it.
 *
 * No null-character is implicitly appended at the end of @p destination
 * if source is longer than @p num. Thus, in this case, @p destination shall
 * not be considered a null terminated C string (reading it as such
 * would overflow).
 *
 * destination and source shall not overlap 
 *
 * @param destination - Pointer to the destination array where the
 * content is to be copied.
 * @param source - C string to be copied.
 * @param num - Maximum number of characters to be copied from source.
 *
 * @return destination is returned.
 *
 * @see http://www.cplusplus.com/reference/cstring/strncpy/
 */
char* strncpy(char* destination, const char* source, size_t num);

/**
 * @brief Get string length
 *
 * Returns the length of the C string str.
 *
 * The length of a C string is determined by the terminating
 * null-character: A C string is as long as the number of characters
 * between the beginning of the string and the terminating null character
 * (without including the terminating null character itself).
 *
 * This should not be confused with the size of the array that holds
 * the string. For example:
 *
 * @c char @c mystr[100]="test string"; 
 *
 * defines an array of characters with a size of 100 chars,
 * but the C string with which mystr has been initialized has a length
 * of only 11 characters. Therefore, while @c sizeof(mystr) evaluates
 * to 100, @c strlen(mystr) returns 11.
 *
 * @param str - C string.
 *
 * @return The length of string.
 */
size_t strlen(const char* str);

/**
 * @ brief Convert string to unsigned long integer
 *
 * Parses the C-string @p str, interpreting its content as an integral
 * number of the specified @p base, which is returned as an value of type
 * @c unsigned @c long @c int.
 *
 * @param str - C-string containing the representation of an integral
 * number.
 * @param endptr - Reference to an object of type @c char*, whose value is
 *  set by the function to the next character in @p str after the numerical
 * value. This parameter can also be a null pointer, in which case it is
 * not used.
 * @param base - Numerical base (radix) that determines the valid
 * characters and their interpretation.
 *
 * @return On success, the function returns the converted integral number
 * as an unsigned long int value. If no valid conversion could be
 * performed, a zero value is returned. 
 *
 * @see http://www.cplusplus.com/reference/cstdlib/strtoul/
 */
uint32_t strtoul(const char* str, char** endptr, int base);

/**
 * Convert integer to string
 * 
 * Converts an integer value to a null-terminated string using the
 * specified @p base and stores the result in the array given
 * by @p str.
 *
 * If @p base is 10 and value is negative, the resulting string is
 * preceded with a minus sign (-). With any other base, value is
 * always considered @c unsigned.
 *
 * @p str should be an array long enough to contain any possible value, 
 * i.e. 33 bits in a 32-bit platform.
 *
 * @param value - Value to be converted to a string.
 * @param str - Array in memory where to store the resulting
 * null-terminated string.
 * @param base - Numerical base used to represent the value as a string,
 * between 2 and 36, where 10 means decimal base, 16 hexadecimal,
 * 8 octal, and 2 binary.
 *
 * @return A pointer to the resulting null-terminated string,
 * same as parameter @p str. 
 *
 * @see http://www.cplusplus.com/reference/cstdlib/itoa/
 */
char* itoa(int32_t value, char* str, int base);

/** @cond */
#endif
/** @endcond */

/**
 * @brief Concatenate strings
 *
 * Appends a copy of the @p source string to the @p destination string.
 * The terminating null character in @p destination is overwritten by the
 * first character of source, and a null-character is included at the
 * end of the new string formed by the concatenation of both 
 * in @p destination.
 *
 * @p destination and @p source shall not overlap.
 *
 * @param destination - Pointer to the destination array, which should
 *      contain a C string, and be large enough to contain the
 *      resulting string.
 * @param source - C string to be appended
 *
 * @return @p destination is returned.
 *
 * @see http://www.cplusplus.com/reference/cstring/strcat/
 */
char* strcat(char* destination, const char* source);

#endif
