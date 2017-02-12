/**
 * @file print.h
 * @brief Print output
 *
 */

#ifndef PRINT_H
#define PRINT_H

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

#endif
