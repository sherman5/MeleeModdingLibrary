#ifndef EVENT_H
#define EVENT_H

#include <stdint.h>
#include <stddef.h>

typedef struct event {

    /* function that returns T/F */
    void* event;

    /* arguments to the event function */
    int32_t evt_arg1;
    int32_t evt_arg2;

    /* function that takes some action */
    void* action;

    /* arguments to the action function */
    int32_t act_arg1;
    int32_t act_arg2;

} Event;

typedef struct node {

    Event event;
    struct node* next;

} Node;

typedef struct event_queue {

    /* available memory start */
    void* start_address;

    /* first event in queue */
    Event* front;

    /* available memory for this queue */
    size_t capacity;

} EventQueue;

void initEQueue(void*, size_t);
int8_t addToEQueue(EventQueue*, Event*);
void clearEQueue(EventQueue*);
Event checkEQueue(EventQueue*);
void takeAction(Event*);

#endif
