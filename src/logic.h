/**
 * @file logic.h
 * @brief Defines structs for AI logic.
 *
 */

#ifndef MML_LOGIC_H
#define MML_LOGIC_H

#include "gctypes.h"

/**
 * @brief Function Argument
 *
 * This union allows for a function to accept multiple data types as
 * parameters. Since it is marked as a transparent_union it is always
 * passed as a 32-bit integer in the standard registers. Thus, if a 
 * function has the signature <tt> void foo(u32) </tt> it is valid to
 * call it as <tt> foo(FunctionArg) </tt>. However,
 * <tt> void bar(float) </tt> would expect the parameter to be in a 
 * floating-point register, thus calling <tt> bar(FunctionArg) </tt>
 * is not valid.
 *
 * @see https://gcc.gnu.org/onlinedocs/gcc-3.3/gcc/Type-Attributes.html
 */
typedef union
{
    u32 u; /**< 32-bit unsigned integer */
    s32 s; /**< 32-bit signed integer */
    f32 f; /**< 32-bit floating-point value */
    void* p; /**< pointer (32-bits) */

} FunctionArg __attribute__((__transparent_union__));

/**
 * @brief Describes a function call
 *
 * Allows for a function call to be stored in memory. Essentially,
 * a function pointer with arguments.
 */
typedef struct
{
    void* function; /**< function pointer */
    FunctionArg arg1; /**< first argument of function call */
    FunctionArg arg2; /**< second argument of function call */
    
} FunctionCall;

/**
 * @brief Describes simple if-then logic
 *
 * Essentially captures the behavior of an if statement in a compact
 * struct. This allows for arrays of 'logic' (if-else chain) to be stored
 * in memory and accessed at specific times.
 */
typedef struct
{
    FunctionCall condition; /**< function that returns bool */
    FunctionCall action; /**< function to call if condition returns true */

} Logic;

#endif
