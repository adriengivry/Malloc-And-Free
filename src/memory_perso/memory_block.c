#include "../../include/memory_perso/memory_block.h"

void iterate(t_block** block)
{
    *block = (*block)->next;
}

void* my_memset(void* data, int value, size_t size)
{
    for(size_t i = 0; i < size; ++i)
        ((unsigned char*)(data))[i] = (unsigned char)value;
    
    return data;
}

t_block* split_block(t_block* block, size_t size)
{
    (void)size;
    return block;
}

