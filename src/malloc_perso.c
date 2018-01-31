#include "../include/malloc_perso.h"

void* first_block = NULL;

void initialize_block(t_block* block)
{
    block->size = 0;
    block->next = NULL;
    block->previous = NULL;
    block->to_free = false;
}

t_block* extend_heap(size_t size)
{
    t_block* new_block = NULL;

        if (!get_break_addr((void**)&new_block))
            return NULL;

        sbrk(sizeof(t_block) + size);

        initialize_block(new_block);
        new_block->size = size;

        if (!first_block)
        {
            first_block = (void*)new_block;
        }
        else
        {
            t_block* current = (t_block*)first_block;

            while (current->next)
            {
                current = current->next;
            }

            current->next = new_block;
            new_block->previous = current;
        }

    return new_block;
}

void* malloc_perso(size_t size)
{
    (void)size;
    // TODO: Implement malloc_perso
    return NULL;
}