#ifndef TESTING_H
#define TESTING_H

#include <stdint.h>

extern uint32_t* output;

#define REQUIRE_EQ(L, R) \
    do { \
        if ((L) != (R)) { \
            *output = (L); \
        } else if (*output == 0xEEEE0000 || *output == 0x0000AAAA) { \
            *output = 0x0000AAAA; \
        }\
        output++;\
    } while (0)

#define REQUIRE_AEQ(L, R, T) \
    do { \
        if (!APPROX_EQ(L, R, T)) { \
            *output = (L); \
        } else if (*output == 0xEEEE0000 || *output == 0x0000AAAA) { \
            *output = 0x0000AAAA; \
        }\
        output++;\
    } while (0)

#define APPROX_EQ(a,b,tol) ((a) < (b) ? (b) - (a) < tol : (a) - (b) < tol)
    
#endif

