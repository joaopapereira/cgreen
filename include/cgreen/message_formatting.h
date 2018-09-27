#ifndef CGREEN_MESSAGE_FORMATTING_H
#define CGREEN_MESSAGE_FORMATTING_H

#include "internal/constraints.h"
#include <stdint.h>

#ifdef __cplusplus
namespace cgreen {
extern "C" {
#endif

char *failure_message_for(CGreenConstraint *constraint, const char *actual_string, intptr_t actual);
char *validation_failure_message_for(CGreenConstraint *constraint, intptr_t actual);
bool parameters_are_not_valid_for(CGreenConstraint *constraint, intptr_t actual);

#ifdef __cplusplus
}
}
#endif

#endif
