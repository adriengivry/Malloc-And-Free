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

    // If previous or next block is free --> fuse

    reset_block(ptr, 0, get_block(ptr)->size);

    get_block(ptr)->free = true;

    DEBUG_SUCCESS("Free : Success");
}