#include <math.h>
#include <string.h>
#include <system.h>
#include <print.h>
#include <gctypes.h>
#include <error.h>

static char heap[15000];
static bool init = false;
//static char str[100];

void _main()
{
    if (!init) {

        initHeap(heap, heap + sizeof(heap));

print("One of the coolest features of this library is the ability to print text in the game. This allows for error reporting, unit testing, and more tools for debugging your code. Perhaps the most important thing is that debugging tools are now available on the Wii/GameCube. Previously, all of the debugging had to be done in Dolphin, and if your mod didn't work in the Wii is was all up to guesswork to diagnose the problem.");

/*        memset(str, 0, sizeof(str));
        strcat(str, "this is a test of how strings are wrapped when");
        strcat(str, " they are too long for a single line");

        print("this is a test sentence to see how many characters fit");
        print("this is a test of multiple calls to print");
        print(str);
        print("print first extra string");
        print("print second extra string");
        print("print third extra string");
        print("print fourth");
        print("print fifth");
        print("line 10");
        print("line 11");
        print("line 12");
        print("line 13");
        print("line 14");
        print("line 15");
        print("line 16");
        print("line 17");
        print("line 18");
        print("line 19");
        print("line 20");
        print("line 21");
        print("line 22");
        print("line 23");
        print("line 24");
        print("line 25");
        print("line 26");
        print("line 27");
        print("line 28");
        print("line 29");
        print("line 30");
        print("line 31");
        THROW_ERROR("test error taking up multiple lines of output blah blah");
        print("line 31");*/
        init = true;
    }
}

