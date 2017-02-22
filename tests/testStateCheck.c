#include <logic.h>
#include <state_check.h>
#include <unit_test.h>
#include <system.h>
#include <string.h>
#include <game_state.h>
#include <logic.h>

UNIT_TEST;

static bool init_run = false;
static char heap[15000];

static bool tests_run = false;

void init(void)
{
    initHeap(heap, heap + sizeof(heap));
    init_run = true;
}

void _main(void)
{
    if (!init_run) {init();}

    if (!tests_run && inGame())
    {
        unsigned sum = 0;

        Logic logic = {
            (Function) {&chance, .arg1.f = 1.f / 2.f, 0},
            (Function) {NULL, 0, 0}
        };

        bool (*c)(FunctionArg, FunctionArg)
            = logic.condition.function;
        
        for (unsigned i = 0; i < 10000; i++)
        {
            if (c(logic.condition.arg1, logic.condition.arg2)) {sum++;}
        }

        char buffer[128];
        memset(buffer, 0, sizeof(buffer));
        itoa(sum, buffer);
        print(buffer);

        REQUIRE(sum > 4000);
        REQUIRE(sum < 6000);

        tests_run = true;
        END_TEST;
    }
}


