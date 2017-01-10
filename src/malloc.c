#include "malloc.h"

void initMalloc()
{
    Block b;
    b.size = HEAP_SIZE - sizeof(Block);
    b.free = true;
    b.next = NULL;

    *((Block*) HEAP_ADDRESS) = b;
}

void* malloc(size_t size)
{
    if (!initialized)
    {
        initMalloc();
    }

    Block* current = (Block*) HEAP_ADDRESS;
    bool defragged = false;
    
    while (current && (current->size < size || !current->free))
    {
        current = current->next;

        if (current == NULL && !defragged)
        {
            defragment();
            current = Block* HEAP_ADDRESS;
            defragged = true;
        }            
    }

    if (current != NULL)
    {
        
        Block leftover;
        leftover.size = current->size - size - sizeof(Block);
        leftover.free = true;
        leftover.next = current->next;
        *((void*) (current + size + sizeof(Block))) = leftover;

        current->size = size;
        current->free = 0;
        current->next = (void*) (current + size + sizeof(Block));
    }
    else
    {
        //malloc fails
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
