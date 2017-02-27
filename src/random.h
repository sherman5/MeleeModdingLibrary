/**
 * @file random.h
 * @brief Random number generation.
 *
 */

#ifndef MML_RANDOM_H
#define MML_RANDOM_H

#include "gctypes.h"

/**
 * @brief Generate random number in [0,1].
 *
 * @return - Random floating point number in [0,1]
 */
float rand();

/**
 * @brief Sample uniformly from <tt> [a, b] </tt>.
 *
 * @return random floating point number in <tt> [a, b] </tt>
 */
float uniform(float a, float b);

/**
 * @brief Return index of array according to given probabilities.
 *
 * @param probs - array of probabilities, must sum to 1
 * @param size - size of probability array 
 * @return index of array
 */
unsigned sample(const float* probs, size_t size);

#endif
