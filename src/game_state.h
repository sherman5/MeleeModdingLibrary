/**
 * @file game_state.h
 * @brief Track the state of in game variables.
 *
 */

#ifndef MML_GAME_STATE_H
#define MML_GAME_STATE_H

#include "gctypes.h"
#include "math.h"

typedef enum
{
    YOSHIS = 0x06,
    FOUNTAIN = 0x08,
    STADIUM = 0x12,
    BATTLEFIELD = 0x18,
    FINAL = 0x19,
    DREAMLAND = 0x1a

} StageName;

typedef struct
{
    float height;
    float left;
    float right;

} Platform;

#define DEFAULT_PLATFORM {0.0, 0.0, 0.0}

typedef struct
{
    StageName name;
    float ledge;
    Platform side;
    Platform top;

} Stage;

#define DEFAULT_STAGE {0, 0.0, DEFAULT_PLATFORM, DEFAULT_PLATFORM}

typedef struct
{
    char pad1[0x10];
    u32 actionState;

    char pad2[0x2c - 0x10 - sizeof(u32)];
    float facingDirection;

    char pad3[0xb0 - 0x2c - sizeof(float)];
    Point coordinates;

    char pad4[0xc8 - 0xb0 - sizeof(Point)];
    Point deltaCoordinates;

    char pad5[0xe3 - 0xc8 - sizeof(Point)];
    bool inAir;

    char pad6[0x148 - 0xe3 - sizeof(bool)];
    float jumpSquat;

    char pad7[0x1830 - 0xe3 - sizeof(float)];
    float percent;

    char pad8[0x1848 - 0x1830 - sizeof(float)];
    u32 knockbackAngle;

    char pad9[0x195c - 0x1848 - sizeof(u32)];
    float hitlag;

    char pad10[0x1968 - 0x195c - sizeof(float)];
    u8 jumpsUsed;

    char pad11[0x1998 - 0x1968 - sizeof(u8)];
    float shieldSize;
    
    char pad12[0x1a9b - 0x1998 - sizeof(float)];
    u8 aiLevel;

    char pad13[0x2340 - 0x1a9b - sizeof(u8)];
    float hitstun;

} PlayerData;

typedef struct
{
    PlayerData* playerData[5];
    Stage stage;

} GameState;

#define DEFAULT_GAMESTATE {{0, 0, 0, 0, 0}, DEFAULT_STAGE}

extern GameState gameState;

bool inGame();
void updateGameState();
PlayerData* playerData(unsigned id);

#ifdef PAL

#else
    
    #define PLAYER_BLOCK(x) (0x804521F0 + 0xE90 * (x))
    #define CHAR_SELECT(x)  (*((u8*) (0x803F0DE6 + 0x24 * (x))))

    #define STAGE_ID        (*((u16*) 0x804D6CAD))
    #define CURRENT_FRAME   (*((u32*) 0x80479D60))

#endif

#define PLAYER_STATE(x)     (*((u32*) (PLAYER_BLOCK(x) + 0x00)))
#define SLOT_TYPE(x)        (*((u32*) (PLAYER_BLOCK(x) + 0x08)))
#define STOCKS(x)           (*((u32*) (PLAYER_BLOCK(x) + 0x8e)))

#endif
