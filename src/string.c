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
/*************************************************************************/

char* strcat(char* destination, const char* source)
{
    char* originalDestination = destination;
    while (*destination) {destination++;}
    while ((*destination++ = *source++)) {}
    return originalDestination;
}

/* https://en.wikibooks.org/wiki/C_Programming/C_Reference/stdlib.h/itoa */

//TODO: remove for v2
static void reverse(char s[])
{
    int i, j;
    char c;
 
    for (i = 0, j = strlen(s) - 1; i < j; i++, j--)
    {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}

//TODO: remove for v2
char* itoa(s32 n, char* s)
{
    int i = 0, sign;
 
    /* record sign, make n positive */
    if ((sign = n) < 0) {n = -n;}

    /* generate digits in reverse order */
    do
    {
        s[i++] = n % 10 + '0';
    }
    while ((n /= 10) > 0);

    if (sign < 0) {s[i++] = '-';}
    s[i] = '\0';
    reverse(s);
    return s;
}

/*  memcpy and memset are defined in this way since sometimes the 
    compiler calls these functions automatically and it assumes
    the symbol is a function, not a function pointer */

static void* (*native_memcpy)(void*, const void*, size_t) = MEM_CPY_FPTR;
void* memcpy(void* destination, const void* source, size_t num)
{
    return native_memcpy(destination, source, num);
}

static void* (*native_memset)(void*, int, size_t) = MEM_SET_FPTR;
void* memset(void* ptr, int value, size_t num)
{
    return native_memset(ptr, value, num);
}

