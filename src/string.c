#include <stdbool.h>
#include "string.h"
#include "melee.h"

/*************************** built in functions **************************/
void*    (*memchr)  (const void*, int, size_t)         = MEM_CHR_FPTR;
int      (*memcmp)  (const void*, const void*, size_t) = MEM_CMP_FPTR;
void*    (*memcpy)  (void*, const void*, size_t)       = MEM_CPY_FPTR;
void*    (*memset)  (void*, int, size_t)               = MEM_SET_FPTR;
char*    (*strchr)  (const char*, int)                 = STR_CHR_FPTR;
int      (*strcmp)  (const char*, const char*)         = STR_CMP_FPTR;
int      (*strncmp) (const char*, const char*, size_t) = STRN_CMP_FPTR;
char*    (*strcpy)  (char*, const char*)               = STR_CPY_FPTR;
char*    (*strncpy) (char*, const char*, size_t)       = STRN_CPY_FPTR;
size_t   (*strlen)  (const char*)                      = STR_LEN_FPTR;
uint32_t (*strtoul) (const char*, char**, int)         = STR_TO_UL_FPTR;
char*    (*itoa)    (int32_t, char*, int)              = ITOA_FPTR;
/*************************************************************************/


/* variables needed for print stream */
static bool initialized = false;
static char* stream;
static uint32_t* menu;
static unsigned totalBytes, menuSize, menuPos;

#define CHAR_PER_LINE 60

void initStream(char* mem, unsigned size)
{
    /* find portion for menu and stream (1 : 2 ratio) */
    totalBytes = size;
    unsigned menuBytes = 32 + (int) (totalBytes - 32) / 3;
    menuSize = menuBytes / 32;    
    menuBytes = 32 * menuSize;

    /* set addresses of menu and stream, initialize to zero */
    menu = (uint32_t*) mem;
    stream = mem + 0x4 * menuBytes;
    memset(menu, 0, menuBytes);
    memset(stream, 0, totalBytes - menuBytes);
    menuPos = 0;
    
    /* add stream pointer to each menu "struct" */
    for (unsigned i = 0; i < menuSize - 1; ++i)
    {
        menu[8 * i + 0] = 1;
        menu[8 * i + 2] = (uint32_t) stream + CHAR_PER_LINE * i;
    }
    menu[8 * (menuSize - 1)] = 9; //mark the end of the menu

    initialized = true;
}

void print(const char* str)
{
    if (initialized)
    {
        strcpy(stream + CHAR_PER_LINE * menuPos, str);
        menuPos++;
    }
}

/* create the display where print sends output, should never 
   be called by user. Instead, user branches to this symbol
   when display should be shown (i.e. tournament mode is selected) */
void CreateDisplay()
{
    if (!initialized && menuSize == 0) {/* initialize with malloc*/}
    *((uint32_t**) 0x804d6890) = menu;
}

