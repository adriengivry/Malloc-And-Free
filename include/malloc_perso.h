#ifndef __MALLOC_PERSO__
#define __MALLOC_PERSO__

#define ALIGN(size) ((size) + (sizeof(size_t)-1)) & ~(sizeof(size_t)-1)

#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>

#include "util.h"

typedef struct s_block t_block;
struct s_block
{
    bool to_free;       // 1 byte
    size_t size;        // 8 bytes
    void* data;         // 8 bytes
    t_block* next;      // 8 bytes
    t_block* previous;  // 8 bytes
    
};

void initialize_block(t_block* block);
t_block* extend_heap(size_t size);
void* malloc_perso(size_t size);

#endif // __MALLOC_PERSO__