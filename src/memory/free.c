#include "../../include/memory/free.h"

void free_perso(void* ptr)
{
    DEBUG_START("Free");

    if (!ptr)
    {
        DEBUG_ERROR("Free : Ptr is NULL");
        DEBUG_END("Free");
        return;
    }

    if (!get_block(ptr))
    {
        DEBUG_ERROR("Free : Block not found");
        DEBUG_END("Free");
        return;
    }

    t_block* block = get_block(ptr);

    block->free = true;
    try_to_fuse(block);
    reset_block(ptr, 0, block->size);

    DEBUG_SUCCESS("Free : Success");

    DEBUG_END("Free");
}