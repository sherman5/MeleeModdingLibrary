#include "profile.h"
#include "native_functions.h"
#include "print.h"

u32 (*OSGetTime)(void) = OS_GET_TIME_FPTR;
u32 (*OSGetTick)(void) = OS_GET_TICK_FPTR;
u32 (*OSGetSystemTime)(void) = OS_GET_SYSTEM_TIME_FPTR;
u32 (*OSTimeToSystemTime)(void) = OS_TIME_TO_SYSTEM_TIME_FPTR;

void startTrial(Profile* prof)
{
    prof->startTick = OSGetTick();
}

void endTrial(Profile* prof)
{
    if (prof->startTick != 0)
    {
        u32 diff = OSGetTick() - prof->startTick;

        prof->avgTicks = (prof->avgTicks * prof->numTrials + diff)
            / (prof->numTrials + 1);

        if (diff > prof->maxTicks) {prof->maxTicks = diff;}
        if (diff < prof->minTicks) {prof->minTicks = diff;}

        prof->numTrials++;
    }
}

void printProfile(Profile* prof)
{
    printInt("Average Ticks:   ", prof->avgTicks);
    printInt("Max Ticks:   ", prof->maxTicks);
    printInt("Min Ticks:   ", prof->minTicks);
}
