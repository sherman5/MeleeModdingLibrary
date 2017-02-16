#ifndef PLAYER_H
#define PLAYER_H

#define DR_MARIO        0
#define MARIO           1
#define LUIGI           2
#define BOWSER          3
#define PEACH           4
#define YOSHI           5
#define DK              6
#define FALCON          7
#define GANON           8 
#define FALCO           9
#define FOX             10
#define NESS            11
#define ICE_CLIMBERS    12
#define KIRBY           13
#define SAMUS           14
#define ZELDA           15
#define LINK            16
#define YOUNG_LINK      17
#define PICHU           18
#define PIKACHU         19
#define PUFF            20
#define MEWTWO          21
#define MR_G&W          22
#define MARTH           23
#define ROY             24

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
