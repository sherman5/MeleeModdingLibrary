#ifndef MML_LOGIC_H
#define MML_LOGIC_H

#include "gctypes.h"

typedef union
{
    u32 u;
    s32 s;
    f32 f;
    void* p;

} FunctionArg;

typedef struct
{
    void* function;
    FunctionArg arg1;
    FunctionArg arg2;
    
} FunctionCall;


typedef struct
{
    FunctionCall condition;
    FunctionCall action;

} Logic;

#endif
