/**
 * @file profile.h
 * @brief Measure performance of code
 */

#ifndef MML_PROFILE_H
#define MML_PROFILE_H

#include "gctypes.h"

/** @brief key information about code performance */
typedef struct
{
    u32 maxTicks; /**< maximum number of ticks elapsed */
    u32 minTicks; /**< minimum number of ticks elapsed */
    u32 avgTicks; /**< average number of ticks elapsed */

    u32 numTrials; /**< number of trials recorded */

    u32 startTick; /**< used locally for measuring (end - start) */

} Profile;

/** Use to initialize Profile struct */
#define DEFAULT_PROFILE {0, 0xFFFFFFFF, 0, 0, 0}

/** @cond */
extern u32 (*OSGetTime)(void);
extern u32 (*OSGetTick)(void);
extern u32 (*OSGetSystemTime)(void);
extern u32 (*OSTimeToSystemTime)(void);

#if 0
/// @endcond

#endif

/**
 * @brief Start timing your code
 *
 * @param prof - Pointer to a profile
 * @return None
 */
void startTrial(Profile* prof);

/**
 * @brief Finish timing your code
 *
 * @param prof - Pointer to a profile
 * @return None
 */
void endTrial(Profile* prof);

/**
 * @brief Print stats about your code performance
 * @ingroup CallMalloc
 *
 * @param prof - Pointer to a profile
 * @return None
 */
void printProfile(Profile* prof);

#endif
