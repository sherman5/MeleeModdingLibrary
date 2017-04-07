#include "native_functions.h"
#include "game_state.h"
#include "gctypes.h"

#ifdef PAL

#error game_state.c not compatible with PAL

#else

#define IN_GAME (((*((u32*) (0x8065CC14)) >> 20) & 0x0F) == 0x0D)

#endif

u32 (*numPlayers)() = (void*) 0x8016b558;

static u32 _end_frame = 0xffffffff;
static bool _in_game = false;

void endGame()
{
//    _in_game = false;
//    _end_frame = CURRENT_FRAME;
}

bool inGame()
{
/*    if (!_in_game && IN_GAME && CURRENT_FRAME < _end_frame)
    {
        _in_game = true;    
    }
    return _in_game;*/  
//   bool res = IN_GAME;
//    bool res = (playerData(1) || playerData(2) || playerData(3)
//        || playerData(4));
//    bool res = numPlayers() > 0;

    if (!_in_game && IN_GAME)
    {
        _in_game = true;
    }
    else if (_in_game && CURRENT_FRAME < _end_frame)
    {
        _in_game = false;
    }

    if (_in_game)
    {
        _end_frame = CURRENT_FRAME;
    }    

    *((u32*) 0x80001810) = _in_game ? 0xAAAA : 0xFFFF;
    
    return _in_game;
}

GameState _gameState = DEFAULT_GAMESTATE;

u32 (*playerEntity)(u32) = PLAYER_ENTITY_FPTR;

PlayerData* playerData(u32 id)
{
    u32 entity = playerEntity(id - 1);
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
    _gameState.playerData[1] = playerData(1);
    _gameState.playerData[2] = playerData(2);
    _gameState.playerData[3] = playerData(3);
    _gameState.playerData[4] = playerData(4);

    _gameState.playerBlock[1] = (PlayerBlock*) 0x80453080;
    _gameState.playerBlock[2] = (PlayerBlock*) 0x80453f10;
    _gameState.playerBlock[3] = (PlayerBlock*) 0x80454da0;
    _gameState.playerBlock[4] = (PlayerBlock*) 0x80455c30;

    _gameState.stage.name = STAGE_ID;

    switch (_gameState.stage.name)
    {
        case YOSHIS:

            _gameState.stage.ledge.x = 59.5f;
            _gameState.stage.ledge.y = -3.f;

            _gameState.stage.side.left = 28.f;
            _gameState.stage.side.right = 59.5f;
            _gameState.stage.side.height = 23.45f;

            _gameState.stage.top.left = -15.75f;
            _gameState.stage.top.right = 15.75f;
            _gameState.stage.top.height = 42.f;

            break;

        case FOUNTAIN:

            _gameState.stage.ledge.x = 63.34f;
            _gameState.stage.ledge.y = 1.f;

            _gameState.stage.side.height = 0.f;

            _gameState.stage.top.left = -14.25f;            
            _gameState.stage.top.right = 14.25f;
            _gameState.stage.top.height = 42.75f;

            break;

        case STADIUM:

            _gameState.stage.ledge.x = 87.75f;
            _gameState.stage.ledge.y = 5.f;

            _gameState.stage.side.left = 25.f;
            _gameState.stage.side.right = 55.f;
            _gameState.stage.side.height = 25.f;

            _gameState.stage.top.height = 0.f;

            break;

        case BATTLEFIELD:

            _gameState.stage.ledge.x = 68.4f;
            _gameState.stage.ledge.y = 6.f;

            _gameState.stage.side.left = 20.f;
            _gameState.stage.side.right = 57.6f;
            _gameState.stage.side.height = 27.2f;

            _gameState.stage.top.left = -18.8f;
            _gameState.stage.top.right = 18.8f;
            _gameState.stage.top.height = 54.4f;

            break;

        case FINAL:

            _gameState.stage.ledge.x = 85.57f;
            _gameState.stage.ledge.y = 0.f;

            _gameState.stage.side.height = 0.f;

            _gameState.stage.top.height = 0.f;

            break;

        case DREAMLAND:

            _gameState.stage.ledge.x = 77.27f;
            _gameState.stage.ledge.y = 0.f;

            _gameState.stage.side.left = 31.7f;
            _gameState.stage.side.right = 63.07f;
            _gameState.stage.side.height = 30.24f;

            _gameState.stage.top.left = -19.02f;
            _gameState.stage.top.right = 19.02f;
            _gameState.stage.top.height = 51.43f;

            break;

        default:

            _gameState.stage.ledge.x = 0.f;
            break;
    }
}


