#ifndef TESTING_H
#define TESTING_H

#include <stdint.h>
#include <math.h>

extern uint32_t* output;
extern int numTests;

#define AZERO(diff, tol) (diff > 0 ? diff < tol : -diff < tol)

#define REQUIRE_FLT_EQ(L, R) fltEq(L, R); __COUNTER__;
#define REQUIRE_INT_EQ(L, R) intEq(L, R); __COUNTER__;

#define END_TEST int numTests = __COUNTER__;

extern void fltEq(float L, float R);
extern void intEq(uint32_t L, uint32_t R);

#endif

