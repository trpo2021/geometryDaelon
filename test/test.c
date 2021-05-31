#include "ctest.h"
#include "geometry/geometry.h"

CTEST(suite, system_testing)
{
    ASSERT_EQUAL(1 + 2, 3);
}

CTEST(suite, test_lack_of_data)
{
    struct TCircle c;
    char result[1000];

    Correct_Writing("", &c, result);

    ASSERT_NOT_EQUAL(result[0], 0);
}

CTEST(suite, test_invalid_shape_name)
{
    struct TCircle c;
    char result[1000];

    Correct_Writing("oval(10 10, 5)", &c, result);

    ASSERT_NOT_EQUAL(result[0], 0);
}

CTEST(suite, test_incomplete_data)
{
    struct TCircle c;
    char result[1000];

    Correct_Writing("circle( 10 )", &c, result);

    ASSERT_NOT_EQUAL(result[0], 0);
}

CTEST(suite, test_incorrect_input_of_coordinates)
{
    struct TCircle c;
    char result[1000];

    Correct_Writing("circle( 10,10,10 )", &c, result);

    ASSERT_NOT_EQUAL(result[0], 0);
}

CTEST(suite, test_invalid_character_after_the_shape_name)
{
    struct TCircle c;
    char result[1000];

    Correct_Writing("circle)", &c, result);

    ASSERT_NOT_EQUAL(result[0], 0);
}

CTEST(suite, test_happy_case)
{
    struct TCircle c;
    char result[1000];

    Correct_Writing("circle(10 10,10)", &c, result);

    ASSERT_EQUAL(result[0], 0);
}