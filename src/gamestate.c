#include "native_functions.h"
#include "gamestate.h"

GameState gameState = DEFAULT_GAMESTATE;

uint32_t (*playerEntity)(unsigned) = PLAYER_DATA_FPTR;

PlayerData* playerData(unsigned id)
{
    uint32_t entity = playerEntity(id - 1);
    if (entity > 0)
    {
        return *((PlayerData**) (entity + 0x2c));
    }
    else
    {
        return 0;
    }
}

void updateGameState()
{
    gameState.playerData[1] = playerData(1);
    gameState.playerData[2] = playerData(2);
    gameState.playerData[3] = playerData(3);
    gameState.playerData[4] = playerData(4);

    gameState.stage.name = STAGE_ID;
    switch (gameState.stage.name)
    {
        case YOSHIS:

            gameState.stage.ledge = 57.92;

            gameState.stage.side.left = 28.0;
            gameState.stage.side.right = 59.5;
            gameState.stage.side.height = 23.45;

            gameState.stage.top.left = -15.75;
            gameState.stage.top.right = 15.75;
            gameState.stage.top.height = 42.0;

            break;

        case FOUNTAIN:

            gameState.stage.ledge = 65.23;

            gameState.stage.side.height = 0.0;

            gameState.stage.top.left = -14.25;            
            gameState.stage.top.right = 14.25;
            gameState.stage.top.height = 42.75;

            break;

        case STADIUM:

            gameState.stage.ledge = 89.67;

            gameState.stage.side.left = 25.0;
            gameState.stage.side.right = 55.0;
            gameState.stage.side.height = 25.00;

            gameState.stage.top.height = 0.0;

            break;

        case BATTLEFIELD:

            gameState.stage.ledge = 70.32;

            gameState.stage.side.left = 20.0;
            gameState.stage.side.right = 57.60;
            gameState.stage.side.height = 27.20;

            gameState.stage.top.left = -18.80;
            gameState.stage.top.right = 18.80;
            gameState.stage.top.height = 54.40;

            break;

        case FINAL:

            gameState.stage.ledge = 88.02;

            gameState.stage.side.height = 0.0;

            gameState.stage.top.height = 0.0;

            break;

        case DREAMLAND:

            gameState.stage.ledge = 79.72;

            gameState.stage.side.left = 31.73;
            gameState.stage.side.right = 61.39;
            gameState.stage.side.height = 30.14;

            gameState.stage.top.left = -19.02;
            gameState.stage.top.right = 19.02;
            gameState.stage.top.height = 51.43;

            break;
    }
}

bool inGame()
{
    return PLAYER_STATE(1) + PLAYER_STATE(2) + PLAYER_STATE(3)
        + PLAYER_STATE(4) > 0;
}

