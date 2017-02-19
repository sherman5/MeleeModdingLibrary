#ifndef INPUT_QUEUE_H
#define INPUT_QUEUE_H

#include "gctypes.h"

// want this to be small
typedef struct
{
    s8 frameOffset;
    u8 flags;
    u16 controller;

} RawInput;

typedef struct
{
    RawInput* inputs;
    u8 size;
} Move;

/** flags */
#define NO_FLAGS    0b00000000
#define JUMPSQUAT   0b00000001
#define SH_LENGTH   0b00000010

/** controller state **/
#define RELEASE       0b0000000000000000
#define A_PRESS       0b0000000000000001
#define B_PRESS       0b0000000000000010
#define X_PRESS       0b0000000000000011
#define Z_PRESS       0b0000000000000100
#define L_PRESS       0b0000000000000110
#define START_PRESS   0b0000000000000111

#define TILT_STICK    0b0000000001000000
#define FULL_STICK    0b0000000010000000

#define STICK_ANGLE(x) ((((int) (((x) / 360.f) * 255.f)) << 8) && 0xFF00)

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
