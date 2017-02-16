#include "AI.h"
#include "gctypes.h"
#include "system.h"
#include "gamestate.h"

void addLogic(AI* ai, FunctionCall condition, FunctionCall action)
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

ControllerInput processRawInput(u8 port, RawInput input)
{
    ControllerInput processed;

    processed.frame = CURRENT_FRAME + input.frameOffset;

    if (input.flags & JUMPSQUAT)
    {
        processed.frame += (u32) gameState.playerData[port]->jumpSquat;
    }

    processed.controller = input.controller;
    return processed;
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

void checkLogic(AI* ai)
{
    for (unsigned i = 0; i < ai->logicSize; ++i)
    {
        FunctionCall cond = ai->logicQueue[i].condition;
        bool (*c)(FunctionArg, FunctionArg) = cond.function;
        
        if (c(cond.arg1, cond.arg2))
        {
            FunctionCall act = ai->logicQueue[i].action;
            void (*a)(FunctionArg, FunctionArg) = act.function;
            a(act.arg1, act.arg2);
            ai->logicSize = 0;
            return;
        }
    }
} 

void checkInput(AI* ai)
{
    if (CURRENT_FRAME >= ai->inputQueue[ai->inputSize - 1].frame)
    {
        setController(&ai->controller,
            ai->inputQueue[ai->inputSize - 1].controller);
        ai->inputSize--;
    }
}

void updateAI(AI* ai)
{
    updateGameState();

    if (PLAYER_STATE(ai->port)
        && (ai->characters >> CHAR_SELECT(ai->port)) & 1)
    {
        checkLogic(ai);
        checkInput(ai);

        writeController(&ai->controller, ai->port);
    }

}

void initPlayer(AI* ai)
{
    ai->logicCapacity = 10;
    ai->logicQueue = calloc(ai->logicCapacity, sizeof(Logic));
    ai->logicSize = 0;
}

bool needLogic(AI* ai)
{
    return ai->logicSize == 0 && ai->inputSize == 0;
}


