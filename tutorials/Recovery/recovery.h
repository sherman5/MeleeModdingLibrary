#ifndef RECOVERY_H
#define RECOVERY_H

#include <mml/AI.h>
#include <mml/math.h>

void recovery(AI* ai);
void ledgeOption(AI* ai);

extern Point ledge;
extern Point coords;
extern float abs_x;
extern bool leftSide;
extern float stageDir;
extern u32 jumps;
extern u32 character;
extern s32 horizJump, vertJump;
extern s32 charHeight;

#endif




















