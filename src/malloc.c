#include "malloc.h"

void initMalloc()
{
    Block b;
    b.size = HEAP_SIZE - sizeof(Block);
    b.free = true;
    b.next = NULL;
    
    *((Block*) HEAP_ADDRESS) = b;
    initialized = true;
}

void defragment()
{
    Block* current = (Block*) HEAP_ADDRESS;

    while (current->next)
    {
        if (current->free && current->next->free)
        {
            current->size += current->next->size + sizeof(struct block);
            current->next = current->next->next;
        }
        else
        {
            current = current->next;
        }
    }
}

void* malloc(size_t size)
{
    if (!initialized) { initMalloc();}

    defragment();

    Block* current = (Block*) HEAP_ADDRESS;
    
    while (current && (current->size < size || !current->free))
    {
        current = current->next;
    }

    if (current)
    {
        Block* leftover = (Block*) (current + size + sizeof(Block));
        leftover->size = current->size - size - sizeof(Block);
        leftover->free = true;
        leftover->next = current->next;
        
        current->size = size;
        current->free = false;
        current->next = (void*) (current + size + sizeof(Block));
    }

    return current;
}

/* Reallocate memory block */
void* realloc(void* ptr, size_t size)
{
    /* handle edge cases */
    if (!ptr) {return malloc(size);}
    if (size == 0) {free(ptr); return NULL;}
    
    /* find ptr in linked list of memory blocks */
    Block* current = (Block*) HEAP_ADDRESS;
    while (current && current != ptr) {current = current->next;}
    
    /* if not found, return NULL */
    if (!current) {return NULL;}

    

}

void free(void* ptr)
{
    ((Block*) ptr)->free = true;
}
