#include <stdbool.h>
#include "string.h"
#include "melee.h"

/* get addresses of functions */
void*    (*memchr)(const void*, int, size_t)          = MEM_CHR_FPTR;
int      (*memcmp) (const void*, const void*, size_t) = MEM_CMP_FPTR;
void*    (*memcpy) (void*, const void*, size_t)       = MEM_CPY_FPTR;
void*    (*memset) (void*, int, size_t)               = MEM_SET_FPTR;
char*    (*strchr) (const char*, int)                 = STR_CHR_FPTR;
int      (*strcmp) (const char*, const char*)         = STR_CMP_FPTR;
int      (*strncmp)(const char*, const char*, size_t) = STRN_CMP_FPTR;
char*    (*strcpy) (char*, const char*)               = STR_CPY_FPTR;
char*    (*strncpy)(char*, const char*, size_t)       = STRN_CPY_FPTR;
size_t   (*strlen) (const char*)                      = STR_LEN_FPTR;
uint32_t (*strtoul)(const char*, char**, int)         = STR_TO_UL_FPTR;
char*    (*itoa)   (int32_t, char*, int)              = ITOA_FPTR;

/* variables needed for print stream */
static bool initialized = false;
static char* mStream;
static unsigned mSize, mPos; // size of stream, and current position

/* spoof input for debug menu creator */
//static uint32_t spoofMenu[9] = {0, 0, &stream, 0, 0, 0, 0, 0, 9};

void initStream(char* stream, unsigned size)
{
    mStream = stream;
    mSize = size;
    mPos = 0;
    initialized = true;
}

void print(const char* str)
{
    if (initialized && mPos + strlen(str) < 1000)
    {
        mStream[mPos] = *str;
        mPos += strlen(str);
    }
}

/* create the display where print sends output, should never 
   be called by user. Instead, user branches to this symbol
   when display should be shown (i.e. tournament mode is selected) */
void CreateDisplay()
{
    



}
