/**
 * @file AI.h
 * @brief Automated player
 *
 */

#ifndef MML_AI_H
#define MML_AI_H

#define DR_MARIO        0b00000000000000000000000000000001
#define MARIO           0b00000000000000000000000000000010
#define LUIGI           0b00000000000000000000000000000100
#define BOWSER          0b00000000000000000000000000001000
#define PEACH           0b00000000000000000000000000010000
#define YOSHI           0b00000000000000000000000000100000
#define DK              0b00000000000000000000000001000000
#define FALCON          0b00000000000000000000000010000000
#define GANON           0b00000000000000000000000100000000 
#define FALCO           0b00000000000000000000001000000000
#define FOX             0b00000000000000000000010000000000
#define NESS            0b00000000000000000000100000000000
#define ICE_CLIMBERS    0b00000000000000000001000000000000
#define KIRBY           0b00000000000000000010000000000000
#define SAMUS           0b00000000000000000100000000000000
#define ZELDA           0b00000000000000001000000000000000
#define LINK            0b00000000000000010000000000000000
#define YOUNG_LINK      0b00000000000000100000000000000000
#define PICHU           0b00000000000001000000000000000000
#define PIKACHU         0b00000000000010000000000000000000
#define PUFF            0b00000000000100000000000000000000
#define MEWTWO          0b00000000001000000000000000000000
#define MR_GNW          0b00000000010000000000000000000000
#define MARTH           0b00000000100000000000000000000000
#define ROY             0b00000001000000000000000000000000

#include "logic.h"
#include "inputs.h"
#include "controller.h"
#include "bool.h"

typedef struct
{
    uint32_t frame;
    uint16_t controller;

} ControllerInput;

typedef struct player
{
    ControllerInput* inputQueue;
    Logic* logicQueue;
    size_t logicSize, inputSize;
    size_t logicCapacity;
    uint32_t characters;
    uint8_t port;
    bool initialized;
    Controller controller;
        
} AI;

void addLogic(AI* ai, FunctionCall condition, FunctionCall action);

void addMove(AI* ai, Move* move);

void updatePlayer(AI* ai);

void initPlayer(AI* ai);

bool needLogic(AI* ai);

#endif
