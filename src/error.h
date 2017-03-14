/**
 * @file error.h
 * @brief handle run-time errors
 */

#ifndef MML_ERROR_H
#define MML_ERROR_H

#include "print.h"

/** @cond */
#define STRINGIFY(x) #x
#define TOSTRING(x) STRINGIFY(x)
/** @endcond */

/** send error state and display error message @ingroup CallsMalloc */
#define THROW_ERROR(code, msg) \
do { \
    _errorState = _errorState | code; \
    error(__FILE__ ":" TOSTRING(__LINE__) ": " msg); \
} while (0)

/** display error message @ingroup CallsMalloc */
#define ERROR_MSG(msg) error(__FILE__ ":" TOSTRING(__LINE__) \
    ": " msg)

/** true as soon as one error throw */
#define ERROR_STATE _errorState;

/** check if error code has been thrown */
#define ERROR_THROWN(code) (_errorState & (code))

//@{
/** Error Code */
#define ERR_1       (1 << 0)
#define ERR_2       (1 << 1)
#define ERR_3       (1 << 2)
#define ERR_4       (1 << 3)
#define ERR_5       (1 << 4)
#define ERR_6       (1 << 5)
#define ERR_7       (1 << 6)
#define ERR_8       (1 << 7)
#define ERR_9       (1 << 8)
#define ERR_10      (1 << 9)
#define ERR_11      (1 << 10)
#define ERR_12      (1 << 11)
#define ERR_13      (1 << 12)
#define ERR_14      (1 << 13)
#define ERR_15      (1 << 14)
#define ERR_16      (1 << 15)
#define ERR_17      (1 << 16)
#define ERR_18      (1 << 17)
#define ERR_19      (1 << 18)
#define ERR_20      (1 << 19)
#define ERR_21      (1 << 20)
#define ERR_22      (1 << 21)
#define ERR_23      (1 << 22)
#define ERR_24      (1 << 23)
#define ERR_25      (1 << 24)
#define ERR_26      (1 << 25)
#define ERR_27      (1 << 26)
#define ERR_28      (1 << 27)
#define ERR_29      (1 << 28)
#define ERR_30      (1 << 29)
#define ERR_31      (1 << 30)
#define ERR_32      (1 << 31)
//@}

/** Only @c true if @c error has never been called **/
extern u32 _errorState;

#endif
