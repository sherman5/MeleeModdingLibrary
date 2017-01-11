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

/**
 * @brief Generate random 32-bit value.
 *
 * Generate random 32-bit value using a linear-feedback shift
 * register. The internal random value of the game is used as a
 * seed. A second random value is generated and written to the 
 * address of the internal random random value. This ensures that
 * no random number is used twice.
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
