#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1

#include <stdio.h>

#include "../include/memory.h"

int main(int argc, char** argv)
{
    (void)argc;
    (void)argv;

    ALLOC_TEST(int,             toto1, 1);
    ALLOC_TEST(char,            toto2, 5);
    ALLOC_TEST(unsigned int,    toto3, 1);
    ALLOC_TEST(float,           toto4, 1);
    ALLOC_TEST(double,          toto5, 3);

    DEBUG_SUMMARY();

    return EXIT_SUCCESS;
}