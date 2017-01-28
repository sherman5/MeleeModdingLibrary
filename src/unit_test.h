#ifndef UNIT_TESTS_H
#define UNIT_TESTS_H

#include <stdint.h>
#include <stdbool.h>

extern uint32_t* output;
extern int numTests;

bool AZERO(float diff, float tol);

#define REQUIRE_INT(cond, value) requireInt(cond, value); __COUNTER__;
void requireInt(bool cond, int value);

#define REQUIRE_FLOAT(cond, value) requireFloat(cond, value); __COUNTER__;
void requireFloat(bool cond, float value);

#define START_TEST void runTest()
#define END_TEST numTests = __COUNTER__;

#endif

