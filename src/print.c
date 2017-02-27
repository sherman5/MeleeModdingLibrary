#include "string.h"
#include "system.h"
#include "print.h"
#include "math.h"
#include "gctypes.h"
#include "error.h"

#define LINE_SIZE 60
#define MAX_LINES 27

typedef struct
{
    char text[LINE_SIZE];
    u32 pad;

} MenuLine;

typedef struct
{
    u32 type;
    char pad1[0x04];
    MenuLine* line;
    char pad2[0x14];

} DebugMenuSlot;

#define MENU_SLOT(t, l) {(t), {0}, (l), {0}}
#define SLOT_SIZE  (sizeof(MenuLine) + sizeof(DebugMenuSlot))

/* initialize stream variables */
bool _errorState = false;
static MenuLine* stream = NULL;
static DebugMenuSlot* menu = NULL;
static size_t numLines = 0, maxLines = 0;
static size_t capacity = 0;

/* guarantees menu exists, also used when an error occurs */
static MenuLine staticLine1 = {{0}, 0};
static MenuLine staticLine2 = {{0}, 0};
static DebugMenuSlot staticMenu[3] =
{
    MENU_SLOT(1, &staticLine1),
    MENU_SLOT(1, &staticLine2),
    MENU_SLOT(9, NULL)
};

void print(const char* str)
{   
    /* stop printing once error is thrown */
    if (_errorState) { return; }

    /* calculate number of lines this string will use */
    size_t strLines = 1 + strlen(str) / LINE_SIZE;

    /* calculate max lines */
    maxLines = imin((getHeapSize() / 5) / SLOT_SIZE, MAX_LINES);

    /* don't print strings that are too large */
    if (strLines > maxLines) {THROW_ERROR("string too large"); return;}

    /* discard extra lines */
    if (numLines + strLines > maxLines)
    {
        size_t discard = numLines + strLines - maxLines;
        numLines -= discard;

        memcpy(menu, menu + discard, numLines * sizeof(DebugMenuSlot));
        memcpy(stream, stream + discard, numLines * sizeof(MenuLine));
    }

    /* resize menu and stream arrays */
    if (numLines + strLines > capacity)
    {
        capacity = imin(numLines + strLines + 5, MAX_LINES);
        menu = realloc(menu, (capacity + 1) * sizeof(DebugMenuSlot));
        stream = realloc(stream, capacity * sizeof(MenuLine));

        /* check if allocation failed */
        if (!menu || !stream)
        {
            THROW_ERROR("failed allocation");
            return;
        }
    }

    /* copy string to stream */
    for (unsigned i = 0; i < strLines; ++i)
    {
        memset(stream + numLines, 0, sizeof(MenuLine));
        strncpy((char*) (stream + numLines), str + LINE_SIZE * i,
            LINE_SIZE);
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

//TODO: solve the array out of bounds error (happens with -O3)
#pragma GCC push_options
#pragma GCC optimize ("-O0")
void error(const char* errMessage)
{
    _errorState = true;
    strncpy(staticLine1.text, errMessage, LINE_SIZE);
    if (strlen(errMessage) > LINE_SIZE)
    {
        strncpy(staticLine2.text, errMessage + LINE_SIZE, LINE_SIZE);
    }
    numLines = 0;
}
#pragma GCC pop_options

void clear()
{
    numLines = 0;
}

void display() 
{
    if (numLines == 0)
    {
        menu = staticMenu;
    }    
    *((DebugMenuSlot**) 0x804d6890) = menu;
}

