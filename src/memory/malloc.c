#include "../../include/memory/malloc.h"

void* malloc_perso(size_t size)
{
    DEBUG_START("Malloc");

    if (size == 0)
    {
        DEBUG_ERROR("Malloc : Size given is 0");
        DEBUG_END("Malloc");
        return NULL;
    }

    size_t aligned_size = ALIGN(size);
    t_block* new_block = find_block(aligned_size);
    if (!new_block)
    {
        new_block = extend_heap(aligned_size);
        
    }

    if (!new_block)
    {
        DEBUG_ERROR("Malloc : Heap couldn't be extended");
    }
    else
    {
        DEBUG_SUCCESS("Malloc : Success");
    }

    DEBUG_END("Malloc");

    return !new_block ? NULL : get_data(new_block);
}