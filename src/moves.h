/**
 * @file moves.h
 * @brief Common input sequences.
 *
 */

#ifndef MML_MOVES_H
#define MML_MOVES_H

#include "gctypes.h"
#include "controller.h"

/** represent an input in its minimal form */
typedef struct __attribute__((packed))
{
    u16 controller; /**< controller state */
    s8 frameOffset; /**< frame offset */
    u8 flags; /**< input flags */

} RawInput;

/** @brief Represents a single move (string of timed inputs) */
typedef struct
{
    RawInput* inputs; /**< input array */
    u32 size; /**< size of array */

} Move;

//@{
/** Input Flags */
#define NO_FLAGS    0
#define JUMPSQUAT   (1 << 0)
#define SH_LENGTH   (1 << 1)
#define LEDGEDASH   (1 << 2)
//@}

//@{
/** Controller State Macros */
#define RELEASE         0x0000
#define OVERWRITE       0
#define STICK_ANGLE(x)  ((((u8) (((x) / 360.f) * 255.f)) << 8) & 0xFF00)
//@}

/** @cond **/
extern RawInput _raw_shNeutralB[4];
extern RawInput _raw_shortHop[2];
extern RawInput _raw_tech[2];
extern RawInput _raw_spotDodge[3];
extern RawInput _raw_aPress[2];
extern RawInput _raw_hitDI[2];
extern RawInput _raw_holdDirection[1];
extern RawInput _raw_upB[2];
extern RawInput _raw_sideB[1];
extern RawInput _raw_doubleJump[1];
extern RawInput _raw_downB[2];
extern RawInput _raw_ledgeDash[4];
/** @endcond **/

/** Short Hop Neutral B. */
extern Move _mv_shNeutralB;

/** Short Hop */
extern Move _mv_shortHop;

/** Hit standard tech */
extern Move _mv_tech;

/** Set tech direction **/
#define SET_TECH_DIR(x) _raw_tech[0].controller = \
    L_BUTTON | FULL_STICK | STICK_ANGLE(x)

/** Spot Dodge */
extern Move _mv_spotDodge;

/** Get Up Attack */
extern Move _mv_getUpAttack;

/** Jab */
extern Move _mv_jab;

/** DI from hit */
extern Move _mv_hitDI;

/** Set the direction of DI for normal hits */
#define SET_HIT_DI_DIR(x) _raw_hitDI[0].controller = \
    FULL_STICK | STICK_ANGLE((x))

/** DI from throw @note INDEFINITE */
extern Move _mv_throwDI;

/** Set the direction of DI for throws */
#define SET_THROW_DI_DIR(x) _raw_holdDirection[0].controller = \
    FULL_STICK | STICK_ANGLE((x))

/** Up B @note INDEFINITE */
extern Move _mv_upB;

/** Set the direction for the Up B */
#define SET_UP_B_DIR(x) _raw_upB[1].controller = \
    FULL_STICK | STICK_ANGLE((x))

/** Side B */
extern Move _mv_sideB;

/** Set the direction for the side B */
#define SET_SIDE_B_DIR(x) _raw_sideB[0].controller = \
    B_BUTTON | FULL_STICK | STICK_ANGLE((x))

/** Double Jump with Direction @note INDEFINITE */
extern Move _mv_doubleJump;

/** Set the direction for the double jump */
#define SET_DJ_DIR(x) _raw_doubleJump[0].controller = \
    X_BUTTON | FULL_STICK | STICK_ANGLE((x))

/** Ledgedash */
extern Move _mv_ledgeDash;

/** Set angle for ledge dash */
#define SET_LEDGEDASH_ANGLE(x) _raw_ledgeDash[2].controller = \
    L_BUTTON | FULL_STICK | STICK_ANGLE((x))

/** Hold Control Stick in Direction @note INDEFINITE */
extern Move _mv_holdDirection;

/** Set the direction of the control stick */
#define SET_HOLD_DIR(x) _raw_holdDirection[0].controller = \
    FULL_STICK | STICK_ANGLE((x))

/** Down B */
extern Move _mv_downB;

#endif

