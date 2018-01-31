#ifndef __MEMORY_BLOCK__
#define __MEMORY_BLOCK__

#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>

typedef struct s_block t_block;

struct s_block
{
    bool        to_free;        // 1 byte
    size_t      size;           // 8 bytes
    void*       data;           // 8 bytes
    t_block*    next;           // 8 bytes
    t_block*    previous;       // 8 bytes
};

void iterate(t_block** block);

#endif // __MEMORY_BLOCK__