/**
 * @file ai.h
 * @brief Automated player
 *
 */

#ifndef MML_AI_H
#define MML_AI_H

//@{
/** AI Character Bit Mask */
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
//@}

#include "logic.h"
#include "moves.h"
#include "controller.h"
#include "gctypes.h"
#include "input_queue.h"

/** @brief Holds all information about an AI */
typedef struct
{
    InputQueue inputQueue;  /**< Manages inputs */
    Logic* logicQueue;      /**< Array of logic to evaluate */
    size_t logicSize;       /**< Size of logic/input arrays */
    size_t logicCapacity;   /**< Capacity of arrays */
    u32 characters;         /**< Characters this AI can control */
    u32 port;               /**< Port this AI plays at */
    u32 opponent;           /**< Port of this AI's opponent */
    bool active;            /**< AI is active in the game */
        
} AI;

/** helps with ai initialization */
#define INIT_AI(port_val, characters_val) \
{ \
    .inputQueue = INIT_INPUT_QUEUE(port_val), \
    .logicQueue = NULL, \
    .logicSize = 0, \
    .logicCapacity = 0, \
    .characters = characters_val, \
    .port = port_val, \
    .active = false \
}

/**
 * @brief Add single logic rule to AI
 * @ingroup CallsMalloc
 *
 * @param ai - Pointer to AI struct
 * @param logic - Point to Logic struct
 * @return none
 */
void addLogic(AI* ai, const Logic* logic);

/**
 * @brief Add a move to the ai
 * @ingroup CallsMalloc
 *
 * @param ai - Pointer to AI struct
 * @param move - Pointer to Move struct
 * @return none
 */
void addMove(AI* ai, const Move* move);

/**
 * @brief Check logic rules and queued inputs 
 *
 * @param ai - Pointer to AI struct 
 * @return  none 
 */
void updateAI(AI* ai);

/**
 * @brief Check if AI has no logic or inputs queued
 *
 * @param ai - Pointer to AI struct
 * @return Return true if AI has no logic or inputs queued 
 */
bool needLogic(const AI* ai);

/** 
 * @brief Clear all logic and inputs from AI (reset controller)
 *
 * @param ai - Pointer to AI struct
 * @return none
 */
void clearAI(AI* ai);

#endif
