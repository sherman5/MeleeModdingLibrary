#ifndef MELEE_102_H
#define MELEE_102_H

#include <stdint.h>

/* function addreses */

/** address of the sin() function in Melee v102 */
#define SINE_ADDRESS 0x80326220

/** address of the cos() function in Melee v102 */
#define COSINE_ADDRESS 0x80326200

/** address of the tan() function in Melee v102 */
#define TANGENT_ADDRESS  0x803261bc

/** address of the fabs() function in Melee v102 */
#define ABS_VAL_ADDRESS 0x803261b4

/* macro functions for handling raw address values */

#define UINT_PTR(x) ((uint32_t*) (x))
#define DREF_UINT(x) (*UINT_PTR(x))

#define INT_PTR(x) ((int32_t*) (x))
#define DREF_INT(x) (*INT_PTR(x))

#define FLT_PTR(x) ((float*) (x))
#define DREF_FLT(x) (*FLT_PTR(x))

/* player information */

#define PLAYER_BLOCK(x)     (0x804521F0 + 0xE90 * x)

#define P1_BLOCK    0x80453080
#define P2_BLOCK    0x80453F10
#define P3_BLOCK    0x80454DA0
#define P4_BLOCK    0x80455C30

#define PLAYER_ENTITY(x)    DREF_UINT(PLAYER_BLOCK(x) + 0xB0)

#define P1_ENTITY   DREF_UINT(0x80453130)
#define P2_ENTITY   DREF_UINT(0x80453FC0)
#define P3_ENTITY   DREF_UINT(0x80454E50)
#define P4_ENTITY   DREF_UINT(0x80455CE0)

#define PLAYER_DATA(x)      DREF_UINT(PLAYER_ENTITY(x) + 0x2C)

#define P1_DATA     DREF_UINT(P1_ENTITY + 0x2C)
#define P2_DATA     DREF_UINT(P2_ENTITY + 0x2C)
#define P3_DATA     DREF_UINT(P3_ENTITY + 0x2C)
#define P4_DATA     DREF_UINT(P4_ENTITY + 0x2C)

/* remaining stocks */

#define PLAYER_STOCKS(x)    DREF_UINT(PLAYER_BLOCK(x) + 0x8E)

#define P1_STOCKS   DREF_UINT(0x8045310E)
#define P2_STOCKS   DREF_UINT(0x80453F9E)
#define P3_STOCKS   DREF_UINT(0x80454E2E)
#define P4_STOCKS   DREF_UINT(0x80455CBE)

/* current damage percent */

#define PLAYER_PERCENT(x)   DREF_UINT(PLAYER_BLOCK(x) + 0x60)

#define P1_PERCENT       DREF_PTR(0x804530E0)
#define P2_PERCENT       DREF_PTR(0x80453F70)
#define P3_PERCENT       DREF_PTR(0x80454E00)
#define P4_PERCENT       DREF_PTR(0x80455C90)

/* character select */

#define PLAYER_CHAR(x)  (DREF_PTR(0x803F0DE4 + 0x24 * x) & 0x000000FF)

#define P1_CHAR     (DREF_PTR(0x803F0E08) & 0x000000FF)
#define P2_CHAR     (DREF_PTR(0x803F0E2C) & 0x000000FF)
#define P3_CHAR     (DREF_PTR(0x803F0E50) & 0x000000FF)
#define P4_CHAR     (DREF_PTR(0x803F0E74) & 0x000000FF)

/* character codes */

#define FALCO 0x09

/* player type (0x00 - human, 0x01 - cpu, 0x02 - demo) */

#define PLAYER_TYPE(x)      DREF_PTR(PLAYER_BLOCK(x) + 0x08)

#define P1_TYPE     DREF_PTR(0x80453088)
#define P2_TYPE     DREF_PTR(0x80453F18)
#define P3_TYPE     DREF_PTR(0x80454DA8)
#define P4_TYPE     DREF_PTR(0x80455C38)

/* player action state */

#define PLAYER_ACTION_STATE(x)  DREF_PTR(PLAYER_DATA(x) + 0x10)

#define P1_ACTION_STATE     DREF_PTR(P1_DATA + 0x10)
#define P2_ACTION_STATE     DREF_PTR(P2_DATA + 0x10)
#define P3_ACTION_STATE     DREF_PTR(P3_DATA + 0x10)
#define P4_ACTION_STATE     DREF_PTR(P4_DATA + 0x10)

/* direction player is facing */

#define PLAYER_DIRECTION(x)     DREF_PTR(PLAYER_DATA(x) + 0x30)

#define P1_DIRECTION    DREF_PTR(P1_DATA + 0x30)
#define P2_DIRECTION    DREF_PTR(P2_DATA + 0x30)
#define P3_DIRECTION    DREF_PTR(P3_DATA + 0x30)
#define P4_DIRECTION    DREF_PTR(P4_DATA + 0x30)

/* player coordinates */

#define PLAYER_X(x) DREF_FLT(PLAYER_DATA(x) + 0xB0)
#define PLAYER_Y(x) DREF_FLT(PLAYER_DATA(x) + 0xB4)

#define P1_X    DREF_FLT(P1_DATA + 0xB0)
#define P1_Y    DREF_FLT(P1_DATA + 0xB4)
#define P2_X    DREF_FLT(P2_DATA + 0xB0)
#define P2_Y    DREF_FLT(P2_DATA + 0xB4)
#define P3_X    DREF_FLT(P3_DATA + 0xB0)
#define P3_Y    DREF_FLT(P3_DATA + 0xB4)
#define P4_X    DREF_FLT(P4_DATA + 0xB0)
#define P4_Y    DREF_FLT(P4_DATA + 0xB4)

/* hitlag frames remaining */

#define PLAYER_HITLAG(x)    DREF_PTR(PLAYER_DATA(x) + 0x195C)

#define P1_HITLAG   DREF_PTR(P1_DATA + 0x195C)
#define P2_HITLAG   DREF_PTR(P2_DATA + 0x195C)
#define P3_HITLAG   DREF_PTR(P3_DATA + 0x195C)
#define P4_HITLAG   DREF_PTR(P4_DATA + 0x195C)

/* hitstun frames remaining */

#define PLAYER_HITSTUN(x)    DREF_FLT(PLAYER_DATA(x) + 0x2340)

#define P1_HITSTUN   DREF_PTR(P1_DATA + 0x2340)
#define P2_HITSTUN   DREF_PTR(P2_DATA + 0x2340)
#define P3_HITSTUN   DREF_PTR(P3_DATA + 0x2340)
#define P4_HITSTUN   DREF_PTR(P4_DATA + 0x2340)

/* jumps used */

#define PLAYER_JUMPS_USED(x)    (DREF_PTR(PLAYER_DATA(x) + 0x1968) >> 24)

#define P1_JUMPS_USED   (DREF_PTR(P1_DATA + 0x1968) >> 24)
#define P2_JUMPS_USED   (DREF_PTR(P2_DATA + 0x1968) >> 24)
#define P3_JUMPS_USED   (DREF_PTR(P3_DATA + 0x1968) >> 24)
#define P4_JUMPS_USED   (DREF_PTR(P4_DATA + 0x1968) >> 24)

/* shield size */

#define PLAYER_SHIELD(x)    DREF_PTR(PLAYER_DATA(x) + 0x1998)

#define P1_SHIELD   DREF_PTR(P1_DATA + 0x1998)
#define P2_SHIELD   DREF_PTR(P2_DATA + 0x1998)
#define P3_SHIELD   DREF_PTR(P3_DATA + 0x1998)
#define P4_SHIELD   DREF_PTR(P4_DATA + 0x1998)

/* whether or not player is in air */

#define PLAYER_IN_AIR(x)    DREF_UINT(PLAYER_DATA(x) + 0xE0)

#define P1_IN_AIR   DREF_PTR(P1_DATA + 0xE0)
#define P2_IN_AIR   DREF_PTR(P2_DATA + 0xE0)
#define P3_IN_AIR   DREF_PTR(P3_DATA + 0xE0)
#define P4_IN_AIR   DREF_PTR(P4_DATA + 0xE0)

/* vertical "velocity" (change in Y coordinate) */

#define PLAYER_DELTA_Y(x)   DREF_PTR(PLAYER_DATA(x) + 0xCC)

#define P1_DELTA_Y  DREF_PTR(P1_DATA + 0xCC)
#define P2_DELTA_Y  DREF_PTR(P2_DATA + 0xCC)
#define P3_DELTA_Y  DREF_PTR(P3_DATA + 0xCC)
#define P4_DELTA_Y  DREF_PTR(P4_DATA + 0xCC)

/* game information */

#define STAGE_ID          (DREF_PTR(0x804D6CAC) >> 8)
#define CURRENT_FRAME     DREF_PTR(0x80479D60)
#define IN_GAME           (((DREF_PTR(0x8065CC14) >> 20) & 0x0F) == 0x0D)

#endif
