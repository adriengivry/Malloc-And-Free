#include "../../include/memory_perso/memory_block.h"

void iterate(t_block** block)
{
    *block = (*block)->next;
}
