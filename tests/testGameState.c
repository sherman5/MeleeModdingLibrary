#include <unit_test.h>
#include <system.h>
#include <math.h>
#include <string.h>
#include <gamestate.h>
#include <bool.h>

UNIT_TEST;

static bool init = false;
static char heap[21000];

static int tests_run = 0;

void _init(void)
{
    initHeap(heap, heap + sizeof(heap));
    *((uint32_t*) 0x80001804) = 0;
    *((uint32_t*) 0x80001808) = 0;
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

    if (inGame())
    {
        *((bool*) 0x80002000) = gameState.playerData[1]->actionState;
        *((float*) 0x80002004) = gameState.playerData[1]->facingDirection;
        *((float*) 0x80002008) = gameState.playerData[1]->coordinates.x;
        *((float*) 0x8000200c) = gameState.playerData[1]->coordinates.y;
        *((float*)0x80002010) = gameState.playerData[1]->deltaCoordinates.x;
        *((float*)0x80002014) = gameState.playerData[1]->deltaCoordinates.y;
        *((bool*) 0x80002018) = gameState.playerData[1]->inAir;
        *((float*) 0x8000201c) = gameState.playerData[1]->percent;
        *((uint32_t*) 0x80002020) = gameState.playerData[1]->knockbackAngle;
        *((float*) 0x80002024) = gameState.playerData[1]->hitlag;
        *((uint8_t*) 0x80002028) = gameState.playerData[1]->jumpsUsed;
        *((float*) 0x8000202c) = gameState.playerData[1]->shieldSize;
        *((float*) 0x80002030) = gameState.playerData[1]->aiLevel;
        *((float*) 0x80002034) = gameState.playerData[1]->hitstun;

        *((uint32_t*) 0x80002038) = PLAYER_STATE(1);
        *((uint32_t*) 0x8000203c) = SLOT_TYPE(1);
        *((uint32_t*) 0x80002040) = STOCKS(1);

        *((bool*) 0x80002000) = gameState.playerData[2]->actionState;
        *((float*) 0x80002004) = gameState.playerData[2]->facingDirection;
        *((float*) 0x80002008) = gameState.playerData[2]->coordinates.x;
        *((float*) 0x8000200c) = gameState.playerData[2]->coordinates.y;
        *((float*)0x80002010) = gameState.playerData[2]->deltaCoordinates.x;
        *((float*)0x80002014) = gameState.playerData[2]->deltaCoordinates.y;
        *((bool*) 0x80002018) = gameState.playerData[2]->inAir;
        *((float*) 0x8000201c) = gameState.playerData[2]->percent;
        *((uint32_t*) 0x80002020) = gameState.playerData[2]->knockbackAngle;
        *((float*) 0x80002024) = gameState.playerData[2]->hitlag;
        *((uint8_t*) 0x80002028) = gameState.playerData[2]->jumpsUsed;
        *((float*) 0x8000202c) = gameState.playerData[2]->shieldSize;
        *((float*) 0x80002030) = gameState.playerData[2]->aiLevel;
        *((float*) 0x80002034) = gameState.playerData[2]->hitstun;

        *((uint32_t*) 0x80002038) = PLAYER_STATE(2);
        *((uint32_t*) 0x8000203c) = SLOT_TYPE(2);
        *((uint32_t*) 0x80002040) = STOCKS(2);

        *((bool*) 0x80002000) = gameState.playerData[3]->actionState;
        *((float*) 0x80002004) = gameState.playerData[3]->facingDirection;
        *((float*) 0x80002008) = gameState.playerData[3]->coordinates.x;
        *((float*) 0x8000200c) = gameState.playerData[3]->coordinates.y;
        *((float*)0x80002010) = gameState.playerData[3]->deltaCoordinates.x;
        *((float*)0x80002014) = gameState.playerData[3]->deltaCoordinates.y;
        *((bool*) 0x80002018) = gameState.playerData[3]->inAir;
        *((float*) 0x8000201c) = gameState.playerData[3]->percent;
        *((uint32_t*) 0x80002020) = gameState.playerData[3]->knockbackAngle;
        *((float*) 0x80002024) = gameState.playerData[3]->hitlag;
        *((uint8_t*) 0x80002028) = gameState.playerData[3]->jumpsUsed;
        *((float*) 0x8000202c) = gameState.playerData[3]->shieldSize;
        *((float*) 0x80002030) = gameState.playerData[3]->aiLevel;
        *((float*) 0x80002034) = gameState.playerData[3]->hitstun;

        *((uint32_t*) 0x80002038) = PLAYER_STATE(3);
        *((uint32_t*) 0x8000203c) = SLOT_TYPE(3);
        *((uint32_t*) 0x80002040) = STOCKS(3);

        *((bool*) 0x80002000) = gameState.playerData[4]->actionState;
        *((float*) 0x80002004) = gameState.playerData[4]->facingDirection;
        *((float*) 0x80002008) = gameState.playerData[4]->coordinates.x;
        *((float*) 0x8000200c) = gameState.playerData[4]->coordinates.y;
        *((float*)0x80002010) = gameState.playerData[4]->deltaCoordinates.x;
        *((float*)0x80002014) = gameState.playerData[4]->deltaCoordinates.y;
        *((bool*) 0x80002018) = gameState.playerData[4]->inAir;
        *((float*) 0x8000201c) = gameState.playerData[4]->percent;
        *((uint32_t*) 0x80002020) = gameState.playerData[4]->knockbackAngle;
        *((float*) 0x80002024) = gameState.playerData[4]->hitlag;
        *((uint8_t*) 0x80002028) = gameState.playerData[4]->jumpsUsed;
        *((float*) 0x8000202c) = gameState.playerData[4]->shieldSize;
        *((float*) 0x80002030) = gameState.playerData[4]->aiLevel;
        *((float*) 0x80002034) = gameState.playerData[4]->hitstun;

        *((uint32_t*) 0x80002038) = PLAYER_STATE(4);
        *((uint32_t*) 0x8000203c) = SLOT_TYPE(4);
        *((uint32_t*) 0x80002040) = STOCKS(4);
    }

}


