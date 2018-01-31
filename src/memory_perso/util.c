#include "../../include/memory_perso/util.h"

bool get_break_addr(void** break_addr)
{
    void* temp = sbrk(0);
    
    if (temp == (void*)-1)
        return false;
    
    *break_addr = temp;

    return true;
}