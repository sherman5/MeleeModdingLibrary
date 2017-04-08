#include "ai.h"
#include "gctypes.h"
#include "system.h"
#include "game_state.h"
#include "melee_info.h"
#include "string.h"
#include "error.h"

static bool aiError = false;

#define COND_FPTR       ai->logicQueue[i].condition.function
#define ACTION_FPTR     ai->logicQueue[i].action.function
#define COND_ARG_1      ai->logicQueue[i].condition.arg1
#define COND_ARG_2      ai->logicQueue[i].condition.arg2
#define ACTION_ARG_1    ai->logicQueue[i].action.arg1
#define ACTION_ARG_2    ai->logicQueue[i].action.arg2
static void checkLogic(AI* ai)
{
    for (unsigned i = 0; i < ai->logicSize; ++i)
    {
        bool (*condition)(FunctionArg, FunctionArg) = COND_FPTR;
        
        if (condition(COND_ARG_1, COND_ARG_2))
        {
            clearAI(ai);
            void (*action)(FunctionArg, FunctionArg) = ACTION_FPTR;
            action(ACTION_ARG_1, ACTION_ARG_2);
            return;
        }
    }
} 

#define LOGIC_SIZE      (ai->logicCapacity * sizeof(Logic))
void addLogic(AI* ai, const Logic* logic)
{
    if (ai->logicSize == ai->logicCapacity)
    {
        ai->logicCapacity = ai->logicCapacity * 2 + 1;
        ai->logicQueue = realloc(ai->logicQueue, LOGIC_SIZE);
        if (!ai->logicQueue)
        {
            THROW_ERROR(0, "failed allocation: logic queue");
            aiError = true;
        }    
    }
    memcpy(ai->logicQueue + ai->logicSize, logic, sizeof(Logic));
    ai->logicSize++;
}

bool needLogic(const AI* ai)
{
    return ai->logicSize == 0 && ai->inputQueue.size == 0 && ai->active;
}

void clearAI(AI* ai)
{
    ai->logicSize = 0;  
    ai->inputQueue.size = 0;
    ai->inputQueue.controller = DEFAULT_CONTROLLER;
}

static void findOpponent(AI* ai)
{
    if       (playerData(1) && ai->port != 1) {ai->opponent = 1;}
    else if  (playerData(2) && ai->port != 2) {ai->opponent = 2;}
    else if  (playerData(3) && ai->port != 3) {ai->opponent = 3;}
    else if  (playerData(4) && ai->port != 4) {ai->opponent = 4;}
}

void updateAI(AI* ai)
{
    updateGameState();

    if (aiError) {return;}

    if (!ai->active && inGame() && playerData(ai->port) 
        && _gameState.playerBlock[ai->port]->slotType == 0x01
        && _gameState.stage.ledge.x > 0
        && ((ai->characters >> CHAR_SELECT(ai->port)) & 1))
    {
        ai->active = true;
        clearAI(ai);
        _gameState.playerBlock[ai->port]->slotType = 0x00;
        findOpponent(ai);
    }
    
    if (ai->active && !inGame())
    {
        ai->active = false;
        clearAI(ai);
        _gameState.playerBlock[ai->port]->slotType = 0x01;
        writeController(&ai->inputQueue.controller, ai->port, false);
    }

    if (ai->active)
    {
        checkLogic(ai);
        processInputQueue(&ai->inputQueue);
    }
}

