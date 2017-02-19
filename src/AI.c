#include "AI.h"
#include "gctypes.h"
#include "system.h"
#include "gamestate.h"
#include "meleeinfo.h"

static ControllerInput processRawInput(u8 port, RawInput input)
{
    ControllerInput processed;

    processed.frame = CURRENT_FRAME + input.frameOffset;

    if (input.flags & JUMPSQUAT)
    {
        processed.frame += (u32) gameState.playerData[port]->jumpSquat;
    }

    if (input.flags & SH_LENGTH)
    {
        processed.frame += GET_SH_LENGTH(CHAR_SELECT(port));
    }

    processed.controller = input.controller;
    return processed;
}

static void checkLogic(AI* ai)
{
    for (unsigned i = 0; i < ai->logicSize; ++i)
    {
        bool (*c)(FunctionArg, FunctionArg)
            = ai->logicQueue[i].condition.function;
        
        if (c(ai->logicQueue[i].condition.arg1,
            ai->logicQueue[i].condition.arg2))
        {
            ai->logicSize = 0;

            void (*a)(u32, u32)
                = ai->logicQueue[i].action.function;

            a(ai->logicQueue[i].action.arg1.u,
                ai->logicQueue[i].action.arg2.u);

            return;
        }
    }
} 

static void checkInput(AI* ai)
{
    if (CURRENT_FRAME >= ai->inputQueue[ai->inputSize - 1].frame)
    {
        setController(&ai->controller,
            ai->inputQueue[ai->inputSize - 1].controller);
        ai->inputSize--;
    }
}

void addLogic(AI* ai, Function condition, Function action)
{
    if (ai->logicSize == ai->logicCapacity)
    {
        ai->logicCapacity += 5;
        ai->logicQueue = realloc(ai->logicQueue,
            ai->logicCapacity * sizeof(Logic));
    }

    ai->logicQueue[ai->logicSize] = (Logic) {condition, action};
    ai->logicSize++;
}

void addMove(AI* ai, Move* move)
{
    ai->inputSize = move->size;
    ai->inputQueue = realloc(ai->inputQueue,
        ai->inputSize * sizeof(ControllerInput));

    for (unsigned i = 0; i < ai->inputSize; ++i)
    {
        unsigned index = ai->inputSize - i - 1;
        ai->inputQueue[i] = processRawInput(ai->port, move->inputs[index]);
    }
}

void updateAI(AI* ai)
{
    updateGameState();
    
    if (!ai->active && inGame()
        && playerData(ai->port)
        && SLOT_TYPE(ai->port) == 0x01
        && ((ai->characters >> CHAR_SELECT(ai->port)) & 1)
        && gameState.stage.ledge > 0)
    {
        ai->active = true;
        SLOT_TYPE(ai->port) = 0x00;
        ai->inputSize = 0;
        ai->logicSize = 0;
        ai->logicCapacity = 0;
        ai->controller = (Controller) {0, 0.0, 0.0};
        ai->logicQueue = NULL;
        ai->inputQueue = NULL;
    }
    
    if (ai->active && !inGame())
    {
        ai->active = false;
        SLOT_TYPE(ai->port) = 0x01;
        ai->controller = (Controller) {0, 0.0, 0.0};
        writeController(&ai->controller, ai->port);
    }

    if (ai->active)
    {
        checkLogic(ai);
        if (ai->inputSize > 0) {checkInput(ai);}

        writeController(&ai->controller, ai->port);
    }

}

bool needLogic(AI* ai)
{
    return ai->logicSize == 0 && ai->inputSize == 0;
}

