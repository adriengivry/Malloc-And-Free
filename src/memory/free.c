#include "../../include/memory/free.h"

void free_perso(void* ptr)
{
    if (!ptr)
    {
        DEBUG_ERROR("Free : Ptr is NULL");
        return;
    }

    if (!get_block(ptr))
    {
        DEBUG_ERROR("Free : Block not found");
        return;
    }

    t_block* block = get_block(ptr);

    try_to_fuse(block);
    reset_block(ptr, 0, block->size);
    block->free = true;

    DEBUG_SUCCESS("Free : Success");
}