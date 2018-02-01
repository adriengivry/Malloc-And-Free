#include "../../include/memory/block.h"
#include "../../include/memory/shared.h"

void init_block(t_block* block)
{
    block->size = 0;
    block->next = NULL;
    block->previous = NULL;
    block->free = false;
    block->data = NULL;
}

void iterate_block(t_block** block)
{
    *block = (*block)->next;
}

void* reset_block(void* data, int value, size_t size)
{
    unsigned char* tempData = (unsigned char*)data;

    while(size--)
        *(tempData++) = (unsigned char)value;
    
    return data;
}

t_block* extend_heap(size_t size)
{
    t_block* new_block = NULL;

        if (!get_break_addr((void**)&new_block))
            return NULL;

        sbrk(sizeof(t_block) + size);

        init_block(new_block);
        new_block->size = size;
        new_block->data = new_block + 1;

        if (!first_block)
        {
            first_block = (void*)new_block;
        }
        else
        {
            t_block* current = (t_block*)first_block;

            while (current->next)
            {
                iterate_block(&current);
            }

            current->next = new_block;
            new_block->previous = current;
        }

    return new_block;
}

t_block* find_block(size_t size)
{
    t_block* current = (t_block*)first_block;

    while (current)
    {
        if (current->size < size)
            iterate_block(&current);
        else 
            return current->size > size ? split_block(current, size) : current;
    }

    return NULL;
}

t_block* split_block(t_block* block, size_t size)
{
    size_t remaining_size = block->size - size;
    block->size = size;

    t_block* splitted_block = find_block(remaining_size);
    if (!splitted_block)
        splitted_block = extend_heap(remaining_size);

    return block;
}