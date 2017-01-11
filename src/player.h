#ifndef PLAYER_H
#define PLAYER_H

#include "inputs.h"
#include "events.h"

typedef struct player
{
    uint8_t number;
    Input* inputs;
    EventListener* events;
    
} Player;

/**
 * @brief Initialize all player information, called at beginning of match
 */
void initPlayer(Player* player, uint8_t number);

/**
 * @brief Add an event listener to this players queue.
 */
void addEventListener(Player* player, EventListener* listener);

void addInput(Player* player, Input input[]);

void checkEvents(Player* player);

void needInstruction(Player* player);

/**
 * @brief Get local copy of @p input, modified for this specific player.
 */
Input parseFlags(Player* player, Input* input);

#endif