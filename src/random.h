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
