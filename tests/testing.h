#ifndef TESTING_H
#define TESTING_H

#include <stdint.h>

uint32_t* outputAddress = (uint32_t*) 0x80001804;

#define REQ_CT __COUNTER__

#define CHECK_COND(x, c) \
    do { \
        if (!(x)) { \
            *(outputAddress + c) = 0xFFFF0000; \
        } else if (*(outputAddress + c) != 0xFFFF0000) { \
            *(outputAddress + c) = 0x0000AAAA; \
        } \
    } while (0)

#define REQUIRE(x) CHECK_COND(x, REQ_CT)

#define APPROX_EQ(a,b,tol) ((a) < (b) ? (b) - (a) < tol : (a) - (b) < tol)
    
#endif

