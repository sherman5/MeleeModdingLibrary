#include <mml/input_queue.h>
#include <mml/moves.h>
#include <mml/system.h>
#include <mml/game_state.h>
#include <mml/print.h>

static char heap[20000];
static bool init_run = false;

#define PORT 2
static InputQueue inputQueue = INIT_INPUT_QUEUE(PORT);
static bool active = false;
static uint32_t wait = 120;

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
        print("control on");
        active = true;
        inputQueue.size = 0; // reset queue
        inputQueue.controller = DEFAULT_CONTROLLER; // reset controller
        writeController(&inputQueue.controller, PORT, false);
        _gameState.playerBlock[PORT]->slotType = 0x00; // take control of player
    }
    
    if (active && !inGame()) // turn off input control
    {
        print("control off");
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
            addMoveToQueue(&inputQueue, &_mv_shortHop);
            print("added move");
            char buffer[96];
            sprintf(buffer, "Input Queue Size: %d", inputQueue.size);
            print(buffer);
        }
        else if (inputQueue.size > 0)
            wait = 120;
        else 
            wait--;
    
        processInputQueue(&inputQueue);
    }

}

