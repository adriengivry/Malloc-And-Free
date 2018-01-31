#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1

#include <stdio.h>
#include <unistd.h>

#include "../include/malloc_perso.h"

int main(int argc, char** argv)
{
    (void)argc;
    (void)argv;

    void* brk_addr;
    if (get_break_addr(&brk_addr))
        printf("Current break adress : %p\n", brk_addr);
    else
        printf("Oups, sbrk failed\n");
    
    return EXIT_SUCCESS;
}