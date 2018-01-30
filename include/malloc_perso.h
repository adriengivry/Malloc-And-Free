#ifndef __MALLOC_PERSO__
#define __MALLOC_PERSO__

#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>

typedef struct s_block t_block;
struct s_block
{
    size_t size;
    t_block* next;
    t_block* previous;
    bool to_free;
};

extern void* first_block;

void initialize_block(t_block* block);
t_block* extend_heap(size_t size);
void* malloc_perso(size_t size);

#endif // __MALLOC_PERSO__