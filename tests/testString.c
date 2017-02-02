#include <math.h>
#include <melee.h>
#include <string.h>
#include <stdbool.h>
#include <system.h>
#include <print.h>

static char stream[600];
static int init = 0;
static char str[100];
static char* allocStr;

void initTestString()
{
    memset(str, 0, sizeof(str));
    strcat(str, "this is a test of how strings are wrapped when they are");
    strcat(str, " too long for a single line");

    char* temp = "this string is stored on the heap"; 
    allocStr = malloc(40);
    memset(allocStr, 0, 40);
    strncpy(allocStr, temp, 40 - 1);
}
 
void _main()
{
//    if (!init) {initTestString(); init = true;}
//    memset(stream, 0, sizeof(stream));
//    initStream(stream, 600);
    if (!init) {
    print("this is a test sentence to see how many characters fit");
    print("this is a test of multiple calls to print");
    init = 1;
    }
//    print(str);
//    print(allocStr);
}

