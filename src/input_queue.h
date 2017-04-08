/**
 * @file input_queue.h
 * @brief Queue inputs for a specific port
 */

#ifndef MML_INPUT_QUEUE_H
#define MML_INPUT_QUEUE_H

#include "moves.h"
#include "controller.h"
#include "gctypes.h"

/**
 * @brief A single controller input made by the AI
 * @note size = 8 bytes
 */
typedef struct __attribute__((packed))
{
    u32 frame;              /**< Frame on which to execute input */
    u16 state;              /**< State of controller */
    u16 resetStickCount;    /**< Reset control stick active frames */

} ControllerInput;

/** @brief Manages a list of inputs */
typedef struct
{
    ControllerInput* queue; /**< Array of inputs to execute */
    size_t size;            /**< Number of inputs in queue */
    size_t capacity;        /**< Capacity of queue */
    unsigned port;          /**< Port that this input queue belongs to */
    Controller controller; /**< Controller this queue uses */

} InputQueue;

/** Default InputQueue struct */
#define INIT_INPUT_QUEUE(port) {NULL, 0, 0, port, DEFAULT_CONTROLLER}

/**
 * @brief Add single input to queue
 * @ingroup CallsMalloc
 *
 * @param queue - Pointer to InputQueue struct
 * @param input - Pointer to RawInput struct
 * @return none
 */
void addInput(InputQueue* queue, const RawInput input);

/**
 * @brief Add entire move to queue
 * @ingroup CallsMalloc
 *
 * @param queue - Pointer to InputQueue struct
 * @param move - Pointer to Move struct
 * @return none
 */
void addMove(InputQueue* queue, const Move* move);

/**
 * @brief Check if any inputs need to be written
 *
 * @param queue - Pointer to InputQueue struct
 * @return  none 
 */
void processInputQueue(InputQueue* queue);

u32 highestFrame(InputQueue* queue);

#endif
