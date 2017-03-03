#ifndef CPU_LOGIC_H
#define CPU_LOGIC_H

#include <mml/logic.h>
#include <mml/AI.h>

extern Logic respawnLogic;
extern Logic resetOnDeathLogic;

extern Logic hitTechLogic;
extern Logic getOffGroundLogic;
extern Logic resetOnHitLogic;
extern Logic resetOnWaitLogic;
extern Logic actAfterTechLogic;
extern Logic resetOnGroundLogic;

extern Logic hitDiLogic;
extern Logic throwDiLogic;
extern Logic stopThrowDiLogic;
extern Logic resetAfterFrameLogic;

extern Logic recoveryLogic;
extern Logic onLedgeLogic;
extern Logic resetOnStageLogic;
extern Logic doubleJumpRecoveryLogic;
extern Logic illusionRecoveryLogic;
extern Logic fireRecoveryLogic;
extern Logic postFireLogic;
extern Logic marthDoubleJumpLogic;
extern Logic marthUpBLogic;

extern Logic exitHitstunLogic;
extern Logic actOutOfHitstunLogic;

extern AI cpuPlayer;

#endif
