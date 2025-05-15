/**
 * @file ex5-8.c
 * @author Felix Lempriere
 * @brief Solution to Exercise 5.8 from The C Programming Language, 2nd Edition.
 *
 * There is no error checking in day_of_year or month_day. Remedy this defect.
 * @version 0.1
 * @date 2025-05-10
 *
 * @copyright Copyright (c) 2025
 *
 */

#include <stdio.h>
#include <stdlib.h>

/**
 * @brief enum storing false and true values
 *
 * FALSE = 0;
 * TRUE = 1
 */
enum truth {
    FALSE,
    TRUE
};

/**
 * @brief Enumeration for the months.
 *
 */
enum month {
    NONE,
    JAN,
    FEB,
    MAR,
    APR,
    MAY,
    JUN,
    JUL,
    AUG,
    SEP,
    OCT,
    NOV,
    DEC
};

/**
 * @brief Checks if a year corresponds to a leap year.
 *
 * @param x year to check
 *
 * @return TRUE if x is a leap year, else
 * @return FALSE.
 */
#define IS_LEAP(x) (((x) % 4 == 0 && (x) % 100 != 0) || (x) % 400 == 0)

/**
 * @brief Sets the month and day pointers to error values.
 *
 * @param x month parameter.
 * @param y day parameter.
 */
#define SET_MONTH_DAY_ERROR(x, y) \
    do {                          \
        *x = NONE;                \
        *y = 0;                   \
    } while (0)

/**
 * @brief Static containing the number of days in a month, with seperate
 * subarrays for leap and non-leap years.
 *
 */
static char daytab[2][13] = {
    { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 },
    { 0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 }
};

/**
 * @brief Returns the day of the year for a given year, day and month.
 *
 * Given a month and day, determines the day of the year, i.e. 1st of Jan
 * is the 1st day of the year, while 31st December is either the 365 or 366
 * depending on if it is a leap year.
 *
 * @param year
 * @param month
 * @param day
 * @return day of the year corresponding to day, month.
 */
int day_of_year(int year, int month, int day);

/**
 * @brief Sets the month and day corresponding to a given day of the year.
 *
 * Given the yearday day of the year, year, determines the corresponding pmonth
 * and pday and sets the pointers to the correct value.
 * @param year
 * @param yearday
 * @param pmonth
 * @param pday
 */
void month_day(int year, int yearday, int* pmonth, int* pday);

/**
 * @brief Test value for a non-leap year
 *
 */
#define TEST_NOT_LEAP 2001

/**
 * @brief Test value for a leap year
 *
 */
#define TEST_LEAP 2000

/**
 * @brief Tests the implementation of month_day and day_to_year.
 *
 * Given a year, month, and day, runs day_of_year(year, month, day) and checks
 * this matches expected. We then check that the inverse of the result
 * month_day(year, result, x, y) recovers the original month and day. An
 * error diagnostic is printed if the test fails.
 *
 * @param year
 * @param yearday
 * @param month
 * @param expected
 * @return TRUE if test passses, else
 * @return FALSE
 */
enum truth test_calender_functions(int year, int month, int day, int expected);

/**
 * @brief Test driver for day_of_year and month_day
 *
 * @return EXIT_SUCCESS if all tests passed successfully, else
 * @return EXIT_FAILURE.
 */
int main(void) {
    // test non-leap year
    if (!test_calender_functions(TEST_NOT_LEAP, JAN, 1, 1)) {
        return EXIT_FAILURE;
    }
    if (!test_calender_functions(TEST_NOT_LEAP, MAR, 1, 60)) {
        return EXIT_FAILURE;
    }
    if (!test_calender_functions(TEST_NOT_LEAP, FEB, 29, 0)) {
        return EXIT_FAILURE;
    }
    if (!test_calender_functions(TEST_NOT_LEAP, DEC, 31, 365)) {
        return EXIT_FAILURE;
    }
    if (!test_calender_functions(TEST_NOT_LEAP, 0, 1, 0)) {
        return EXIT_FAILURE;
    }
    if (!test_calender_functions(TEST_NOT_LEAP, 1, 0, 0)) {
        return EXIT_FAILURE;
    }
    if (!test_calender_functions(TEST_NOT_LEAP, DEC + 1, 1, 0)) {
        return EXIT_FAILURE;
    }
    if (!test_calender_functions(TEST_NOT_LEAP, DEC, 32, 0)) {
        return EXIT_FAILURE;
    }
    // test leap year
    if (!test_calender_functions(TEST_LEAP, JAN, 1, 1)) { return EXIT_FAILURE; }

    if (!test_calender_functions(TEST_LEAP, MAR, 1, 61)) {
        return EXIT_FAILURE;
    }
    if (!test_calender_functions(TEST_LEAP, FEB, 29, 60)) {
        return EXIT_FAILURE;
    }
    if (!test_calender_functions(TEST_LEAP, DEC, 31, 366)) {
        return EXIT_FAILURE;
    }
    if (!test_calender_functions(TEST_LEAP, 0, 1, 0)) { return EXIT_FAILURE; }
    if (!test_calender_functions(TEST_LEAP, 1, 0, 0)) { return EXIT_FAILURE; }
    if (!test_calender_functions(TEST_LEAP, DEC + 1, 1, 0)) {
        return EXIT_FAILURE;
    }
    if (!test_calender_functions(TEST_LEAP, DEC, 32, 0)) {
        return EXIT_FAILURE;
    }
    if (!test_calender_functions(-1, JAN, 1, 0)) { return EXIT_FAILURE; }
    printf("All tests passed successfully\n");
    return EXIT_SUCCESS;
}

int day_of_year(int year, int month, int day) {
    if (year < 0 || month < JAN || month > DEC) { return 0; }
    enum truth leap = IS_LEAP(year);
    if (day > daytab[leap][month] || day < 1) { return 0; }

    for (int i = 1; i < month; day += daytab[leap][i], i++);
    return day;
}

void month_day(int year, int yearday, int* pmonth, int* pday) {
    if (yearday < 1 || year < 0) {
        SET_MONTH_DAY_ERROR(pmonth, pday);
        return;
    }
    enum truth leap = IS_LEAP(year);
    if (yearday > 365 + (int) leap) {
        SET_MONTH_DAY_ERROR(pmonth, pday);
        return;
    }
    int i = 1;
    for (; yearday > daytab[leap][i]; yearday -= daytab[leap][i], i++);
    *pmonth = i;
    *pday = yearday;
}

enum truth test_calender_functions(int year, int month, int day, int expected) {
    int res = day_of_year(year, month, day);
    if (res != expected) {
        printf("Test failed while converted Y-M-D %d-%d-%d to day of year\n",
               year, month, day);
        printf("Error: Expected: %d, Result: %d\n", expected, res);
        return FALSE;
    }
    int m;
    int d;
    month_day(year, res, &m, &d);
    if (year < 0 || month < JAN || month > DEC) { month = NONE; }
    if (year < 0 || day < 1 || day > daytab[IS_LEAP(year)][month]) { day = 0; }
    if (m != month && d != day) {
        printf("Test failed while converting day: %d of year %d to Y-M-D\n",
               res, year);
        printf("Error: Expected (%d, %d), Result (%d, %d)\n", month, day, m, d);
        return FALSE;
    }
    return TRUE;
}