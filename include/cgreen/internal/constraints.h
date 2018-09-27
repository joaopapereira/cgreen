#ifndef CONSTRAINT_HEADER
#define CONSTRAINT_HEADER

#include <cgreen/reporter.h>
#include <cgreen/cgreen_value.h>
#ifndef __cplusplus
#include <stdbool.h>
#endif
#include <stddef.h>
#include <stdint.h>

typedef enum {
    VALUE_COMPARER,
    CONTENT_COMPARER,
    STRING_COMPARER,
    DOUBLE_COMPARER,
    RETURN_VALUE,
    CONTENT_SETTER,
    CALL
} ConstraintType;

typedef struct CGreenConstraint_ CGreenConstraint;
struct CGreenConstraint_ {
    ConstraintType type;
    const char *name;
    void (*destroy)(CGreenConstraint *);
    bool (*compare)(CGreenConstraint *, CgreenValue);
    void(*execute)(CGreenConstraint *, const char *, CgreenValue, const char *, int, TestReporter *);
    char *(*failure_message)(CGreenConstraint *, const char *, intptr_t);
    const char *actual_value_message;
    const char *expected_value_message;
    CgreenValue expected_value;
    const char *expected_value_name;

    /* Side Effect parameters */ 
    void (*sideeffect_callback)(void *);
    void *sideeffect_data;

    /* for PARAMETER constraints */
    const char *parameter_name;
    size_t size_of_expected_value;
};

#ifdef __cplusplus
namespace cgreen {
    extern "C" {
#endif

CGreenConstraint *create_constraint(void);
CGreenConstraint *create_parameter_constraint_for(const char *parameter_name);

bool compare_want_value(CGreenConstraint *constraint, CgreenValue actual);
bool compare_do_not_want_value(CGreenConstraint *constraint, CgreenValue actual);
void test_want(CGreenConstraint *constraint, const char *function, CgreenValue actual, const char *test_file, int test_line, TestReporter *reporter);

void test_constraint(CGreenConstraint *constraint, const char *function, intptr_t actual, const char *test_file, int test_line, TestReporter *reporter);

CGreenConstraint *create_equal_to_value_constraint(intptr_t expected_value, const char *expected_value_name);
CGreenConstraint *create_equal_to_hexvalue_constraint(intptr_t expected_value, const char *expected_value_name);
CGreenConstraint *create_not_equal_to_value_constraint(intptr_t expected_value, const char *expected_value_name);
CGreenConstraint *create_greater_than_value_constraint(intptr_t expected_value, const char *expected_value_name);
CGreenConstraint *create_less_than_value_constraint(intptr_t expected_value, const char *expected_value_name);
CGreenConstraint *create_equal_to_contents_constraint(void *pointer_to_compare, size_t size_to_compare, const char *compared_pointer_name);
CGreenConstraint *create_not_equal_to_contents_constraint(void *pointer_to_compare, size_t size_to_compare, const char *compared_pointer_name);
CGreenConstraint *create_equal_to_string_constraint(const char* expected_value, const char *expected_value_name);
CGreenConstraint *create_not_equal_to_string_constraint(const char* expected_value, const char *expected_value_name);
CGreenConstraint *create_contains_string_constraint(const char* expected_value, const char *expected_value_name);
CGreenConstraint *create_does_not_contain_string_constraint(const char* expected_value, const char *expected_value_name);
CGreenConstraint *create_begins_with_string_constraint(const char* expected_value, const char *expected_value_name);
CGreenConstraint *create_does_not_begin_with_string_constraint(const char* expected_value, const char *expected_value_name);
CGreenConstraint *create_ends_with_string_constraint(const char* expected_value, const char *expected_value_name);
CGreenConstraint *create_does_not_end_with_string_constraint(const char* expected_value, const char *expected_value_name);

CGreenConstraint *create_equal_to_double_constraint(double expected_value, const char *expected_value_name);
CGreenConstraint *create_not_equal_to_double_constraint(double expected_value, const char *expected_value_name);
CGreenConstraint *create_less_than_double_constraint(double expected_value, const char *expected_value_name);
CGreenConstraint *create_greater_than_double_constraint(double expected_value, const char *expected_value_name);
CGreenConstraint *create_return_value_constraint(intptr_t value_to_return);
CGreenConstraint *create_return_double_value_constraint(double value_to_return);
CGreenConstraint *create_set_parameter_value_constraint(const char *parameter_name, intptr_t value_to_set, size_t size_to_set);
CGreenConstraint *create_with_sideeffect_constraint(void (*callback)(void *), void *data);

/* Utility: */
int get_significant_figures(void);
void significant_figures_for_assert_double_are(int figures);

#ifdef __cplusplus
    }
}
#endif

#endif
