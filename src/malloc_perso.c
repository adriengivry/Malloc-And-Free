#include "../include/malloc_perso.h"

void initialize_block(t_block* block)
{
    block->size = 0;
    block->next = NULL;
    block->previous = NULL;
    block->to_free = false;
}

t_block* extend_heap(size_t size)
{
    t_block* new_block = (t_block*)sbrk(size);
    initialize_block(new_block);

    new_block->size = size;
    if (first_block == NULL)
    {
        new_block->previous = NULL;
        new_block->next = NULL;
        first_block = new_block;
    }
    else
    {
        t_block* current = (t_block*)first_block;
        while (current->next)
        {
            current = current->next;
        }

        new_block->previous = current;
        current->next = new_block;
    }
    
    return new_block;
}

void* malloc_perso(size_t size)
{
    (void)size;
    // TODO: Implement malloc_perso
    return NULL;
}