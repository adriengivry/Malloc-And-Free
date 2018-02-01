#include "../../include/memory/malloc.h"

void* malloc_perso(size_t size)
{
    if (size == 0)
        return NULL;

    size_t aligned_size = ALIGN(size);
    t_block* new_block = find_block(aligned_size);
    if (!new_block)
    {
        new_block = extend_heap(aligned_size);
    }

    return !new_block ? NULL : new_block->data;
}