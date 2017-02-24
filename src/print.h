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
 * 
 * This function prints a string to an output stream
 * displayed on the designated window (tournament mode - replaces
 * debug menu).
 *
 * @param str - string to output
 *
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

void erro(const char* errMessage);

extern bool _error_state;

#endif
