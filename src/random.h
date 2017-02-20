/**
 * @file random.h
 * @brief Random number generation.
 *
 */

#ifndef MML_RANDOM_H
#define MML_RANDOM_H

#include "gctypes.h"

#ifdef PAL
    
#error random.h not compatible with PAL

#else

/** address that holds a random 32-bit seed in melee */
#define RAND_ADDRESS 0x804D5F90

#endif

/**
 * @brief Generate random 32-bit value.
 *
 * @return Random 32-bit @c integer    
*/
u32 randUint32(void);

/**
 * @brief Generate random number in [0,1].
 *
 * @return - Random floating point number in [0,1]
 */
float rand(void);

/**
 * @brief Sample uniformly from [@p a,@p b].
 *
 * @return random floating point number in [@p a, @p b]
 */
float uniform(float a, float b);

/**
 * @brief Return index of array according to given probabilities.
 *
 * @param probs[] - array of probabilities, must sum to 1
 *
 * @return index of array
 */
unsigned sample(const float* probs, size_t size);

#endif
