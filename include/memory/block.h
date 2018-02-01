#ifndef __BLOCK__
#define __BLOCK__

#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>

#include "util.h"

typedef struct s_block t_block;

struct s_block
{
    bool        free;           // 1 byte
    size_t      size;           // 8 bytes
    t_block*    next;           // 8 bytes
    t_block*    previous;       // 8 bytes
};

void        init_block(t_block* block);
void        iterate_block(t_block** block);
void*       reset_block(void* data, int value, size_t size);
void*       get_data(t_block* block);
t_block*    get_block(void* data);
t_block*    extend_heap(size_t size);
t_block*    find_block(size_t size);
t_block*    split_block(t_block* block, size_t size);
size_t      count_allocated_blocks();
size_t      count_free_blocks();

#endif // __BLOCK__