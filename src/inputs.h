/**
 * @file inputs.h
 * @brief Common input sequences.
 *
 */

#ifndef MML_INPUTS_H
#define MML_INPUTS_H

#include "gctypes.h"
#include "controller.h"

typedef struct __attribute__((packed))
{
    u16 controller;
    s8 frameOffset;
    u8 flags;

} RawInput;

typedef struct
{
    RawInput* inputs;
    u8 size;

} Move;

/** flags */
#define NO_FLAGS    0
#define JUMPSQUAT   (1 << 0)
#define SH_LENGTH   (1 << 1)

#define RELEASE 0x0000
#define STICK_ANGLE(x) ((((u8) (((x) / 360.f) * 255.f)) << 8) & 0xFF00)

/**
 * @brief Short Hop Neutral B.
 */
extern RawInput raw_shNeutralB[4];
extern Move shNeutralB;

/**
 * @brief Short Hop
 */
extern RawInput raw_shortHop[2];
extern Move shortHop;

#endif
