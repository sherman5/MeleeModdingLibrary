#include "malloc.h"

void init_heap(Heap* heap, void* mem_address, size_t size) {

    heap->blockLL = mem_address;
    heap->blockLL->size = size - sizeof(struct block);
    heap->blockLL->free = 1;
    heap->blockLL->next = NULL;

}

void* malloc(Heap* heap, size_t size) {

    struct block* current = heap->blockLL;
    int defragged = 0;
    
    while (current->size < size || !current->free) {

        current = current->next;

        if (current == NULL && defragged == 0) {

            defragment(heap);
            current = heap->blockLL;
            defragged = 1;

        }            

    }

    if (current != NULL) {

        struct block* new_block;
        new_block = (void*) ((void*) current + size + sizeof(struct block));

        new_block->size = current->size - size - sizeof(struct block);
        new_block->free = 1;
        new_block->next = current->next;

        current->size = size;
        current->free = 0;
        current->next = new_block;

    }

    return current;

}

void free(void* ptr) {

    ((struct block*) ptr)->free = 1;

}

void defragment(Heap* heap) {

    struct block* current = heap->blockLL;

    while (current->next != NULL) {

        if (current->free && current->next->free) {

            current->size += current->next->size + sizeof(struct block);
            current->next = current->next->next;

        } else {

            current = current->next;

        }

    }

}
