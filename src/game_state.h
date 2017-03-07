/**
 * @file game_state.h
 * @brief Track the state of in game variables.
 *
 */

#ifndef MML_GAME_STATE_H
#define MML_GAME_STATE_H

#include "gctypes.h"
#include "math.h"
#include "action_state.h"

/** Name of Stage and Internal ID */
typedef enum
{
    YOSHIS = 0x06, /**< Yoshi's Story */
    FOUNTAIN = 0x08, /**< Fountain of Dreams */
    STADIUM = 0x12, /**< Pokemon Stadium */
    BATTLEFIELD = 0x18, /**< Battlefield */
    FINAL = 0x19, /**< Final Destination */
    DREAMLAND = 0x1a /**< Dreamland */

} StageName;

/** @brief Platform information */
typedef struct
{
    float height; /**< y-coordinate of character standing on platform */
    float left; /**< |x-coordinate| of character at left edge */
    float right; /**< |y-coordinate| of character at right edge */

} Platform;

/** Default Platform Value */
#define DEFAULT_PLATFORM {0.0, 0.0, 0.0}

/** @brief Stage Information */
typedef struct
{
    StageName name; /**< Name of Stage */
    Point ledge; /**< coordinates of right ledge of stage */
    Platform side; /**< side platform */
    Platform top; /**< top platform */

} Stage;

/** Default Stage Value */
#define DEFAULT_STAGE {0, {0.f, 0.f}, DEFAULT_PLATFORM, DEFAULT_PLATFORM}

/** @brief struct holding player data */
typedef struct
{
    /** @cond */char pad1[0x10];/** @endcond */
    u32 actionState; /**< current action state of player */

    /** @cond */char pad2[0x2c - 0x10 - sizeof(u32)];/** @endcond */
    float facingDirection; /**< -1 facing left, 1 facing right */

    /** @cond */char pad3[0xb0 - 0x2c - sizeof(float)];/** @endcond */
    Point coordinates; /**< coordinates of player */

    /** @cond */char pad4[0xc8 - 0xb0 - sizeof(Point)];/** @endcond */
    Point deltaCoordinates; /**< change in coordinates from last frame */

    /** @cond */char pad5[0xe0 - 0xc8 - sizeof(Point)];/** @endcond */
    bool inAir; /**< true if player is in air */

    /** @cond */char pad6[0x148 - 0xe0 - sizeof(bool)];/** @endcond */
    float jumpSquat; /**< frames of jumpsquat */

    /** @cond */char pad7[0x1830 - 0x148 - sizeof(float)];/** @endcond */
    float percent; /**< percent of player */

    /** @cond */char pad8[0x1844 - 0x1830 - sizeof(float)];/** @endcond */
    float damageDirection; /**< -1, 1 depending on direction sent */
    u32 knockbackAngle; /**< angle of knockback [0, 360], 361 = sakurai */

    /** @cond */char pad10[0x195c - 0x1848 - sizeof(u32)];/** @endcond */
    float hitlag; /**< remaining frames of hitlag */

    /** @cond */char pad11[0x1968 - 0x195c - sizeof(float)];/** @endcond */
    u8 jumpsUsed; /**< number of jumps already used */

    /** @cond */char pad12[0x1998 - 0x1968 - sizeof(u8)];/** @endcond */
    float shieldSize; /**< size of shield */
    
    /** @cond */char pad13[0x1a4c - 0x1998 - sizeof(float)];/** @endcond */
    float breakoutCountdown; /**< frames until breakout of grab */

    /** @cond */char pad14[0x1a9b - 0x1a4c - sizeof(float)];/** @endcond */
    u8 aiLevel; /**< cpu level selected on CSS */

    /** @cond */char pad15[0x2340 - 0x1a9b - sizeof(u8)];/** @endcond */
    float hitstun; /**< remaining frames of hitstun */

} PlayerData;

/** @brief In game variables */
typedef struct
{
    PlayerData* playerData[5]; /**< pointer to each player's data */
    Stage stage; /**< Stage Information */

} GameState;

/** Default GameState Value */
#define DEFAULT_GAMESTATE {{0, 0, 0, 0, 0}, DEFAULT_STAGE}

/** global GameState variable */
extern GameState _gameState;

/**
 * Determine if currently playing game
 *
 * @return Returns true if game currently being played 
 */
bool inGame();

/**
 * Update the global GameState variable 
 *
 * @return none
 */
void updateGameState();

/**
 * Branch to this symbol when game ends, never call directly
 * 
 * @return none
 */
void endGame();

/**
 * Get pointer to player's data
 * 
 * @param id - unsigned integer in {1,2,3,4}
 * @return Pointer to PlayerData struct for this player 
 */
PlayerData* playerData(u32 id);

#ifdef PAL

#error game_state.h not compatible with PAL

#else
    
/** Static Player Information */
#define PLAYER_BLOCK(x) (0x804521F0 + 0xE90 * (x))

/** Character Selection of each player (1-4) */
#define CHAR_SELECT(x)  (*((u8*) (0x803F0DE6 + 0x24 * (x))))

/** Stage ID */
#define STAGE_ID        (*((u16*) 0x804D6CAD))

/** Current Frame (32-bit) */
#define CURRENT_FRAME   (*((u32*) 0x80479D60))

#endif

/** State of player: 0x02 = in game, 0x00 = otherwise */
#define PLAYER_STATE(x)     (*((u32*) (PLAYER_BLOCK(x) + 0x00)))

/** Type of player: 0x00 = HUMAN, 0x01 = CPU */
#define SLOT_TYPE(x)        (*((u32*) (PLAYER_BLOCK(x) + 0x08)))

/** Remaining stocks for each player (1-4) */
#define STOCKS(x)           (*((u32*) (PLAYER_BLOCK(x) + 0x8e)))

#endif
