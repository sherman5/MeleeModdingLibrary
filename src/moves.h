/**
 * @file moves.h
 * @brief Common input sequences.
 *
 */

#ifndef MML_MOVES_H
#define MML_MOVES_H

#include "gctypes.h"
#include "controller.h"

/** @brief represent an input in its minimal form */
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
extern RawInput _raw_wavedash[3];
extern RawInput _raw_dash[2];
/** @endcond **/

extern Move _mv_shNeutralB; /**< Short Hop Neutral B. */
extern Move _mv_shortHop; /**< Short Hop */
extern Move _mv_tech; /**< Hit standard tech */
extern Move _mv_spotDodge; /**< Spot Dodge */
extern Move _mv_getUpAttack; /**< Get Up Attack */
extern Move _mv_jab; /**< Jab */
extern Move _mv_hitDI; /**< DI from hit */
extern Move _mv_throwDI; /**< DI from throw @ingroup IndefiniteMove */
extern Move _mv_upB; /**< Up B @ingroup IndefiniteMove */
extern Move _mv_sideB; /**< Side B */
extern Move _mv_downB; /**< Down B */
extern Move _mv_wavedash; /**< Wavedash at an angle */
extern Move _mv_doubleJump; /**< DJ towards direction @note INDEFINITE */
extern Move _mv_holdDirection; /**< Hold stick @ingroup IndefiniteMove */
extern Move _mv_ledgeDash; /**< Ledgedash */
extern Move _mv_dash; /**< Dash Dance (one dash input) */

/** Set tech direction **/
#define SET_TECH_DIR(x) _raw_tech[0].controller = \
    L_BUTTON | FULL_STICK | STICK_ANGLE(x)

/** Set the direction of DI for normal hits */
#define SET_HIT_DI_DIR(x) _raw_hitDI[0].controller = \
    FULL_STICK | STICK_ANGLE(x)

/** Set the direction of DI for throws */
#define SET_THROW_DI_DIR(x) _raw_holdDirection[0].controller = \
    FULL_STICK | STICK_ANGLE(x)

/** Set the direction for the Up B */
#define SET_UP_B_DIR(x) _raw_upB[1].controller = \
    FULL_STICK | STICK_ANGLE(x)

/** Set the direction for the side B */
#define SET_SIDE_B_DIR(x) _raw_sideB[0].controller = \
    B_BUTTON | FULL_STICK | STICK_ANGLE(x)

/** Set the direction for the double jump */
#define SET_DJ_DIR(x) _raw_doubleJump[0].controller = \
    X_BUTTON | FULL_STICK | STICK_ANGLE(x)

/** Set angle for ledge dash */
#define SET_LEDGEDASH_ANGLE(x) _raw_ledgeDash[2].controller = \
    L_BUTTON | FULL_STICK | STICK_ANGLE(x)

/** Set the direction of the control stick */
#define SET_HOLD_DIR(x) _raw_holdDirection[0].controller = \
    FULL_STICK | STICK_ANGLE(x)

/** Set direction of wavedash */
#define SET_WAVEDASH_DIR(x) _raw_wavedash[1].controller = \
    L_BUTTON | FULL_STICK | STICK_ANGLE(x)

/** Set direction of dash */
#define SET_DASH_DIR(x) _raw_dash[0].controller = \
    FULL_STICK | STICK_ANGLE(x)

#endif

