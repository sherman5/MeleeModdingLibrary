/**
 * @file melee_info.h
 * @brief Game Information
 *
 */

#ifndef MML_MELEE_INFO_H
#define MML_MELEE_INFO_H

#include "gctypes.h"

//@{
/** Character Code */
#define DR_MARIO_ID        0    
#define MARIO_ID           1
#define LUIGI_ID           2
#define BOWSER_ID          3
#define PEACH_ID           4
#define YOSHI_ID           5
#define DK_ID              6
#define FALCON_ID          7
#define GANON_ID           8
#define FALCO_ID           9
#define FOX_ID             10
#define NESS_ID            11
#define ICE_CLIMBERS_ID    12
#define KIRBY_ID           13
#define SAMUS_ID           14
#define ZELDA_ID           15
#define LINK_ID            16
#define YOUNG_LINK_ID      17
#define PICHU_ID           18
#define PIKACHU_ID         19
#define PUFF_ID            20
#define MEWTWO_ID          21
#define MR_GNW_ID          22
#define MARTH_ID           23
#define ROY_ID             24
//@}

/** list of short hop lengths (i.e. number of frames before landing) **/
extern const u8 _sh_length[25];

extern const u8 _dj_horizontal[25];

extern const u8 _dj_vertical[25];

#endif
