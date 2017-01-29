#ifndef FPTRS_102_H
#define FPTRS_102_H

#define VOID_PTR(x) ((void*) (x))

/************************** random.h **************************/

/** function that changes the value in RAND_ADDRESS */
#define RANDU_FPTR      VOID_PTR(0x80380580e) 

/************************** system.h **************************/

/** void* malloc(size_t size); */
#define MALLOC_FPTR     VOID_PTR(0x8037f1e4)

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

/** pointer to sin() function in Melee v102 */
#define SINE_FPTR       VOID_PTR(0x80326220)

/** pointer to cos() function in Melee v102 */
#define COSINE_FPTR     VOID_PTR(0x80326200)

/** pointer to tan() function in Melee v102 */
#define TANGENT_FPTR    VOID_PTR(0x803261bc)

/** pointer to fabs() function in Melee v102 */
#define ABS_VAL_FPTR    VOID_PTR(0x803261b4)

/** pointer to 1/sqrt() function in Melee v102 */
#define RECIP_SQRT_FPTR VOID_PTR(0x80022df8);

#endif
