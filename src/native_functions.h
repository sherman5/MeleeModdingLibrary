/**
 * @file native_functions.h
 * @brief Pointers to in game functions
 *
 */

#ifndef MML_NATIVE_FUNCTIONS_H
#define MML_NATIVE_FUNCTIONS_H

/** Cast address to @c void* - make it a function pointer **/
#define VOID_PTR(x) ((void*) (x))

#ifdef PAL

#error native_functions.h not compatible with PAL

#else

/************************* gamestate.h ************************/

/** u32 playerEntity(u32) */
#define PLAYER_ENTITY_FPTR          VOID_PTR(0x80034110)

/************************** random.h **************************/

/** u32 randInt(u32) */
#define RAND_INT_FPTR                  VOID_PTR(0x80380580) 

/************************** system.h **************************/

/** handle_t OSCreateHeap(void*, void*) */
#define OS_CREATE_HEAP_FPTR         VOID_PTR(0x803440e8)

/** void* OSAllocFromHeap(handle_t, size_t) */
#define OS_ALLOC_FROM_HEAP_FPTR     VOID_PTR(0x80343ef0)

/** void OSFreeToHeap(handle_t, void*) */
#define OS_FREE_TO_HEAP_FPTR        VOID_PTR(0x80343fec)

/************************** string.h **************************/

/** void* memchr(const void* ptr, int value, size_t num) */
#define MEM_CHR_FPTR    VOID_PTR(0x8032390c)

/** int memcmp(const void* ptr1, const void* ptr2, size_t num) */
#define MEM_CMP_FPTR    VOID_PTR(0x803238c8)

/** void* memcpy(void* destination, const void* source, size_t num) */
#define MEM_CPY_FPTR    VOID_PTR(0x800031f4) 

/** void* memset(void* ptr, int value, size_t num) */
#define MEM_SET_FPTR    VOID_PTR(0x80003130)

/** char* strchr(const char* str, int character) */
#define STR_CHR_FPTR    VOID_PTR(0x8032578)

/** int strcmp(const char* str1, const char* str2) */
#define STR_CMP_FPTR    VOID_PTR(0x803258e8)

/** int strncmp(const char* str1, const char* str2, size_t num) */
#define STRN_CMP_FPTR   VOID_PTR(0x803258a8)

/** char* strcpy(char* destination, const char* source) */
#define STR_CPY_FPTR    VOID_PTR(0x80325a50)

/** char* strncpy(char* destination, const char* source, size_t num) */
#define STRN_CPY_FPTR   VOID_PTR(0x80325a0c)

/** size_t strlen(const char* str) */
#define STR_LEN_FPTR    VOID_PTR(0x80325b04)

/** uint32_t strtoul(const char* str, char** endptr, int base) */
#define STR_TO_UL_FPTR  VOID_PTR(0x80325b24)

/************************** print.h ***************************/

/** int sprintf(char* str, const char* format, ...) */
#define SPRINTF_FPTR    VOID_PTR(0x80323cf4)

/************************** math.h ****************************/

/** float sin(float x) */
#define SIN_FPTR        VOID_PTR(0x80326220)

/** float cos(float x) */
#define COS_FPTR        VOID_PTR(0x80326200)

/** float tan(float x) */
#define TAN_FPTR        VOID_PTR(0x803261bc)

/** float acos(float x) */
#define ACOS_FPTR       VOID_PTR(0x80022d1c)

/** float asin(float x) */
#define ASIN_FPTR       VOID_PTR(0x80022dbc)

/** float atan(float x) */
#define ATAN_FPTR       VOID_PTR(0x80022e68)

/** float atan2(float y, float x) */
#define ATAN2_FPTR      VOID_PTR(0x80022c30)

/** float exp(float x) */
#define EXP_FPTR        VOID_PTR(0x8000ce50)

/** float log(float x) */
#define LOG_FPTR        VOID_PTR(0x803265a8)

/** float fabs(float x) */
#define FABS_FPTR       VOID_PTR(0x803261b4)

/** float recipSqrt(float x) */
#define RECIP_SQRT_FPTR VOID_PTR(0x80022df8);

/************************** profile.h *************************/

/** u32 OSGetTime() */
#define OS_GET_TIME_FPTR            VOID_PTR(0x8034c3f0)

/** u32 OSGetTick() */
#define OS_GET_TICK_FPTR            VOID_PTR(0x8034c408)

/** u32 OSGetSystemTime() */
#define OS_GET_SYSTEM_TIME_FPTR     VOID_PTR(0x8034c410)

/** u32 OSGetTick() */
#define OS_TIME_TO_SYSTEM_TIME_FPTR VOID_PTR(0x8034c474)

#endif // #ifdef PAL
#endif // #ifndef MML_NATIVE_FUNCTIONS_H
