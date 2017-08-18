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
static float dir = 180.f;
static uint32_t wait = 180;

static void init()
{
    initHeap(heap, heap + sizeof(heap));
    init_run = true;
}

static void updatePlayerState()
{
    if (!active && inGame() // turn on input control
    && playerData(PORT) // player at PORT exists
    && SLOT_TYPE(PORT) == 0x01 // cpu player
    && _gameState.stage.ledge.x > 0) // valid stage
    {
        active = true;
        inputQueue.size = 0; // reset queue
        inputQueue.controller = DEFAULT_CONTROLLER; // reset controller
        SLOT_TYPE(PORT) = 0x00; // take control of player
    }
    
    if (active && !inGame()) // turn off input control
    {
        active = false;
        inputQueue.size = 0; // reset queue
        inputQueue.controller = DEFAULT_CONTROLLER; // reset controller
        writeController(&inputQueue.controller, PORT, false);
        SLOT_TYPE(PORT) = 0x01; // set back to CPU
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
        if (wait == 0)
        {
            addInputToQueue(&inputQueue, (RawInput)
                {FULL_STICK | STICK_ANGLE(dir), 0, RESET_STICK_COUNTER});
            dir = dir > 0 ? 0.f : 180.f;
            wait = _dash_frames[CHAR_SELECT(PORT)];
        }
        else
        {
            wait--;
        }
        processInputQueue(&inputQueue);
    }

}
