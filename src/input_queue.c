#include "input_queue.h"
#include "game_state.h"
#include "error.h"

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

void addInput(InputQueue* queue, const RawInput input)
{
    if (queue->size == queue->capacity)
    {
        queue->capacity = 2 * queue->capacity;
        queue->queue = realloc(queue->queue, queue->capacity
            * sizeof(ControllerInput));

        if (!queue->queue)
        {
            ERROR_MSG("failed allocation: input queue");
        }
    }
    
    if (queue->queue)
    {
        ControllerInput procInput = processRawInput(queue->port, input);
        unsigned index = queue->size - 1;
        while (queue[index].frame < procInput.frame && index >= 0)
        {
            queue[index + 1] = queue[index];
            index--;
        }
        queue->queue[index + 1] = procInput;
        queue->size++;
    }
}

void addMove(InputQueue* queue, const Move* move)
{
    for (unsigned i = 0; i < move->size; ++i)
    {
        addInput(queue, move->inputs[i]);
    }
}

#define PDATA _gameState.playerData[queue->port]
void processInputQueue(InputQueue* queue)
{
    if (queue->size > 0)
    {
        ControllerInput* input = &queue->queue[queue->size - 1]
        if (CURRENT_FRAME >= input->frame)
        {
            setController(&queue->controller, input->state);
            queue->size--;
            if (input->resetStickCount)
            {
                PDATA->analogCardinalXFrames = 0;
                PDATA->analogCardinalYFrames = 0;
            }
        }
    }
    writeController(&queue->controller, queue->port, true);
}

u32 highestFrame(InputQueue* queue)
{
    return queue->queue[queue->size - 1].frame;
}
