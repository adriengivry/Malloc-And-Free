#ifndef __MALLOC_PERSO__
#define __MALLOC_PERSO__

#define ALIGN(size) ((size) + (sizeof(size_t)-1)) & ~(sizeof(size_t)-1)

#include <unistd.h>

#include "util.h"
#include "memory_block.h"

void        initialize_block(t_block* block);
t_block*    extend_heap(size_t size);
void*       malloc_perso(size_t size);
t_block*    find_block(size_t size);

#endif // __MALLOC_PERSO__