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
    // TODO: Implement extend_heap
    return NULL;
}

void* malloc_perso(size_t size)
{
    // TODO: Implement malloc_perso
    return NULL;
}