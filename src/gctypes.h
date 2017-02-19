/**
 * @file gctypes.h
 * @brief Data types for the gamecube
 *
 */

#ifndef MML_GC_TYPES_H
#define MML_GC_TYPES_H

#include <stdint.h>

typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;

typedef int8_t s8;
typedef int16_t s16;
typedef int32_t s32;

typedef volatile u8 vu8;
typedef volatile u16 vu16;
typedef volatile u32 vu32;

typedef volatile s8 vs8;
typedef volatile s16 vs16;
typedef volatile s32 vs32;

typedef float f32;
typedef double f64;

typedef volatile float vf32;
typedef volatile double vf64;

typedef u32 size_t;

typedef u32 bool;

#define true 1
#define false 0
#define __bool_true_false_are_defined 1

#define NULL ((void*) 0)

#endif
