#include "../../include/memory/block.h"
#include "../../include/memory/shared.h"

void init_block(t_block* block)
{
    block->size = 0;
    block->next = NULL;
    block->previous = NULL;
    block->free = false;

    DEBUG_INFO("Init block : Done");
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

    DEBUG_INFO("Reset Block : Done");
    
    return data;
}

void* get_data(t_block* block)
{
    return (void*)(block + 1);
}

t_block* get_block(void* data)
{
    return ((t_block*)data) - 1;
}

t_block* extend_heap(size_t size)
{
    t_block* new_block = NULL;

        if (!get_break_addr((void**)&new_block))
        {
            DEBUG_ERROR("Extend heap : Unable to get break addr");
            return NULL;
        }

        sbrk(sizeof(t_block) + size);

        init_block(new_block);
        new_block->size = size;

        if (!head)
        {
            head = (void*)new_block;
        }
        else
        {
            t_block* current = (t_block*)head;

            while (current->next)
                iterate_block(&current);

            current->next = new_block;
            new_block->previous = current;
        }

    DEBUG_INFO("Extend heap : Done");

    return new_block;
}

t_block* find_block(size_t size)
{
    t_block* current = (t_block*)head;

    while (current)
    {
        if (current->size < size || !current->free)
            iterate_block(&current);
        else
        {
            DEBUG_INFO("Find block : Block found");
            return current->size > size ? split_block(current, size) : current;
        }
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

    splitted_block->free = true;
    splitted_block->previous->next = NULL;
    splitted_block->previous = block;
    splitted_block->next = block->next;
    block->next = splitted_block;


    DEBUG_INFO("Split block : Done");

    return block;
}

void try_to_fuse(t_block* block)
{
    if(block->previous && block->free && block->previous->free)
    {
        block->previous->size += sizeof(t_block) + block->size;

        if(block->next != NULL)
            block->next->previous = block->previous;

        block->previous->next = block->next;

        reset_block(block, 0, sizeof(t_block));
        DEBUG_INFO("Previous fuse : Done");
    }

    if(block->next && block->free && block->next->free)
    {
        block->size += sizeof(t_block) + block->next->size;

        if(block->next->next != NULL)
            block->next = block->next->next;

        block->previous->next = block->next;

        reset_block(block->next, 0, sizeof(t_block));
        DEBUG_INFO("Next fuse : Done");
    }
}

size_t count_allocated_blocks()
{
    size_t counter = 0;

    t_block* current = (t_block*)head;

    while (current)
    {
        ++counter;
        iterate_block(&current);
    }

    return counter;
}

size_t count_free_blocks()
{
    size_t counter = 0;

    t_block* current = (t_block*)head;

    while (current)
    {
        if (current->free)
            ++counter;
        iterate_block(&current);
    }

    return counter;
}