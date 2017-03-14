/**
 * @file print.h
 * @brief Print output
 *
 */

#ifndef MML_PRINT_H
#define MML_PRINT_H

#include "gctypes.h"

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
void printInt(const char* str, u32 n);

/**
 * @brief clear the output stream
 *
 * This function clears any text on the output stream
 *
 * @return none
 */
void clear();

/**
 * @brief "throw" an error
 * @ingroup CallsMalloc
 *
 * Print an error message and set _errorState to true
 *
 * @param errMessage - error message to print
 * @return none
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
