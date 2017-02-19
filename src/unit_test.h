/**
 * @file unit_test.h
 * @brief Macros for unit testing.
 *
 */

#ifndef MML_UNIT_TEST_H
#define MML_UNIT_TEST_H

#include "print.h"
#include "math.h"
#include "gctypes.h"

#define UNIT_TEST static bool tests_passed = true

#define STRINGIFY(x) #x
#define TOSTRING(x) STRINGIFY(x)
#define ASSERT_MSG "assert failed: " __FILE__ ":" TOSTRING(__LINE__)

#define REQUIRE(condition) do { if (!(condition)) \
    {print(ASSERT_MSG); tests_passed = false;}} while (0)

#define APPROX_ZERO(x, tol) (fabs(x) < tol)

#define REQUIRE_FLT_EQ(L, R, tol) REQUIRE(APPROX_ZERO((L) - (R), tol))

#define END_TEST do { if (tests_passed) \
    {print("all tests passed!");}} while (0)

#endif

