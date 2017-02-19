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


typedef struct
{
    Function condition;
    Function action;

} Logic;

#endif
