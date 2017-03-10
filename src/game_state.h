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

/** @cond */
#define PAD(name, addr, prev, prev_type) char pad_ ## name[addr - prev - sizeof(prev_type)]
/** @endcond */

/** @brief struct holding player data */
typedef struct
{
    /**@cond */char pad_actionState[0x10];/**@endcond */
    u32 actionState; /**< current action state of player */

    /**@cond */PAD(facingDirection, 0x2c, 0x10, u32);/**@endcond */
    float facingDirection; /**< -1 facing left, 1 facing right */

    /**@cond */PAD(playerSpeed, 0x80, 0x2c, float);/**@endcond */
    float xSpeedSelfAir;
    float ySpeedSelf;
    float zSpeedSelf;
    float xSpeedAttack;
    float ySpeedAttack;
    float zSpeedAttack;

    /**@cond */PAD(coordinates, 0xb0, 0x94, float);/**@endcond */
    Point coordinates;
    float zPosition;
    Point prevCoordinates;
    float zPrevious;
    Point deltaCoordinates;
    float zDelta;
    
    /**@cond */PAD(inAir, 0xe0, 0xd0, float);/**@endcond */
    bool inAir; /**< true if player is in air */

    /**@cond */PAD(xSpeedSelfGround, 0xec, 0xe0, bool);/**@endcond */
    float xSpeedSelfGround;
    
    /**@cond */PAD(attributes1, 0x110, 0xec, float);/**@endcond */
    float walkInitialVelocity;
    float walkAcceleration;
    float walkMaximumVelocity;
    float slowWalkMax;
    float midWalkPoint;
    float fastWalkMin;
    float groundFriction;
    float dashInitialVelocity;
    float dashAccelerationA;
    float dashAcceleationB;
    float dashTerminalVelocity;
    float runAnimationScaling;
    float runAcceleration;
    float groundedMaxHorizontalVelocity;
    float jumpSquat;
    float jumpHorizontalInitialVelocity;
    float jumpVerticalInitialVelocity;
    float groundToAirJumpMomentum;
    float jumpHorizontalMaxVelocity;
    float hopVerticalInitialVelocity;
    float airJumpVerticalMultiplier;
    float airJumpHorizontalMultiplier;
    float numberOfJumps;
    float gravity;
    float terminalVelocity;
    float airMobilityA;
    float airMobilityB;
    float maxHorizontalAirMobility;
    float horizontalAirFriction;
    float fastfallVelocity;
    
    /**@cond */PAD(attributes2, 0x18c, 0x184, float);/**@endcond */
    float jab2inputWindow;
    float jab3inputWindow;
    float framesToChangeDirection;
    float weight;
    float modelScaling;
    float maxShieldSize;
    float shieldBreakInitialVelocity;
    float rapidJabWindow;

    /**@cond */PAD(attributes3, 0x1f4, 0x1a8, float);/**@endcond */    
    float normalLandingLag;
    float nairLandingLag;
    float fairLandingLag;
    float bairLandingLag;
    float uairLandingLag;
    float dairLandingLag;

    /**@cond */PAD(attributes4, 0x214, 0x208, float);/**@endcond */    
    float wallJumpHorizontalVelocity;
    float wallJumpVerticalVelocity;

    /**@cond */PAD(analogStick, 0x620, 0x218, float);/**@endcond */    
    float analogStickX;
    float analogStickY;
    float prevAnalogStickX;
    float prevAnalogStickY;
    
    /**@cond */PAD(cStick, 0x638, 0x62c, float);/**@endcond */    
    float cStickX; /** -1.0 to 1.0 */
    float cStickY; /**< -1.0 to 1.0 */

    /**@cond */PAD(controller, 0x650, 0x63c, float);/**@endcond */    
    float analogTriggerData;
    u32 digitalButtonData;
    u32 prevDigitalButtonData;

    /**@cond */PAD(lastPosition, 0x830, 0x660, u32);/**@endcond */    
    float lastPosition; /**< last position player landed at */

    /**@cond */PAD(platformID, 0x83f, 0x830, float);/**@endcond */    
    u8 platformID;

    /**@cond */PAD(stageRelation, 0x842, 0x83f, u8);/**@endcond */    
    u8 stageRelationID;
    u8 stageTransformationID;

    /**@cond */PAD(actionFrame, 0x894, 0x843, u8);/**@endcond */    
    float actionFrame; /**< resets to 1 with each new action state */

    /**@cond */PAD(percent, 0x1830, 0x894, float);/**@endcond */    
    float percent; /**< percent of player */

    /**@cond */PAD(damage, 0x1838, 0x1830, float);/**@endcond */    
    float percentForDamageCalc; /**< percent for damage calculation */
    u32 damageApplied; /**< percentForDamageCalc cast to int */
    
    /**@cond */PAD(knockback, 0x1844, 0x183c, u32);/**@endcond */    
    float damageDirection; /**< -1, 1 depending on direction sent */
    u32 knockbackAngle; /**< angle of knockback [0, 360], 361 = sakurai */

    /**@cond */PAD(forceApplied, 0x1850, 0x1848, u32);/**@endcond */    
    float forceApplied;

    /**@cond */PAD(hitlag, 0x195c, 0x1850, float);/**@endcond */    
    float hitlag; /**< remaining frames of hitlag */

    /**@cond */PAD(jumpsUsed, 0x1968, 0x195c, float);/**@endcond */    
    u8 jumpsUsed; /**< number of jumps already used */

    /**@cond */PAD(bodyState, 0x198c, 0x1968, u8);/**@endcond */    
    u32 bodyState; /**< 0 - normal, 1 - invulnerable, 2 - intangible */
    float ledgeInvincibility;
    float haloInvincinility;
    float shieldSize; /**< size of shield */
    float lightshieldAmount; /**< 1 = hard shield, 0.071429 = z-shield */  

    /**@cond */PAD(breakout, 0x1a4c, 0x199c, float);/**@endcond */    
    float breakoutCountdown; /**< frames until breakout of grab */

    /**@cond */PAD(aiType, 0x1a97, 0x1a4c, float);/**@endcond */
    u8 aiType;

    /**@cond */PAD(aiLevel, 0x1a9b, 0x1a97, u8);/**@endcond */        
    u8 aiLevel; /**< cpu level selected on CSS */

    /**@cond */PAD(actionCounter, 0x206c, 0x1a9b, u8);/**@endcond */        
    u32 actionCounter; /**< number of action states this match */

    /**@cond */PAD(comboCount, 0x2090, 0x206c, u32);/**@endcond */        
    u16 comboCount;

    /**@cond */PAD(wallride, 0x210C, 0x2090, u16);/**@endcond */        
    u8 wallrideCounter;

    /**@cond */PAD(wallAndSmash, 0x2110, 0x2090, u8);/**@endcond */        
    float wallLocation;
    u32 smashAttackState;
    u32 smashChargeFrame;
    float smashChargeFrameMax;
    float smashChargeStrength;

    /**@cond */PAD(walljump, 0x2224, 0x2120, float);/**@endcond */        
    u8 canWallJump;

    /**@cond */PAD(hitstun, 0x2340, 2224, u8);/**@endcond */        
    float hitstun; /**< remaining frames of hitstun */

} PlayerData;

/** @brief Variables in static player block */
typedef struct
{
    u32 playerState;
    u32 playerCharacter;
    u32 slotType;
    u16 transformed;

    /**@cond */PAD(costumeID, 0x44, 0x0c, u16);/**@endcond */        
    u8 costumeID;
    u8 controllerIndex;
    u8 subcolorID;
    u8 teamID;
    u8 playerID;
    
    /**@cond */PAD(falls, 0x68, 0x48, u8);/**@endcond */        
    u32 deaths;
    u32 nanaDeaths;
    u32 p1Kills;
    u32 p2Kills;
    u32 p3Kills;
    u32 p4Kills;
    u32 p5Kills;
    u32 p6Kills;

    /**@cond */PAD(selfDeaths, 0x8d, 0x84, u32);/**@endcond */        
    u8 selfDeaths;
    u8 stocks;

} PlayerBlock;

/** @brief In game variables */
typedef struct
{
    PlayerData* playerData[5]; /**< pointer to player's data */
    PlayerBlock* playerBlock[5]; /**< pointer to player's static block */
    Stage stage; /**< Stage Information */

} GameState;

/** Default GameState Value */
#define DEFAULT_GAMESTATE {{0, 0, 0, 0, 0}, {0, 0, 0, 0, 0}, DEFAULT_STAGE}

// Global GameState Variables 

#ifdef PAL

    #error game_state.h not compatible with PAL

#else
    
    /** Character Selection of each player (1-4) */
    #define CHAR_SELECT(x)  (*((u8*) (0x803F0DE6 + 0x24 * (x))))

    /** Stage ID */
    #define STAGE_ID        (*((u16*) 0x804D6CAD))

    /** Current Frame (32-bit) */
    #define CURRENT_FRAME   (*((u32*) 0x80479D60))

    //TODO: REMOVE
    #define PLAYER_BLOCK(x)     ((u32) _gameState.playerBlock[(x)])
    #define PLAYER_STATE(x)     _gameState.playerBlock[(x)]->playerState
    #define SLOT_TYPE(x)        _gameState.playerBlock[(x)]->slotType
    #define STOCKS(x)           _gameState.playerBlock[(x)]->stocks

#endif

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

#endif
