/**
 * @file controller.h
 * @brief Emulate a player's controller.
 *
 */

#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <stdint.h>

/**
 * @brief Represents the state of a controller.
 */
typedef struct controller {
 
    uint32_t buttons; /**< A-0100, B-0200, X-0400, Z-0010, L-0040 */

    float stickX; /**< x coordinate of control stick */
    float stickY; /**< y coordinate of control stick */
    
} Controller;

/**
 * @brief Set the state of the controller.
 *
 * @param controller - Pointer to a Controller struct.
 * @param state - 16-bit integer encoding the controller state.
 * 0b00000000000xxxxx - buttons
 * 0b00000000xxx00000 - stick radius
 * 0bxxxxxxxx00000000 - stick angle
 *
 * @return None.
 */
void setController(Controller* controller, uint16_t state);

/**
 * @brief Write the state of @p controller to the memory addresses read
 * by the game.
 *
 * @param controller - Pointer to a Controller struct.
 * @param port - Which player port to write to {1,2,3,4}
 *
 * @return None
 */
void writeController(Controller* controller, uint8_t port);

#endif
