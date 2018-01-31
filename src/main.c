#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1

#include <stdio.h>
#include <unistd.h>

#include "../include/memory_perso/memory_perso.h"

int main(int argc, char** argv)
{
    (void)argc;
    (void)argv;

    int* test;

    test = (int*)malloc_perso(sizeof(int));
    *test = 5;

    printf("Malloc perso result pointer : %p\n", test);
    printf("Malloc perso result value : %i\n", *test);

    free_perso(test);
    
    printf("Free perso result value : %i\n", *test);

    return EXIT_SUCCESS;
}