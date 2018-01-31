#include "../../include/memory_perso/free_perso.h"
#include "../../include/memory_perso/shared.h"

void free_perso(void* ptr)
{
    if (!ptr)
        return;

    t_block* current = (t_block*)first_block;

    while (current)
    {
        if (current->data == ptr)
        {
            current->to_free = true;
            for(size_t i = 0; i < current->size; ++i)
                ((char*)(current->data))[i] = 0;
        }
            
        current = current->next;
    }
}