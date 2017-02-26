/**
 * @file logic.h
 * @brief Defines structs for AI logic.
 *
 */

#ifndef MML_LOGIC_H
#define MML_LOGIC_H

#include "gctypes.h"

/** Function Argument **/
typedef union
{
    u32 u;
    s32 s;
    f32 f;
    void* p;

} FunctionArg __attribute__((__transparent_union__));

/** Function **/
typedef struct
{
    void* function;
    FunctionArg arg1;
    FunctionArg arg2;
    
} Function;

/** Logic **/
typedef struct
{
    Function condition;
    Function action;

} Logic;

#endif
