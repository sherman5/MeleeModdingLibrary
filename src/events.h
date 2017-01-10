#ifndef EVENTS_H
#define EVENTS_H

#include <stdint.h>
#include <stdbool.h>

typedef enum event_t
{
    OFFSTAGE,
    HITSTUN,
    AIRBORNE,
    FUNCTION

} Event;

typedef struct event_listener
{
    Event event;
    uint8_t player;
    void* callback;

} EventListener;

bool checkEventListener(EventListener* listener);

#endif