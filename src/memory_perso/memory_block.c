#include "../../include/memory_perso/memory_block.h"

void iterate(t_block** block)
{
    *block = (*block)->next;
}

void* my_memset(void* data, int value, size_t size)
{
    unsigned char* tempData = (unsigned char*)data;

    while(size--)
        *(tempData++) = (unsigned char)value;
    
    return data;
}

t_block* split_block(t_block* block, size_t size)
{
    (void)size;
    return block;
}

