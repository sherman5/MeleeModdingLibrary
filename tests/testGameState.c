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

    *((StageName*) 0x80001900) = gameState.stage.name;
    *((float*) 0x80001904) = gameState.stage.ledge;
    *((float*) 0x80001908) = gameState.stage.side.left;
    *((float*) 0x8000190c) = gameState.stage.side.right;
    *((float*) 0x80001910) = gameState.stage.side.height;
    *((float*) 0x80001914) = gameState.stage.top.left;
    *((float*) 0x80001918) = gameState.stage.top.right;
    *((float*) 0x8000191c) = gameState.stage.top.height;

    if (PLAYER_STATE(1))
    {
        *((bool*) 0x80001a00) = gameState.playerData[1]->actionState;
        *((float*) 0x80001a04) = gameState.playerData[1]->facingDirection;
        *((float*) 0x80001a08) = gameState.playerData[1]->coordinates.x;
        *((float*) 0x80001a0c) = gameState.playerData[1]->coordinates.y;
        *((float*)0x80001a10) = gameState.playerData[1]->deltaCoordinates.x;
        *((float*)0x80001a14) = gameState.playerData[1]->deltaCoordinates.y;
        *((bool*) 0x80001a18) = gameState.playerData[1]->inAir;
        *((float*) 0x80001a1c) = gameState.playerData[1]->percent;
        *((uint32_t*) 0x80001a20) = gameState.playerData[1]->knockbackAngle;
        *((float*) 0x80001a24) = gameState.playerData[1]->hitlag;
        *((uint8_t*) 0x80001a28) = gameState.playerData[1]->jumpsUsed;
        *((float*) 0x80001a2c) = gameState.playerData[1]->shieldSize;
        *((float*) 0x80001a30) = gameState.playerData[1]->aiLevel;
        *((float*) 0x80001a34) = gameState.playerData[1]->hitstun;

        *((uint32_t*) 0x80001a38) = PLAYER_STATE(1);
        *((uint32_t*) 0x80001a3c) = SLOT_TYPE(1);
        *((uint32_t*) 0x80001a40) = STOCKS(1);
    }

    if (PLAYER_STATE(2))
    {
        *((bool*) 0x80001b00) = gameState.playerData[2]->actionState;
        *((float*) 0x80001b04) = gameState.playerData[2]->facingDirection;
        *((float*) 0x80001b08) = gameState.playerData[2]->coordinates.x;
        *((float*) 0x80001b0c) = gameState.playerData[2]->coordinates.y;
        *((float*)0x80001b10) = gameState.playerData[2]->deltaCoordinates.x;
        *((float*)0x80001b14) = gameState.playerData[2]->deltaCoordinates.y;
        *((bool*) 0x80001b18) = gameState.playerData[2]->inAir;
        *((float*) 0x80001b1c) = gameState.playerData[2]->percent;
        *((uint32_t*) 0x80001b20) = gameState.playerData[2]->knockbackAngle;
        *((float*) 0x80001b24) = gameState.playerData[2]->hitlag;
        *((uint8_t*) 0x80001b28) = gameState.playerData[2]->jumpsUsed;
        *((float*) 0x80001b2c) = gameState.playerData[2]->shieldSize;
        *((uint8_t*) 0x80001b30) = (gameState.playerData[2]->aiLevel == 8);
        *((float*) 0x80001b34) = gameState.playerData[2]->hitstun;

        *((uint32_t*) 0x80001b38) = PLAYER_STATE(2);
        *((uint32_t*) 0x80001b3c) = SLOT_TYPE(2);
        *((uint32_t*) 0x80001b40) = STOCKS(2);
    }

    if (PLAYER_STATE(3))
    {
        *((bool*) 0x80001c00) = gameState.playerData[3]->actionState;
        *((float*) 0x80001c04) = gameState.playerData[3]->facingDirection;
        *((float*) 0x80001c08) = gameState.playerData[3]->coordinates.x;
        *((float*) 0x80001c0c) = gameState.playerData[3]->coordinates.y;
        *((float*)0x80001c10) = gameState.playerData[3]->deltaCoordinates.x;
        *((float*)0x80001c14) = gameState.playerData[3]->deltaCoordinates.y;
        *((bool*) 0x80001c18) = gameState.playerData[3]->inAir;
        *((float*) 0x80001c1c) = gameState.playerData[3]->percent;
        *((uint32_t*) 0x80001c20) = gameState.playerData[3]->knockbackAngle;
        *((float*) 0x80001c24) = gameState.playerData[3]->hitlag;
        *((uint8_t*) 0x80001c28) = gameState.playerData[3]->jumpsUsed;
        *((float*) 0x80001c2c) = gameState.playerData[3]->shieldSize;
        *((float*) 0x80001c30) = gameState.playerData[3]->aiLevel;
        *((float*) 0x80001c34) = gameState.playerData[3]->hitstun;

        *((uint32_t*) 0x80001c38) = PLAYER_STATE(3);
        *((uint32_t*) 0x80001c3c) = SLOT_TYPE(3);
        *((uint32_t*) 0x80001c40) = STOCKS(3);
    }

    if (PLAYER_STATE(4))
    {
        *((bool*) 0x80001d00) = gameState.playerData[4]->actionState;
        *((float*) 0x80001d04) = gameState.playerData[4]->facingDirection;
        *((float*) 0x80001d08) = gameState.playerData[4]->coordinates.x;
        *((float*) 0x80001d0c) = gameState.playerData[4]->coordinates.y;
        *((float*)0x80001d10) = gameState.playerData[4]->deltaCoordinates.x;
        *((float*)0x80001d14) = gameState.playerData[4]->deltaCoordinates.y;
        *((bool*) 0x80001d18) = gameState.playerData[4]->inAir;
        *((float*) 0x80001d1c) = gameState.playerData[4]->percent;
        *((uint32_t*) 0x80001d20) = gameState.playerData[4]->knockbackAngle;
        *((float*) 0x80001d24) = gameState.playerData[4]->hitlag;
        *((uint8_t*) 0x80001d28) = gameState.playerData[4]->jumpsUsed;
        *((float*) 0x80001d2c) = gameState.playerData[4]->shieldSize;
        *((float*) 0x80001d30) = gameState.playerData[4]->aiLevel;
        *((float*) 0x80001d34) = gameState.playerData[4]->hitstun;

        *((uint32_t*) 0x80001d38) = PLAYER_STATE(4);
        *((uint32_t*) 0x80001d3c) = SLOT_TYPE(4);
        *((uint32_t*) 0x80001d40) = STOCKS(4);
    }

}


