/**
 * @file logic.h
 * @brief Defines structs for AI logic.
 *
 */

#ifndef MML_LOGIC_H
#define MML_LOGIC_H

#include "gctypes.h"

typedef union
{
    u32 u;
    s32 s;
    f32 f;
    void* p;

} FunctionArg __attribute__((__transparent_union__));

typedef struct
{
    void* function;
    FunctionArg arg1;
    FunctionArg arg2;
    
} Function;

//TODO: add random option to condition
typedef struct
{
    Function condition;
    Function action;

} Logic;

#define LOGIC(c, a) (Logic) {(Function) c, (Function) a}

#endif
