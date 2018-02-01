#ifndef __UTIL__
#define __UTIL__

#include <stdbool.h>
#include <unistd.h>

/* 
    DEBUG MODES :
    0 : Disable all
    1 : Show summary + errors
    2 : Show summary + errors + success
    3 : Show summary + errors + success + info
*/

#define DEBUG_MODE 3
#define DEBUG_START(string)     if (DEBUG_MODE >= 2) printf("\e[0;35m[DEBUG] %s START\e[0m\n", string)
#define DEBUG_END(string)       if (DEBUG_MODE >= 2) printf("\e[0;35m[DEBUG] %s END\e[0m\n\n", string)
#define DEBUG_INFO(string)      if (DEBUG_MODE >= 2) printf("\e[0;33m[DEBUG] %s\e[0m\n", string)
#define DEBUG_SUCCESS(string)   if (DEBUG_MODE >= 1) printf("\e[0;32m[DEBUG] %s\e[0m\n", string)
#define DEBUG_ERROR(string)     if (DEBUG_MODE >= 0) printf("\e[0;31m[DEBUG] %s\e[0m\n", string)
#define DEBUG_SUMMARY()         if (DEBUG_MODE > 0)  printf("\e[0;36m[SUMMARY]\n  Block used : %lu\n  Block free : %lu\n[SUMMARY]\n\e[0m", count_allocated_blocks(), count_free_blocks())

#define ALIGN(size) ((size) + (sizeof(size_t)-1)) & ~(sizeof(size_t)-1)

bool get_break_addr(void** break_addr);

#endif // __UTIL__