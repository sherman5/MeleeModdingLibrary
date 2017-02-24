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
    u32 size;

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
extern RawInput _raw_shNeutralB[4];
extern Move _mv_shNeutralB;

/**
 * @brief Short Hop
 */
extern RawInput _raw_shortHop[2];
extern Move _mv_shortHop;

/**
 * @brief Hit standard tech
 */
extern RawInput _raw_tech[2];
extern Move _mv_tech;
#define SET_TECH_DIR(x) _raw_tech[0] = (RawInput) {L_BUTTON | FULL_STICK | STICK_ANGLE(x), 0, NO_FLAGS}

/**
 * @brief Spot Dodge
 */
extern RawInput _raw_spotDodge[3];
extern Move _mv_spotDodge;

/**
 * @brief Press A
 */
extern RawInput _raw_aPress[2];
extern Move _mv_getUpAttack;
extern Move _mv_jab;

/**
 * @brief Input DI
 */
extern RawInput _raw_DI[2];
extern Move _mv_DI;
#define SET_DI_DIR(x) _raw_DI[0] = (RawInput) {FULL_STICK | STICK_ANGLE(x), 0, NO_FLAGS}

#endif
