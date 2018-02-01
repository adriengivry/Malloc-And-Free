#include "../../include/memory_perso/memory_block.h"

void iterate(t_block** block)
{
    *block = (*block)->next;
}

t_block* split_block(t_block* block, size_t size)
{
    (void)size;
    return block;
}