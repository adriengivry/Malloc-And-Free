#ifndef __UTIL__
#define __UTIL__

#define ALIGN(size) ((size) + (sizeof(size_t)-1)) & ~(sizeof(size_t)-1)

#include <unistd.h>
#include <stdbool.h>

bool get_break_addr(void** break_addr);

#endif // __UTIL__