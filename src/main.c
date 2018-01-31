#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1

#include <stdio.h>
#include <unistd.h>
#include <malloc.h>

#include "../include/memory_perso/memory_perso.h"

int main(int argc, char** argv)
{
    (void)argc;
    (void)argv;

    char* toto = (char*)malloc_perso(sizeof(char) * 5);

    *(toto + 0) = 'A';
    *(toto + 1) = 'B';
    *(toto + 2) = 'C';
    *(toto + 3) = 'D';
    *(toto + 4) = '\0';

    printf("toto is a char* containing : %s\n", toto);

    free_perso(toto);

    return EXIT_SUCCESS;
}