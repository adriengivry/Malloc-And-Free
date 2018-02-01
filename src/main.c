#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1

#include <stdio.h>

#include "../include/memory.h"

int main(int argc, char** argv)
{
    (void)argc;
    (void)argv;

    char* toto = (char*)malloc_perso(sizeof(char) * 20);
    free_perso(toto);

    printf("\n");

    char* toto2 = (char*)malloc_perso(sizeof(char) * 20);
    free_perso(toto2);

    printf("\n");

    char* toto3 = (char*)malloc_perso(sizeof(char) * 5);
    free_perso(toto3);

    printf("\e[0;36m[SUMMARY] Blocks : %lu\e[0m\n", count_allocated_blocks());
    printf("\e[0;36m[SUMMARY] Blocks free : %lu\e[0m\n", count_free_blocks());

    return EXIT_SUCCESS;
}