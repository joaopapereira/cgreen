#include <cgreen/internal/constraints.h>
#include <string>

namespace cgreen {

CGreenConstraint *create_equal_to_string_constraint(const std::string& expected_value, const char *expected_value_name)
{
    return create_equal_to_string_constraint(expected_value.c_str(), expected_value_name);
}

CGreenConstraint *create_equal_to_string_constraint(const std::string* expected_value, const char *expected_value_name)
{
    return create_equal_to_string_constraint(expected_value->c_str(), expected_value_name);
}

CGreenConstraint *create_not_equal_to_string_constraint(const std::string& expected_value, const char *expected_value_name)
{
    return create_not_equal_to_string_constraint(expected_value.c_str(), expected_value_name);
}

CGreenConstraint *create_not_equal_to_string_constraint(const std::string* expected_value, const char *expected_value_name)
{
    return create_not_equal_to_string_constraint(expected_value->c_str(), expected_value_name);
}

CGreenConstraint *create_contains_string_constraint(const std::string& expected_value, const char *expected_value_name)
{
    return create_contains_string_constraint(expected_value.c_str(), expected_value_name);
}

CGreenConstraint *create_contains_string_constraint(const std::string* expected_value, const char *expected_value_name)
{
    return create_contains_string_constraint(expected_value->c_str(), expected_value_name);
}

CGreenConstraint *create_does_not_contain_string_constraint(const std::string& expected_value, const char *expected_value_name)
{
    return create_does_not_contain_string_constraint(expected_value.c_str(), expected_value_name);
}

CGreenConstraint *create_does_not_contain_string_constraint(const std::string* expected_value, const char *expected_value_name)
{
    return create_does_not_contain_string_constraint(expected_value->c_str(), expected_value_name);
}

CGreenConstraint *create_begins_with_string_constraint(const std::string& expected_value, const char *expected_value_name)
{
    return create_begins_with_string_constraint(expected_value.c_str(), expected_value_name);
}

CGreenConstraint *create_begins_with_string_constraint(const std::string* expected_value, const char *expected_value_name)
{
    return create_begins_with_string_constraint(expected_value->c_str(), expected_value_name);
}

}
