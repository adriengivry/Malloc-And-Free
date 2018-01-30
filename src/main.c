#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1

#include "../include/display.h"

int main(int argc, char** argv)
{
    (void)argc;
    (void)argv;

    print("Salut\n");
    
    return EXIT_SUCCESS;
}