#include "../../include/memory/free.h"
#include "../../include/memory/shared.h"

void free_perso(void* ptr)
{
    if (!ptr)
        return;

    t_block* current = (t_block*)first_block;

    while (current)
    {
        if (current->data == ptr)
        {
            current->free = true;
            reset_block(current->data, 0, current->size);
        }
            
        current = current->next;
    }
}