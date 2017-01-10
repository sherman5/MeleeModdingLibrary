/**
 * @file controller.h
 * @author Tom Sherman
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
 
    /**
     * 32-bit integer representing which buttons are pressed.
     * A - 0x0100, B - 0x0200, X - 0x0400, Z - 0x0010, L - 0x0040
     */
    uint32_t buttons;

    /** x coordinate of control stick */
    float stickX; 

    /** y coordinate of control stick */
    float stickY; 

    /** player this controller belongs too (1-4) */
    uint8_t playerSlot; 
    
} Controller;

/**
 * @brief Initialize the state of the controller.
 *
 * Set the player slot of this controller to @p slot.
 *
 * @param controller Pointer to a Controller struct.
 * @param slot The slot (1-4) that @p controller is mapped too.
 */
void initController(Controller* controller, uint8_t slot);

/**
 * @brief Press a button on a controller.
 *
 * Press down the button corresponding to @p button.
 *
 * @param controller Pointer to a Controller struct.
 * @param button A @c char representing the button to be pressed.
 * @note This presses @p button down in addition to any other buttons
 *       already being pressed down on @p controller.
 */
void press(Controller* controller, char button);

/**
 * @brief Release all the buttons on @p controller
 * 
 * @param Pointer to a Controller struct
 */
void release(Controller* controller);

/**
 * @brief Set the position of the control stick on @p controller.
 * 
 * @param controller Pointer to a Controller struct.
 * @param radius @c float between [0,1], how far the control stick is pushed
 * @param angle Angle to set the control stick at.
 */
void setStick(Controller* controller, float rad, float angle);

/**
 * @brief Write the state of @p controller to the memory addresses read
 *        read by the game.
 *
 * @param controller Pointer to a Controller struct.
 */
void writeControllerState(Controller* controller);

#endif
