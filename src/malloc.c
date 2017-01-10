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
        Block leftover;
        leftover.size = current->size - size - sizeof(Block);
        leftover.free = true;
        leftover.next = current->next;
        *((Block*) (current + size + sizeof(Block))) = leftover;

        current->size = size;
        current->free = false;
        current->next = (void*) (current + size + sizeof(Block));
    }

    return current;
}

void free(void* ptr)
{
    ((Block*) ptr)->free = true;
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
