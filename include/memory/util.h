#ifndef __UTIL__
#define __UTIL__

#include <stdbool.h>
#include <unistd.h>

/* 
    DEBUG MODES :
        0 : Disable all
        1 : Show errors
        2 : Show errors + success
        3 : Show errors + success + info
*/

#define DEBUG_MODE 3
#define DEBUG_INFO(string)      if (DEBUG_MODE >= 2) printf("\e[0;33m[DEBUG] %s\e[0m\n", string)
#define DEBUG_SUCCESS(string)   if (DEBUG_MODE >= 1) printf("\e[0;32m[DEBUG] %s\e[0m\n", string)
#define DEBUG_ERROR(string)     if (DEBUG_MODE >= 0) printf("\e[0;31m[DEBUG] %s\e[0m\n", string)

#define ALIGN(size) ((size) + (sizeof(size_t)-1)) & ~(sizeof(size_t)-1)

bool get_break_addr(void** break_addr);

#endif // __UTIL__