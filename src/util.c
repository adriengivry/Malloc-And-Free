#include "../include/util.h"

bool get_break_addr(void** p_break_addr)
{
    void* temp = sbrk(0);
    
    if (temp == (void*)-1)
        return false;
    
    *p_break_addr = temp;

    return true;
}