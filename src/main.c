#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1

#include <stdio.h>
#include <unistd.h>

int main(int argc, char** argv)
{
    (void)argc;
    (void)argv;

    printf("Result of sbrk : %p\n", sbrk(1));
    printf("Result of sbrk : %p\n", sbrk(1000));
    
    return EXIT_SUCCESS;
}