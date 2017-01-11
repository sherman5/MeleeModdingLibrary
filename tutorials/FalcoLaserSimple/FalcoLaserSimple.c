//#include <random.h>
//#include <melee.h>
//#include <moves.h>

#include <mml/player.h>
#include <mml/events.h>
#include <mml/moves.h>

#include <stdint.h>
#include <stdbool.h>

static bool notInGame = true;
static Player player = DEFAULT_PLAYER;

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
]

void _main()
{
    if (IN_GAME && P1_CHAR == FALCO)
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
}
 