#include "melee.h"
#include "events.h"

bool checkEventListener(EventListener* listener)
{
    switch (listener->event)
    {
        case 0: //OFFSTAGE
            return PLAYER_X(listener->player) > 100
                || PLAYER_Y(listener->player) < -10;
            break;
        case 1: //HITSTUN
            return PLAYER_HITSTUN(listener->player) > 0;
            break;
        case 2: //AIRBORNE
            return PLAYER_IN_AIR(listener->player);
            break;
    }
}
