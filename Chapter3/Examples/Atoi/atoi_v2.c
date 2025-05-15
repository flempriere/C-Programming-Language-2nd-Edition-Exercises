/**
 * @file atoi_v2.c
 * @author Felix Lempriere
 * @brief atoi example using a more sophisticated parsing logic.
 * @version 0.1
 * @date 2025-04-28
 *
 * @copyright Copyright (c) 2025
 *
 */

#include <ctype.h>
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
 * @brief Converts the string s to an integer. Features improved handling
 * for negative numbers or numbers with a starting + sign.
 *
 * @param s string to convert.
 * @return integer result of converting s
 */
int my_atoi(char s[]);

/**
 * @brief tests my_atoi by converting the string s
 * and comparing it to expected. An error diagnostic
 * is printed if they disagree.
 *
 * @param s input string
 * @param expected expected out.
 * @return TRUE if my_atoi(s) == expected, else
 * @return FALSE
 */
enum truth test_my_atoi(char s[], int expected);

/**
 * @brief Test driver for my_atoi
 *
 * @return EXIT_SUCCESS if all tests pass, else
 * @return EXIT_FAILURE
 */
int main(void) {
    if (!test_my_atoi("0", 0)) { return EXIT_FAILURE; }
    if (!test_my_atoi("5", 5)) { return EXIT_FAILURE; }
    if (!test_my_atoi("9", 9)) { return EXIT_FAILURE; }
    if (!test_my_atoi("12345", 12345)) { return EXIT_FAILURE; }
    if (!test_my_atoi("-0", 0)) { return EXIT_FAILURE; }
    if (!test_my_atoi("+0", 0)) { return EXIT_FAILURE; }
    if (!test_my_atoi("-5", -5)) { return EXIT_FAILURE; }
    if (!test_my_atoi("+5", 5)) { return EXIT_FAILURE; }
    if (!test_my_atoi("-12345", -12345)) { return EXIT_FAILURE; }
    printf("All tests passed successfully\n");
    return EXIT_SUCCESS;
}

int my_atoi(char s[]) {
    int i = 0;
    for (; isspace(s[i]); i++);
    int sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-') { i++; }
    int n = 0;
    for (; isdigit(s[i]); i++) { n = 10 * n + (s[i] - '0'); }
    return sign * n;
}

enum truth test_my_atoi(char s[], int expected) {
    int res = my_atoi(s);
    if (res != expected) {
        printf("Error: failed test on converting %s\n", s);
        printf("Error: result: %d, expected: %d\n", res, expected);
        return FALSE;
    }
    return TRUE;
}