/**
 * @file error.h
 * @brief print error message
 *
 */

#ifndef MML_ERROR_H
#define MML_ERROR_H

#include "print.h"

/** @cond */
#define STRINGIFY(x) #x
#define TOSTRING(x) STRINGIFY(x)
/** @endcond */

/** send error state and display error message */
#define THROW_ERROR(code, msg) \
do { \
    _errorState = _errorState | code; \
    error(__FILE__ ":" TOSTRING(__LINE__) ": " msg); \
} while (0)

/** true as soon as one error throw */
#define ERROR_STATE _errorState;

/** check if error code has been thrown */
#define ERROR_THROWN(code) (_errorState & (code))

/** error in print stream */
#define PRINT_ERR       (1 << 0)

/** error in AI */
#define AI_ERR          (1 << 1)

/** Only @c true if @c error has never been called **/
extern u32 _errorState;

#endif
