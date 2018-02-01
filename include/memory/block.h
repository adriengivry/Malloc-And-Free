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
    void*       data;           // 8 bytes
    t_block*    next;           // 8 bytes
    t_block*    previous;       // 8 bytes
};

void        init_block(t_block* block);
void        iterate_block(t_block** block);
void*       reset_block(void* data, int value, size_t size);
t_block*    extend_heap(size_t size);
t_block*    find_block(size_t size);
t_block*    split_block(t_block* block, size_t size);

#endif // __BLOCK__