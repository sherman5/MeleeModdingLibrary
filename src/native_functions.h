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

#define PLAYER_ENTITY_FPTR          VOID_PTR(0x80034110)

/************************** random.h **************************/

#define RAND_INT_FPTR                  VOID_PTR(0x80380580) 

/************************** system.h **************************/

//#define MALLOC_FPTR     VOID_PTR(0x8037f1e4)

#define OS_CREATE_HEAP_FPTR         VOID_PTR(0x803440e8)

#define OS_ALLOC_FROM_HEAP_FPTR     VOID_PTR(0x80343ef0)

#define OS_FREE_TO_HEAP_FPTR        VOID_PTR(0x80343fec)

#define OS_GET_ARENA_HI_FPTR        VOID_PTR(0x803444c8)

#define OS_GET_ARENA_LO_FPTR        VOID_PTR(0x803444d0)

#define OS_INIT_ALLOC_FPTR          VOID_PTR(0x80344078)

#define OS_SET_ARENA_HI_FPTR        VOID_PTR(0x803444d8)

#define OS_SET_ARENA_LO_FPTR        VOID_PTR(0x803444e0)

//#define OS_SET_CURRENT_HEAP_FPTR    VOID_PTR(0x8034508c) // ?
    
//#define OS_ADD_TO_HEAP_FPTR         VOID_PTR()

//#define OS_DUMP_HEAP_FPTR           VOID_PTR(0x80345334) // ?

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

/** char* itoa(int32_t value, char* str, int base) */
#define ITOA_FPTR       VOID_PTR(0x803250c0)

/************************** math.h ****************************/

/** float sin(float x) */
#define SINE_FPTR       VOID_PTR(0x80326220)

/** float cosine(float x) */
#define COSINE_FPTR     VOID_PTR(0x80326200)

/** float tan(float x) */
#define TANGENT_FPTR    VOID_PTR(0x803261bc)

/** float fabs(float x) */
#define ABS_VAL_FPTR    VOID_PTR(0x803261b4)

/** float recipSqrt(float x) */
#define RECIP_SQRT_FPTR VOID_PTR(0x80022df8);

#endif // #ifdef PAL
#endif // #ifndef MML_NATIVE_FUNCTIONS_H
