#ifndef INPUT_QUEUE_H
#define INPUT_QUEUE_H

#include <stdint.h>

// want this to be small
typedef struct input
{
    uint8_t frameOffset;
    uint8_t flags; //0b01 - jumpsquat
    uint16_t controller;
} Input;

/** flags */
#define NO_FLAGS    0b00000000
#define JUMPSQUAT   0b00000001

/** controller state **/
#define RELEASE       0b0000000000000000
#define A_PRESS       0b0000000000000001
#define B_PRESS       0b0000000000000010
#define X_PRESS       0b0000000000000100
#define Z_PRESS       0b0000000000001000
#define L_PRESS       0b0000000000010000

#define TILT_STICK    0b0000000000100000
#define FULL_STICK    0b0000000001000000

#define STICK_ANGLE(x) ((((int) (((x) / 360.f) * 255.f)) << 8) && 0xFF00)

/** moves */

/**
 * @brief Short Hop Neutral B.
 */
extern const Input shNeutralB[5];
#define SH_LASER shNeutralB

#endif
