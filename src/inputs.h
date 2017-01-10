#ifndef INPUT_QUEUE_H
#define INPUT_QUEUE_H

#include <stdint.h>

// want this to be small
typedef struct input
{
    uint8_t frameOffset;
    uint8_t flags; //0b01 - button, 0b10 - stick, 0b0100 - jumpsquat
    char button;
    uint8_t radius; // divide by 255
    int16_t angle; // integer precision is good enough
} Input;

#define DEFAULT_INPUT {0,0,0,0,0};

/** flags */
#define NO_FLAGS    0b00000000
#define BUTTON      0b00000001
#define STICK       0b00000010
#define JUMPSQUAT   0b00000100

/** input */
#define GET_MACRO(_1,_2,_3,_4,_5,NAME,...) NAME
#define INPUT(...) GET_MACRO(__VA_ARGS__, INPUT5, INPUT4, INPUT3)(__VA_ARGS__)

#define INPUT3(fo, b, fl) {.frameOffset = fo, .button = b, .flags = BUTTON | fl}

#define INPUT4(fo, r, a, fl) {.frameOffset = fo, .radius = r, .angle = a, .flags = STICK | fl}

#define INPUT5(fo, b, r, a, fl) {.frameOffset = fo, .button = b, .radius = r, .angle = a, .flags = BUTTON | STICK | fl}

/** controller inputs */
#define JUMP(frame, flags)              INPUT(frame, 'X', flags)

#define NEUTRAL_B(frame, flags)         INPUT(frame, 'B', flags)

#define SET_STICK(frame, rad, ang, flags)   INPUT(frame, rad, ang, flags)

#define RELEASE_BUTTONS(frame, flags)   INPUT(frame, 0, flags)

#define RELEASE_STICK(frame, flags)     INPUT(frame, 0.0, 0.0, flags)

/** moves */

/**
 * @brief Short Hop Neutral B.
 */
extern const Input shNeutralB[5];
#define SH_LASER shNeutralB

#endif