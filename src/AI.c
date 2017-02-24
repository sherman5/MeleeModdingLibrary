#include "AI.h"
#include "gctypes.h"
#include "system.h"
#include "game_state.h"
#include "melee_info.h"
#include "string.h"

static u32 stockCount;

static ControllerInput processRawInput(u8 port, RawInput input)
{
    ControllerInput processed;

    processed.frame = CURRENT_FRAME + input.frameOffset;

    if (input.flags & JUMPSQUAT)
    {
        processed.frame += (u32) _gameState.playerData[port]->jumpSquat;
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
            ai->inputSize = 0;

            void (*a)(FunctionArg, FunctionArg)
                = ai->logicQueue[i].action.function;

            a(ai->logicQueue[i].action.arg1,
                ai->logicQueue[i].action.arg2);

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

void addLogic(AI* ai, Logic* logic)
{
    if (ai->logicSize == ai->logicCapacity)
    {
        ai->logicCapacity += 5;
        ai->logicQueue = realloc(ai->logicQueue,
            ai->logicCapacity * sizeof(Logic));
    }
    memcpy(ai->logicQueue + ai->logicSize, logic, sizeof(Logic));
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
        && _gameState.stage.ledge > 0)
    {
        ai->active = true;
        SLOT_TYPE(ai->port) = 0x00;
        ai->inputSize = 0;
        ai->logicSize = 0;
        ai->logicCapacity = 0;
        ai->controller = (Controller) {0, 0.f, 0.f, 0.f, 0.f};
        ai->logicQueue = NULL;
        ai->inputQueue = NULL;
        stockCount = STOCKS(ai->port);
    }
    
    if (ai->active && !inGame())
    {
        ai->active = false;
        SLOT_TYPE(ai->port) = 0x01;
        ai->controller = (Controller) {0, 0.f, 0.f, 0.f, 0.f};
        writeController(&ai->controller, ai->port, false);
    }

    if (ai->active)
    {
        if (STOCKS(ai->port) < stockCount)
        {
            stockCount = STOCKS(ai->port);
            clearAI(ai);
            ai->controller = (Controller) {0, 0.f, 0.f, 0.f, 0.f};
        }
        checkLogic(ai);
        if (ai->inputSize > 0) {checkInput(ai);}

        writeController(&ai->controller, ai->port, true);
    }

}

bool needLogic(AI* ai)
{
    return ai->logicSize == 0 && ai->inputSize == 0;
}

void clearAI(AI* ai)
{
    ai->logicSize = 0;  
    ai->inputSize = 0;
    ai->controller = (Controller) {0, 0.f, 0.f, 0.f, 0.f};
}

