#include "input_queue.h"
#include "game_state.h"

static ControllerInput processRawInput(u8 port, RawInput input)
{
    ControllerInput processed = {.controller = input.controller,
        .frame = CURRENT_FRAME + input.frameOffset,
        .resetCounter = 0};

    if (input.flags & JUMPSQUAT)
    {
        processed.frame += (u32) _gameState.playerData[port]->jumpSquat;
    }
    if (input.flags & SH_LENGTH)
    {
        processed.frame += _sh_length[CHAR_SELECT(port)];
    }
    if (input.flags & LEDGEDASH)
    {
        processed.frame += _ledgedash_frames[CHAR_SELECT(port)];
    }
    if (input.flags & RESET_STICK_COUNTER)
    {
        processed.resetCounter = 1;
    }

    return processed;
}
