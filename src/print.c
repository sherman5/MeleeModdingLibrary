#include "string.h"
#include "system.h"
#include "print.h"
#include "math.h"
#include "gctypes.h"

#define LINE_SIZE 60
#define MAX_LINES 27

typedef struct menu_line
{
    char text[LINE_SIZE];
    u32 pad;
} MenuLine;

typedef struct debug_menu_slot
{
    u32 type;
    char pad1[0x04];
    MenuLine* line;
    char pad2[0x14];

} DebugMenuSlot;

#define MENU_SLOT(t, l) {(t), {0}, (l), {0}}

static MenuLine* stream = NULL;
static DebugMenuSlot* menu = NULL;
static u8 numLines = 0, maxLines = 0;

void print(const char* str)
{
    /* calculate number of lines this string will use */
    u8 strLines = 1 + strlen(str) / LINE_SIZE;

    /* calculate max lines */
    maxLines = (getHeapSize() / 5)
        / (sizeof(MenuLine) + sizeof(DebugMenuSlot));
    maxLines = imin(maxLines, MAX_LINES);

    /* discard extra lines */
    if (numLines + strLines > maxLines)
    {
        u8 discard = numLines + strLines - maxLines;
        numLines -= discard;

        memcpy(menu, menu + discard, numLines * sizeof(DebugMenuSlot));
        memcpy(stream, stream + discard, numLines * sizeof(MenuLine));
    }

    //TODO: handle malloc fail 
    /* resize menu and stream arrays */
    menu = realloc(menu, (numLines + strLines + 1) * sizeof(DebugMenuSlot));
    stream = realloc(stream, (numLines + strLines) * sizeof(MenuLine));

    /* copy string to stream */
    for (unsigned i = 0; i < strLines; ++i)
    {
        memset(stream + numLines, 0, sizeof(MenuLine));
        strncpy((char*) (stream + numLines), str + LINE_SIZE * i, LINE_SIZE);
        numLines++;
    }

    /* create debug menu */
    for (unsigned i = 0; i < numLines; ++i)
    {
        DebugMenuSlot tempSlot = MENU_SLOT(1, stream + i);
        memcpy(menu + i, &tempSlot, sizeof(DebugMenuSlot));
    }        

    /* mark the end of the menu */
    DebugMenuSlot tempSlot = MENU_SLOT(9, NULL);
    memcpy(menu + numLines, &tempSlot, sizeof(DebugMenuSlot));
}

void clear()
{
    numLines = 0;
}

/*
    create the display where print sends output, should never 
    be called by user. Instead, user branches to this symbol
    at 0x801a633c
*/
void _display()
{
    if (numLines == 0)
    {
        stream = malloc(sizeof(MenuLine));
        memset(stream, 0, sizeof(MenuLine));
 
        menu = malloc(sizeof(DebugMenuSlot));   
        DebugMenuSlot tempSlot_1 = MENU_SLOT(1, stream);
        DebugMenuSlot tempSlot_2 = MENU_SLOT(9, NULL);

        memcpy(menu, &tempSlot_1, sizeof(DebugMenuSlot));
        memcpy(menu + 1, &tempSlot_2, sizeof(DebugMenuSlot));
    }    
    *((DebugMenuSlot**) 0x804d6890) = menu;
}

