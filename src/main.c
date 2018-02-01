#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1

#include <stdio.h>

#include "../include/memory.h"

int main(int argc, char** argv)
{
    (void)argc;
    (void)argv;

    int* test1 = (int*)malloc_perso(sizeof(int));
    int* test2 = (int*)malloc_perso(sizeof(int));
    int* test3 = (int*)malloc_perso(sizeof(int));
    int* test4 = (int*)malloc_perso(sizeof(int));

    free_perso(test1);
    free_perso(test3);
    free_perso(test2);
    free_perso(test4);

    DEBUG_SUMMARY();

    return EXIT_SUCCESS;
}