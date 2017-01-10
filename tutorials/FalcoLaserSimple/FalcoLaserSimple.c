//#include <random.h>
#include <melee.h>
//#include <moves.h>

#include <stdint.h>

static uint32_t init_key = 0;
//static Input* inputQueue = 0;

void _main()
{
    /* check if this is the first time calling the function */
    if (init_key != 1)
    {
        init_key = 1;

        //do setup
    }

    *((uint32_t*) 0x80001800) = 0xFFFFFFFF;
    
    if (IN_GAME && P1_CHAR == FALCO)
    {
        /* execute moves already in queue */
        //checkQueue(inputQueue);
    
        /* every 2 seconds on average */
        /*if (queueEmpty(inputQueue) && rand() < 1 / 120)
        {
            addToInputQueue(inputQueue, SH_LASER);
        }*/
        *((uint32_t*) 0x80001800) = 0xAAAAAAAA;
    }
}