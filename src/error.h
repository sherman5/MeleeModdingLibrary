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
#define THROW_ERROR(x) error(__FILE__ ":" TOSTRING(__LINE__) ": " x);

#endif
