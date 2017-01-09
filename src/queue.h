#ifndef QUEUE_H
#define QUEUE_H

#include <stdint.h>
#include <stddef.h>

#include <malloc.h>



void initEQueue(void*, size_t);
int8_t addToEQueue(EventQueue*, Event*);
void clearEQueue(EventQueue*);
Event checkEQueue(EventQueue*);
void takeAction(Event*);

#endif
