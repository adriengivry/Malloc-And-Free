#include "../include/display.h"

void print_c(char c)
{
    fwrite(&c, sizeof(c), 1, stdout);
}

void print(char const* str)
{
    for (unsigned int i = 0; str[i++] != STRING_END;)
        print_c(str[i - 1]);
}