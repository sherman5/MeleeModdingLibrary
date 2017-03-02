#ifndef RECOVERY_H
#define RECOVERY_H

#include <mml/AI.h>
#include <mml/math.h>

void recover(AI* ai);
void ledgeOption(AI* ai);
void doubleJump(AI* ai);
void addCleanUpLogic(AI* ai);

typedef struct
{
    Point ledge;
    Point coords;
    float abs_x;
    bool leftSide;
    float stageDir;
    u32 jumps;
    u32 character;
    s32 horizJump, vertJump;
    s32 charHeight;

} RecoveryInfo;

extern RecoveryInfo rInfo;

#endif




















