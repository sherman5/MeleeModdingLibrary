#include "string.h"
#include "native_functions.h"
#include "system.h"
#include "gctypes.h"

/*************************** built in functions **************************/
void*    (*memchr)  (const void*, int, size_t)         = MEM_CHR_FPTR;
int      (*memcmp)  (const void*, const void*, size_t) = MEM_CMP_FPTR;
char*    (*strchr)  (const char*, int)                 = STR_CHR_FPTR;
int      (*strcmp)  (const char*, const char*)         = STR_CMP_FPTR;
int      (*strncmp) (const char*, const char*, size_t) = STRN_CMP_FPTR;
char*    (*strcpy)  (char*, const char*)               = STR_CPY_FPTR;
char*    (*strncpy) (char*, const char*, size_t)       = STRN_CPY_FPTR;
size_t   (*strlen)  (const char*)                      = STR_LEN_FPTR;
uint32_t (*strtoul) (const char*, char**, int)         = STR_TO_UL_FPTR;
char*    (*itoa)    (int32_t, char*, int)              = ITOA_FPTR;
/*************************************************************************/

char* strcat(char* destination, const char* source)
{
    char* originalDestination = destination;
    while (*destination) {destination++;}
    while ((*destination++ = *source++)) {}
    return originalDestination;
}

/*
    memcpy and memset are defined in this way since sometimes the 
    compiler calls these functions automatically and it assumes
    the symbol is a function, not a function pointer
*/

void* memcpy(void* destination, const void* source, size_t num)
{
    void* (*f)(void*, const void*, size_t) = MEM_CPY_FPTR;
    return f(destination, source, num);
}

void* memset(void* ptr, int value, size_t num)
{
    void* (*f)(void*, int, size_t) = MEM_SET_FPTR;
    return f(ptr, value, num);
}

