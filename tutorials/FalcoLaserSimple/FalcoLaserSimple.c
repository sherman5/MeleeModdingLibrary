#include <mml/player.h>
#include <mml/events.h>
#include <mml/moves.h>

#include <stdint.h>
#include <stdbool.h>

/* set player properties */
static const Logic default_logic[] = {  };

Player player2;
player2->port = 2;
player2->defaultLogic = &default_logic;
player2->possibleCharacters = {FOX, FALCO, MARTH};

void SHLaser()
{
    Input shLaser = parseFlags(&player, SH_LASER);   
    clearEvents(&player);
    addInput(&player, shLaser);
}

bool randomChance()
{
    /* once every two seconds */
    return rand() < (float) 1 / 120;
}

void _main()
{
    if (playerLogicEmpty(&player2))
    {
        setDefaultLogic(&player2, &default_logic);
    }  
    playOneFrame(&player2);
}

    #if 0
    if (IN_GAME && P2_CHAR == FALCO)
    {
        /* if entering game, reinitialize player 2 */
        if (notInGame)
        {
            initPlayer(&player, 2);
        }

        /* if player has no instructions */
        if (needInstruction(&player))
        {
            /* load up event */
            EventListener listener = {.event = FUNCTION, .func = randomChance, .player = 2, .callback = SHlaser()};

            /* add event to player */
            addEventListener(&player, listener);
        }
        
        /* check if any event happened */
        checkEvents(player);
    }
    else
    {
        notInGame = true;
    }
    #endif
 
