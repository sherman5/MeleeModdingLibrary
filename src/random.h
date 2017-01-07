#ifndef RANDOM_H
#define RANDOM_H

#include <stdint.h>

/*
    generate random 32-bit value using a linear-feedback shift
    register. The internal random value of the game is used as a
    seed. A second random value is generated and written to the 
    address of the internal random random value. This ensures that
    no random number is used twice.
*/
uint32_t randUint32();

/* generate random number in [0,1] */
float rand();

#endif
