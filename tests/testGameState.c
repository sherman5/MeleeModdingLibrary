#include <unit_test.h>
#include <system.h>
#include <math.h>
#include <string.h>
#include <game_state.h>
#include <gctypes.h>

UNIT_TEST;

static bool init = false;
static char heap[15000];

static int tests_run = 0;

void _init(void)
{
    initHeap(heap, heap + sizeof(heap));
    *((uint32_t*) 0x80001804) = 0;
    *((uint32_t*) 0x80001808) = 0;
    *((uint32_t*) 0x80001a30) = 0;
}

#define ACTION_STATE(p)     (_gameState.playerData[p]->actionState)
#define FACING(p)           (_gameState.playerData[p]->facingDirection)
#define X_COORD(p)          (_gameState.playerData[p]->coordinates.x)
#define Y_COORD(p)          (_gameState.playerData[p]->coordinates.y)
#define DELTA_X(p)          (_gameState.playerData[p]->deltaCoordinates.x)
#define DELTA_Y(p)          (_gameState.playerData[p]->deltaCoordinates.y)
#define IN_AIR(p)           (_gameState.playerData[p]->inAir)
#define PERCENT(p)          (_gameState.playerData[p]->percent)
#define KNOCKBACK_ANGLE(p)  (_gameState.playerData[p]->knockbackAngle)
#define HITLAG(p)           (_gameState.playerData[p]->hitlag)
#define JUMPS_USED(p)       (_gameState.playerData[p]->jumpsUsed)
#define SHIELD_SIZE(p)      (_gameState.playerData[p]->shieldSize)
#define AI_LEVEL(p)         (_gameState.playerData[p]->aiLevel)
#define HITSTUN(p)          (_gameState.playerData[p]->hitstun)
#define JUMP_SQUAT(p)       (_gameState.playerData[p]->jumpSquat)
#define DAM_DIRECTION(p)    (_gameState.playerData[p]->damageDirection)
#define BREAKOUT(p)         (_gameState.playerData[p]->breakoutCountdown)

void _main(void)
{
    if (!init) { _init(); init = true;}

    updateGameState();

    *((bool*) 0x80001800) = inGame();
    *((uint32_t*) 0x80001804) = CURRENT_FRAME;
    *((uint8_t*) 0x80001808) = CHAR_SELECT(1);
    *((uint8_t*) 0x8000180c) = CHAR_SELECT(2);
    *((uint8_t*) 0x80001810) = CHAR_SELECT(3);
    *((uint8_t*) 0x80001814) = CHAR_SELECT(4);

    *((StageName*) 0x80001900) = _gameState.stage.name;
    *((float*) 0x80001904) = _gameState.stage.ledge;
    *((float*) 0x80001908) = _gameState.stage.side.left;
    *((float*) 0x8000190c) = _gameState.stage.side.right;
    *((float*) 0x80001910) = _gameState.stage.side.height;
    *((float*) 0x80001914) = _gameState.stage.top.left;
    *((float*) 0x80001918) = _gameState.stage.top.right;
    *((float*) 0x8000191c) = _gameState.stage.top.height;

    if (PLAYER_STATE(1))
    {
        *((bool*)  0x80001a00) = ACTION_STATE(1);
        *((float*) 0x80001a04) = FACING(1);
        *((float*) 0x80001a08) = X_COORD(1);
        *((float*) 0x80001a0c) = Y_COORD(1);
        *((float*) 0x80001a10) = DELTA_X(1);
        *((float*) 0x80001a14) = DELTA_Y(1);
        *((bool*)  0x80001a18) = IN_AIR(1);
        *((float*) 0x80001a1c) = PERCENT(1);
        *((u32*)   0x80001a20) = KNOCKBACK_ANGLE(1);
        *((float*) 0x80001a24) = HITLAG(1);
        *((u8*)    0x80001a28) = JUMPS_USED(1);
        *((float*) 0x80001a2c) = SHIELD_SIZE(1);
        *((float*) 0x80001a30) = AI_LEVEL(1);
        *((float*) 0x80001a34) = JUMP_SQUAT(1);
        *((float*) 0x80001a38) = DAM_DIRECTION(1);
        *((float*) 0x80001a3c) = BREAKOUT(1);
        *((u32*)   0x80001a40) = PLAYER_STATE(1);
        *((u32*)   0x80001a44) = SLOT_TYPE(1);
        *((u32*)   0x80001a48) = STOCKS(1);
    }

    if (PLAYER_STATE(2))
    {
        *((bool*)  0x80001b00) = ACTION_STATE(2);
        *((float*) 0x80001b04) = FACING(2);
        *((float*) 0x80001b08) = X_COORD(2);
        *((float*) 0x80001b0c) = Y_COORD(2);
        *((float*) 0x80001b10) = DELTA_X(2);
        *((float*) 0x80001b14) = DELTA_Y(2);
        *((bool*)  0x80001b18) = IN_AIR(2);
        *((float*) 0x80001b1c) = PERCENT(2);
        *((u32*)   0x80001b20) = KNOCKBACK_ANGLE(2);
        *((float*) 0x80001b24) = HITLAG(2);
        *((u8*)    0x80001b28) = JUMPS_USED(2);
        *((float*) 0x80001b2c) = SHIELD_SIZE(2);
        *((float*) 0x80001b30) = AI_LEVEL(2);
        *((float*) 0x80001b34) = JUMP_SQUAT(2);
        *((float*) 0x80001b38) = DAM_DIRECTION(2);
        *((float*) 0x80001b3c) = BREAKOUT(2);
        *((u32*)   0x80001b40) = PLAYER_STATE(2);
        *((u32*)   0x80001b44) = SLOT_TYPE(2);
        *((u32*)   0x80001b44) = STOCKS(2);
    }

    if (PLAYER_STATE(3))
    {
        *((bool*)  0x80001c00) = ACTION_STATE(3);
        *((float*) 0x80001c04) = FACING(3);
        *((float*) 0x80001c08) = X_COORD(3);
        *((float*) 0x80001c0c) = Y_COORD(3);
        *((float*) 0x80001c10) = DELTA_X(3);
        *((float*) 0x80001c14) = DELTA_Y(3);
        *((bool*)  0x80001c18) = IN_AIR(3);
        *((float*) 0x80001c1c) = PERCENT(3);
        *((u32*)   0x80001c20) = KNOCKBACK_ANGLE(3);
        *((float*) 0x80001c24) = HITLAG(3);
        *((u8*)    0x80001c28) = JUMPS_USED(3);
        *((float*) 0x80001c2c) = SHIELD_SIZE(3);
        *((float*) 0x80001c30) = AI_LEVEL(3);
        *((float*) 0x80001c34) = JUMP_SQUAT(3);
        *((float*) 0x80001c38) = DAM_DIRECTION(3);
        *((float*) 0x80001c3c) = BREAKOUT(3);
        *((u32*)   0x80001c40) = PLAYER_STATE(3);
        *((u32*)   0x80001c44) = SLOT_TYPE(3);
        *((u32*)   0x80001c44) = STOCKS(3);
    }

    if (PLAYER_STATE(4))
    {
        *((bool*)  0x80001d00) = ACTION_STATE(4);
        *((float*) 0x80001d04) = FACING(4);
        *((float*) 0x80001d08) = X_COORD(4);
        *((float*) 0x80001d0c) = Y_COORD(4);
        *((float*) 0x80001d10) = DELTA_X(4);
        *((float*) 0x80001d14) = DELTA_Y(4);
        *((bool*)  0x80001d18) = IN_AIR(4);
        *((float*) 0x80001d1c) = PERCENT(4);
        *((u32*)   0x80001d20) = KNOCKBACK_ANGLE(4);
        *((float*) 0x80001d24) = HITLAG(4);
        *((u8*)    0x80001d28) = JUMPS_USED(4);
        *((float*) 0x80001d2c) = SHIELD_SIZE(4);
        *((float*) 0x80001d30) = AI_LEVEL(4);
        *((float*) 0x80001d34) = JUMP_SQUAT(4);
        *((float*) 0x80001d38) = DAM_DIRECTION(4);
        *((float*) 0x80001d3c) = BREAKOUT(4);
        *((u32*)   0x80001d40) = PLAYER_STATE(4);
        *((u32*)   0x80001d44) = SLOT_TYPE(4);
        *((u32*)   0x80001d48) = STOCKS(4);
    }

}


