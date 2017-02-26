/**
 * @file error.h
 * @brief print error message
 *
 */

#ifndef MML_ERROR_H
#define MML_ERROR_H

#include "print.h"

#define STRINGIFY(x) #x
#define TOSTRING(x) STRINGIFY(x)
#define ASSERT_MSG "assert failed: " __FILE__ ":" TOSTRING(__LINE__)

#define ERROR(x) error(__FILE__ ":" TOSTRING(__LINE__) ": " x);

#endif
