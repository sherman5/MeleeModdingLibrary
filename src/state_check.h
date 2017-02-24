/**
 * @file state_check.h
 * @brief Check game states.
 *
 */

#ifndef MML_STATE_CHECK_H
#define MML_STATE_CHECK_H

#include "gctypes.h"
#include "logic.h"

bool offstage(FunctionArg port);
bool chance(FunctionArg prob);
bool inHitstun(FunctionArg port);
bool inHitlag(FunctionArg port);
bool belowHeight(FunctionArg port, FunctionArg height);
bool inAir(FunctionArg port);
bool onGround(FunctionArg port);
bool actionStateEq(FunctionArg port, FunctionArg state);
bool actionStateGeq(FunctionArg port, FunctionArg state);
bool actionStateLeq(FunctionArg port, FunctionArg state);
bool chance(FunctionArg prob);
bool nearSurface(FunctionArg port);
bool techSituation(FunctionArg port);
bool hitlagFrames(FunctionArg port, FunctionArg frames);
bool recoverySituation(FunctionArg port);
bool fallenDown(FunctionArg port);
bool hitlagFrame(FunctionArg port, FunctionArg frame);

#endif
