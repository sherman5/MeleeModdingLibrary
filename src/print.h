#ifndef PRINT_H
#define PRINT_H

/**
 * @brief print a string to the output stream
 * 
 * This function prints a string to an output stream
 * displayed on the designated window (tournament mode - replaces
 * debug menu). The stream is normally allocated with malloc, but
 * it can be done at compile time (when testing malloc for instance).
 * In that case, the user must first call @c initStream and pass
 * a @c char[] that they have declared in a global scope
 *
 * @param str - string to output
 *
 * @return none
 */
void print(const char* str);

/**
 * @brief provide stream for output
 *
 * @param mem - block of memory to store output in, need at least 156 bytes
 * @param size - size of the array @p stream
 *
 * @return none
 */
void initStream(char* mem, unsigned size);

#endif
