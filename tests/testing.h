#ifndef TESTING_H
#define TESTING_H

#include <stdint.h>

uint32_t* outputAddress;

#define REQUIRE(x) \
    do { \
        if (!(x)) { \
            *(outputAddress++) = 0xFFFF0000; \
        } else if (*(outputAddress) != 0xFFFF0000) { \
            *(outputAddress++) = 0x0000AAAA; \
        } \
    } while (0)

#define APPROX_EQ(a,b,tol) ((a) < (b) ? (b) - (a) < tol : (a) - (b) < tol)
    
#endif

