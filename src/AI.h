/**
 * @file AI.h
 * @brief Automated player
 *
 */

#ifndef MML_AI_H
#define MML_AI_H

#define DR_MARIO        (1 << 0)
#define MARIO           (1 << 1)
#define LUIGI           (1 << 2)
#define BOWSER          (1 << 3)
#define PEACH           (1 << 4)
#define YOSHI           (1 << 5)
#define DK              (1 << 6)
#define FALCON          (1 << 7)
#define GANON           (1 << 8)
#define FALCO           (1 << 9)
#define FOX             (1 << 10)
#define NESS            (1 << 11)
#define ICE_CLIMBERS    (1 << 12)
#define KIRBY           (1 << 13)
#define SAMUS           (1 << 14)
#define ZELDA           (1 << 15)
#define LINK            (1 << 16)
#define YOUNG_LINK      (1 << 17)
#define PICHU           (1 << 18)
#define PIKACHU         (1 << 19)
#define PUFF            (1 << 20)
#define MEWTWO          (1 << 21)
#define MR_GNW          (1 << 22)
#define MARTH           (1 << 23)
#define ROY             (1 << 24)

#include "logic.h"
#include "inputs.h"
#include "controller.h"
#include "gctypes.h"

typedef struct
{
    u32 frame;
    u16 controller;

} ControllerInput; // 8 bytes with padding

typedef struct
{
    Controller controller;
    ControllerInput* inputQueue;
    Logic* logicQueue;
    size_t logicSize, inputSize;
    size_t logicCapacity, inputCapacity;
    u32 characters;
    u32 port;
    u32 opponent;
    bool active;
        
} AI;

void addLogic(AI* ai, Logic* logic);

void addMove(AI* ai, Move* move);

void updateAI(AI* ai);

bool needLogic(AI* ai);

void clearAI(AI* ai);

#endif
