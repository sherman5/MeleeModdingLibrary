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

/** @cond **/

#define STRINGIFY(x) #x
#define TOSTRING(x) STRINGIFY(x)
#define ASSERT_MSG "assert failed: " __FILE__ ":" TOSTRING(__LINE__)

#define APPROX_ZERO(x, tol) (fabs(x) < tol)
/** @endcond **/

/** Require @p condition to be true **/
#define REQUIRE(condition) do { if (!(condition)) \
    {print(ASSERT_MSG); tests_passed = false;}} while (0)

/** Require @p L and @p R to be within @p tol of each other */
#define REQUIRE_FLT_EQ(L, R, tol) REQUIRE(APPROX_ZERO((L) - (R), tol))

/** Macro placed in the global scope of each .c file, before END_TEST **/ 
#define UNIT_TEST static bool tests_passed = true

/** Macro placed in a function after all tests have been run **/
#define END_TEST do { if (tests_passed) \
    {print("all tests passed!");}} while (0)

#endif

