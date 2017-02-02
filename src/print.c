#include <stdint.h>
#include "string.h"
#include "system.h"
#include "print.h"

#define CHAR_PER_LINE 60
#define SIZEOF_MENU_ITEM (8 * sizeof(uint32_t))

/* variables needed for print stream */
static int user_init = 0;
static char* stream;
static uint32_t* menu;
static unsigned streamSize, menuSize = 0, menuPos;

void menuSetup()
{
    /* add stream pointer to each menu "struct" */
    for (unsigned i = 0; i < menuSize - 1; ++i)
    {
        menu[8 * i + 0] = 1;
        menu[8 * i + 2] = (uint32_t) stream + (4 + CHAR_PER_LINE) * i;
    }
    menu[8 * (menuSize - 1)] = 9; //mark the end of the menu
}

void initStream(char* mem, unsigned size)
{
    /* find portion for menu and stream (1 : 2 ratio) */
    unsigned menuBytes = 32 + (int) (size - 32) / 3;
    menuSize = menuBytes / 32;    
    menuBytes = 32 * menuSize;
    streamSize = size - menuBytes;

    /* set addresses of menu and stream, initialize to zero */
    menu = (uint32_t*) mem;
    stream = mem + menuBytes;
    memset(menu, 0, menuBytes);
    memset(stream, 0, size - menuBytes);
    menuPos = 0;

    /* setup menu and record that initialization has occured */
    menuSetup();
    user_init = 1;
}

void initWithMalloc()
{
    menuSize = 10;
    menuPos = 0;
    streamSize = (4 + CHAR_PER_LINE) * (menuSize - 1 + 2);

    stream = calloc(1, streamSize);
    menu = calloc(menuSize, SIZEOF_MENU_ITEM);
    
    menuSetup();
}

void print(const char* str)
{
    if (user_init)
    {
        unsigned len = strlen(str);
        unsigned lines = 0;
        while (CHAR_PER_LINE * lines < len && menuPos < menuSize - 1)
        {
            strncpy(stream + (4 + CHAR_PER_LINE) * menuPos,
                str + CHAR_PER_LINE * lines, CHAR_PER_LINE);
            menuPos++;
            lines++;
        }
    }
    else
    {
        if (menuSize == 0) {initWithMalloc();}

        unsigned len = strlen(str);
        unsigned lines = 0;

        if (menuPos + 1 + len / CHAR_PER_LINE >= menuSize)
        {
            size_t new_size = menuPos + len / CHAR_PER_LINE + 2;
            menu = realloc(menu, menuSize * SIZEOF_MENU_ITEM,
                new_size * SIZEOF_MENU_ITEM);
            menuSize = new_size;
            menuSetup();
        }

        if ((CHAR_PER_LINE + 4) * (menuSize - 1) > streamSize)
        {
            size_t new_size = (CHAR_PER_LINE + 4) * (menuSize - 1);
            stream = realloc(stream, streamSize, new_size);
            streamSize = new_size;
        }

        while (CHAR_PER_LINE * lines < len)
        {
            strncpy(stream + (4 + CHAR_PER_LINE) * menuPos,
                str + CHAR_PER_LINE * lines, CHAR_PER_LINE);
            menuPos++;
            lines++;
        }
    }        
}

/* create the display where print sends output, should never 
   be called by user. Instead, user branches to this symbol
   when display should be shown (i.e. tournament mode is selected) */
void CreateDisplay()
{
    if (menuSize > 0) {*((uint32_t**) 0x804d6890) = menu;}
}

