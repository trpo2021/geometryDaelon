#include "ctest.h"
#include "libgeometry/checkcoords.h"
#include "libgeometry/checkgeometry.h"
#include "libgeometry/perim.h"
#include <math.h>
#include <stdio.h>

CTEST(check_circle, Error_name)
{
    char str[] = {"ircle  (1 3, 5) "};
    int real = check_circle(str);

    int exp = -1;

    ASSERT_EQUAL(exp, real);
}

CTEST(check_digit, Error_digit)
{
    char mcoord[50] = "";
    char mrad[50] = "";
    double save_arr[3];
    char str[] = {"circle  (1,5) "};
    int real = check_digit(str, mcoord, mrad, save_arr);

    int exp = -5;

    ASSERT_EQUAL(exp, real);
}

CTEST(check_digit, Error_digit2)
{
    char mcoord[50] = "";
    char mrad[50] = "";
    double save_arr[3];
    char str[] = {"circle  (15) "};
    int real = check_digit(str, mcoord, mrad, save_arr);

    int exp = -3;

    ASSERT_EQUAL(exp, real);
}

CTEST(check_digit, Error_digit3)
{
    char mcoord[50] = "";
    char mrad[50] = "";
    double save_arr[3];
    char str[] = {"circle  (,15) "};
    int real = check_digit(str, mcoord, mrad, save_arr);

    int exp = -3;

    ASSERT_EQUAL(exp, real);
}

CTEST(check_digit, Error_digit4)
{
    char mcoord[50] = "";
    char mrad[50] = "";
    double save_arr[3];
    char str[] = {"circle  (,15) "};
    int real = check_digit(str, mcoord, mrad, save_arr);

    int exp = -3;

    ASSERT_EQUAL(exp, real);
}

CTEST(coord_and_rad, no_intersec)
{
    int i = 0;
    int count_fig = 3;
    double save_rad[2];
    save_rad[1] = 1;
    save_rad[0] = 1;
    double save_x[2];
    double save_y[2];
    save_x[0] = 0;
    save_y[0] = 0;
    save_x[1] = 2;
    save_y[1] = 0;
    int real = intersec(i, count_fig - 1, save_rad, save_x, save_y);
    int exp = 1;

    ASSERT_EQUAL(exp, real);
}

CTEST(coord_and_rad, area)
{
    char rad[] = "5.0";
    double arr[2];
    double real = coord_and_rad(rad, arr);

    double exp = 25 * M_PI;

    ASSERT_DBL_NEAR(exp, real);
}