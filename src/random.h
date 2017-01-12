/**
 * @file random.h
 * @brief Random number generation.
 *
 */

#ifndef RANDOM_H
#define RANDOM_H

#include <stdint.h>

/**
 * @brief Generate random 32-bit value.
 *
 * @return Random 32-bit @c integer    
*/
uint32_t randUint32();

/**
 * @brief Generate random number in [0,1].
 *
 * @return - Random floating point number in [0,1]
 */
float rand();

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
unsigned sample(float probs[]);

#endif
