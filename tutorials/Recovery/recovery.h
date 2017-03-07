#ifndef RECOVERY_H
#define RECOVERY_H

#include <mml/ai.h>
#include <mml/math.h>

void recover(AI* ai);
void ledgeOption(AI* ai);
void doubleJump(AI* ai, float target);
void doubleJumpRecovery(AI* ai);
void addCleanUpLogic(AI* ai);
void setGlobalVariables(AI* ai);

typedef struct
{
    Point ledge;
    Point coords;
    float abs_x;
    float dist;
    bool leftSide;
    float stageDir;
    u32 jumps;
    u32 character;
    s32 horizJump, vertJump;
    s32 charHeight;

} RecoveryInfo;

extern RecoveryInfo rInfo;

#endif




















