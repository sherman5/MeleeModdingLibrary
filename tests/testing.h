#ifndef TESTING_H
#define TESTING_H

#include <stdint.h>

const uint32_t* testAddress = (uint32_t*) 0x80001800;
int numTestCases = 0;

#define TEST_CASE(x) \
    void testFunction
    do { \
    

#define REQUIRE(x) \
    do { \
        if (!x) { \
            *testAddress = 0xFFFFFFFF; \
        } else { \
            *testAddress = 0xAAAAAAAA; \
        } \
        testAddress += 0x04; \
    } while (0)

#endif
