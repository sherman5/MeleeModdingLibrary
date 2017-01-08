#include "event.h"

//TODO: don't waste first block

/*void initEQueue(EventQueue* eq, void* mem_address, size_t cap) {
    
    /* starting address of allocated memory */
  /*  eq->start = (Event*) mem_address;

    /* capacity of the queue */
    /*eq->capacity = cap;

    /* initialize first event to null */
   /* eq->start->next = NULL;

}

int8_t addToEQueue(EventQueue* eq, Event* evt) {

    Event* current = eq->start;
    
    while (current->next != NULL) {

        current = current->next;

    }

    if (current + sizeof(Event) > eq->start + eq->capacity) {

        return 1;

    }

    Event* new_event = current + sizeof(Event);

    new_event->event = evt->event;
    new_event->evt_arg1 = evt->evt_arg1;
    new_event->evt_arg2 = evt->evt_arg2;
    new_event->action = evt->action;
    new_event->act_arg1 = evt->act_arg1;
    new_event->act_arg2 = evt->act_arg2;
    new_event->next = NULL;

    return 0;

}

void clearQueue(EventQueue* eq) {

    eq->start = NULL;

}*/

