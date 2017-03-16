/**
 * @file print.h
 * @brief Print output
 *
 */

#ifndef MML_PRINT_H
#define MML_PRINT_H

#include "gctypes.h"

/** @cond */
extern int (*sprintf)(char* str, const char* format, ...);

/**
 * @brief print to the output stream
 * @ingroup CallsMalloc
 * 
 * Writes the C string pointed by @p format to the output stream. If
 * @p format includes format specifiers (subsequences beginning with %),
 * the additional arguments following @p format are formatted and inserted
 * in the resulting string replacing their respective specifiers.
 *
 * @param format - C string
 * @return On success, the total number of character written. On
 *  failure, a negative number is returned
 *
 * @see http://www.cplusplus.com/reference/cstdio/printf/
 */
//int printf(const char* format, ...);

#if 0
/// @endcond

/**
 * @brief write formatted data to string
 * 
 * Composes a string with the same text that would be printed if @p format
 * was used on @c printf, but instead of being printed, the content is
 * stored as a C string in the buffer pointed by @p str.
 *
 * The size of the buffer should be large enough to contain the entire
 * resulting string
 *
 * @param str - Pointer to a buffer where the resulting C string is stored
 * @param format - C string
 *
 * @return On success, the total number of character written. On
 *  failure, a negative number is returned
 *
 * @see http://www.cplusplus.com/reference/cstdio/sprintf/
 */
int sprintf(char* str, const char* format, ...);

#endif

/**
 * @brief print a string to the output stream
 * @ingroup CallsMalloc
 * 
 * This function prints a string to an output stream
 * displayed on the designated window (tournament mode - replaces
 * debug menu).
 *
 * @param str - string to output
 * @return none
 */
void print(const char* str);

/**
 * @brief clear the output stream
 *
 * This function clears any text on the output stream
 *
 * @return none
 */
void clear();

/**
 * @brief print error message
 * @ingroup CallsMalloc
 *
 * Print an error message
 *
 * @param errMessage - error message to print
 * @return none
 *
 * @note this will still print the error if the print stream has failed
 *  to allocate memory
 */
void error(const char* errMessage);

/**
 * @brief display print stream
 *
 * Create the display where print sends output, should never be
 * called by user. The user should create a branch to this symbol 
 * at 0x801a633c overwriting instruction 0x7c7f1b78 (SSBM v1.02)
 *
 * @return none
 */
void display();

#endif
