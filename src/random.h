/**
 * @file random.h
 * @brief Random number generation.
 *
 */

#ifndef RANDOM_H
#define RANDOM_H

#include <stdint.h>

/** address that holds a random 32-bit seed in melee */
#define RAND_ADDRESS 0x804D5F90

/** function that changes the value in RAND_ADDRESS */
#define RANDU_FPTR ((void*) 0x80380580)

/**
 * @brief Generate random 32-bit value.
 *
 * @return Random 32-bit @c integer    
*/
uint32_t randUint32();

/**
 * @brief Generate random number in [0,1]
 *
 * @return random floating point number in [0,1]
 */
float rand();

#endif
