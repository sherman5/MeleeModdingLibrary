#ifndef CPU_LOGIC_H
#define CPU_LOGIC_H

#include <mml/logic.h>
#include <mml/ai.h>

/* General */
extern Logic resetOnHitLogic;
extern Logic resetOnWaitLogic;
extern Logic resetOnGroundLogic;
extern Logic resetAfterFrameLogic;
extern Logic resetOnDeathLogic;

/* Simple Program */
extern Logic respawnLogic;

/* Teching */
extern Logic hitTechLogic;
extern Logic getOffGroundLogic;
extern Logic actAfterTechLogic;

/* DI */
extern Logic hitDiLogic;
extern Logic throwDiLogic;
extern Logic stopThrowDiLogic;

extern AI cpuPlayer;

#endif
