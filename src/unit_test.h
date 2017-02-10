#ifndef UNIT_TESTS_H
#define UNIT_TESTS_H

#include <stdint.h>
#include <stdbool.h>

#include "print.h"

#define MML_ASSERT(message, condition) do { if (!(condition)) \
    print(message); } while (0)

#endif

