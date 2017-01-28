#ifndef FPTRS_102_H
#define FPTRS_102_H

#define VOID_PTR(x) ((void*) (x))

/************************** random.h **************************/

/** function that changes the value in RAND_ADDRESS */
#define RANDU_FPTR      VOID_PTR(0x80380580e) 

/************************** system.h **************************/

/** void* malloc(size_t size); */
#define MALLOC_FPTR     VOID_PTR(0x8037f1e4)

/** void* memcpy(void* destination, const void* source, size_t num) */
#define MEM_CPY_FPTR    VOID_PTR(0x80003220) //80003244 80329194 800031f4

/** void* memset(void* ptr, int value, size_t num) */
#define MEM_SET_FPTR    VOID_PTR(0x80003130)

/** void* memchr(const void* ptr, int value, size_t num) */
#define MEM_CHR_FPTR    VOID_PTR(0x8032390c)

/** int memcmp(const void* ptr1, const void* ptr2, size_t num) */
#define MEM_CMP_FPTR    VOID_PTR(0x803238c8)

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
