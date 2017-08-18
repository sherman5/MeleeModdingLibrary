#include <mml/input_queue.h>
#include <mml/moves.h>
#include <mml/system.h>
#include <mml/game_state.h>
#include <mml/print.h>
#include <mml/random.h>
#include <mml/melee_info.h>
#include <mml/math.h>

static char heap[20000];
static bool init_run = false;

#define PORT 2
static InputQueue inputQueue = INIT_INPUT_QUEUE(PORT);
static bool active = false;
static uint32_t wait = 120;

// TODO: calculate the max dash distance for all players
#define MAX_DASH 10 // dummy value for now

static void init()
{
    initHeap(heap, heap + sizeof(heap));
    init_run = true;
}

static void updatePlayerState()
{
    if (!active && inGame() // turn on input control
    && playerData(PORT) // player at PORT exists
    && _gameState.playerBlock[PORT]->slotType == 0x01 // cpu player
    && _gameState.stage.ledge.x > 0) // valid stage
    {
        active = true;
        inputQueue.size = 0; // reset queue
        inputQueue.controller = DEFAULT_CONTROLLER; // reset controller
        writeController(&inputQueue.controller, PORT, false);
        _gameState.playerBlock[PORT]->slotType = 0x00; // take control of player
    }
    
    if (active && !inGame()) // turn off input control
    {
        active = false;
        inputQueue.size = 0; // reset queue
        inputQueue.controller = DEFAULT_CONTROLLER; // reset controller
        writeController(&inputQueue.controller, PORT, false);
        _gameState.playerBlock[PORT]->slotType = 0x01; // set back to CPU
    }
}

void _main()
{
    if (!init_run)
        init();

    updateGameState();
    updatePlayerState();

    if (active)
    {
        if (inputQueue.size == 0 && wait == 0)
        {
            Point crds = _gameState.playerData[PORT]->coordinates;
            float dist_to_ledge = _gameState.stage.ledge.x - fabs(crds.x);
            float prob = fabs(crds.x) / _gameState.stage.ledge.x;
            
            float dir;
            if (rand() < prob) // away from ledge
                dir = crds.x > 0 ? 180.f : 0.f;
            else // towards ledge
                dir = crds.x > 0 ? 0.f : 180.f;

            float dist = uniform(0, dist_to_ledge);
            float dash_prop = dist / MAX_DASH + 5;
            uint32_t frames = dash_prop * _dash_frames[CHAR_SELECT(PORT)];
            addInputToQueue(&inputQueue, (RawInput) {FULL_STICK | STICK_ANGLE(dir), 0, RESET_STICK_COUNTER});
            wait = frames;
        }
        else if (inputQueue.size == 0)
        {
            wait--;
        }
        processInputQueue(&inputQueue);
    }

}
