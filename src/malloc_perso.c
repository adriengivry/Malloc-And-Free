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
    (void)size;

    t_block* new_block = (t_block*)sbrk(0);
    
    return new_block;
}

void* malloc_perso(size_t size)
{
    (void)size;
    // TODO: Implement malloc_perso
    return NULL;
}