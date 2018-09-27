#include <cgreen/constraint_syntax_helpers.h>
#include <cgreen/internal/constraints.h>
#include "constraint_internal.h"
#include <cgreen/message_formatting.h>
#include <stdbool.h>
#include <stddef.h>


CGreenConstraint static_is_non_null_constraint = {
    /* .type */ VALUE_COMPARER,
    /* .name */ "be non null",
    /* .destroy */ destroy_static_constraint,
    /* .compare */ compare_do_not_want_value,
    /* .test */ test_want,
    /* .format_failure_message_for */ failure_message_for,
    /* .actual_value_message */ "",
    /* .expected_value_message */ "",
    /* .expected_value */ {INTEGER, {0}},
    /* .stored_value_name */ "null",
    /* .sideeffect_callback */ NULL,
    /* .sideeffect_data */ NULL,
    /* .parameter_name */ NULL,
    /* .size_of_stored_value */ 0
};

CGreenConstraint static_is_null_constraint = {
    /* .type */ VALUE_COMPARER,
    /* .name */ "be null",
    /* .destroy */ destroy_static_constraint,
    /* .compare */ compare_want_value,
    /* .test */ test_want,
    /* .format_failure_message_for */ failure_message_for,
    /* .actual_value_message */ "",
    /* .expected_value_message */ "",
    /* .expected_value */ {INTEGER, {(intptr_t)NULL}},
    /* .stored_value_name */ "null",
    /* .sideeffect_callback */ NULL,
    /* .sideeffect_data */ NULL,
    /* .parameter_name */ NULL,
    /* .size_of_stored_value */ 0
};

CGreenConstraint static_is_false_constraint = {
    /* .type */ VALUE_COMPARER,
    /* .name */ "be false",
    /* .destroy */ destroy_static_constraint,
    /* .compare */ compare_want_value,
    /* .test */ test_want,
    /* .format_failure_message_for */ failure_message_for,
    /* .actual_value_message */ "",
    /* .expected_value_message */ "",
    /* .expected_value */ {INTEGER, {false}},
    /* .stored_value_name */ "false",
    /* .sideeffect_callback */ NULL,
    /* .sideeffect_data */ NULL,
    /* .parameter_name */ NULL,
    /* .size_of_stored_value */ 0
};

CGreenConstraint static_is_true_constraint = {
    /* .type */ VALUE_COMPARER,
    /* .name */ "be true",
    /* .destroy */ destroy_static_constraint,
    /* .compare */ compare_want_value,
    /* .test */ test_want,
    /* .format_failure_message_for */ failure_message_for,
    /* .actual_value_message */ "",
    /* .expected_message */ "",
    /* .expected_value */ {INTEGER, {true}},
    /* .stored_value_name */ "true",
    /* .sideeffect_callback */ NULL,
    /* .sideeffect_data */ NULL,
    /* .parameter_name */ NULL,
    /* .size_of_stored_value */ 0
};

CGreenConstraint *is_non_null = &static_is_non_null_constraint;
CGreenConstraint *is_null = &static_is_null_constraint;
CGreenConstraint *is_false = &static_is_false_constraint;
CGreenConstraint *is_true = &static_is_true_constraint;

/* vim: set ts=4 sw=4 et cindent: */
