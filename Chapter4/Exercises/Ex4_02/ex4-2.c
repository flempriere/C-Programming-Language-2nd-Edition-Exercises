/**
 * @file ex4-2.c
 * @author Felix Lempriere
 * @brief Solution to Exercise 4.2 from The C Programming Language, 2nd Edition.
 *
 * Extend `atof` to handle scientific notation of the form
 *      123.45e-6
 * where a floating-point number may be followed by `e` or `E` and an optionally
 * signed exponent.
 * @version 0.1
 * @date 2025-04-30
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
 * @brief Converts a string s to a double
 *
 * @param s string to convert
 * @return double result of conversion
 */
double my_atof(char s[]);

/**
 * @brief Tests atof on the input string in, and compares the output
 * against the expected result expected.
 *
 *
 * @param in input string to test the match
 * @param expected expected output
 * @return TRUE if atof(in, pattern) == expected, else
 * @return FALSE
 *
 * @remark The equality in the return is just to prove a point, we use an
 * approach based on relative magnitude.
 */
enum truth test_my_atof(char in[], double expected);

/**
 * @brief Test driver for atof
 *
 * @return EXIT_SUCCESS if all tests pass, else
 * @return EXIT_FAILURE
 */
int main(void) {
    if (!test_my_atof("0", 0.0)) { return EXIT_FAILURE; }
    if (!test_my_atof("0.", 0.0)) { return EXIT_FAILURE; }
    if (!test_my_atof("0.0", 0.0)) { return EXIT_FAILURE; }
    if (!test_my_atof("5", 5.0)) { return EXIT_FAILURE; }
    if (!test_my_atof("+5", 5.0)) { return EXIT_FAILURE; }
    if (!test_my_atof("-5", -5.0)) { return EXIT_FAILURE; }
    if (!test_my_atof("5.4", 5.4)) { return EXIT_FAILURE; }
    if (!test_my_atof("-5.4", -5.4)) { return EXIT_FAILURE; }
    if (!test_my_atof("+.007", 0.007)) { return EXIT_FAILURE; }
    if (!test_my_atof(".007", 0.007)) { return EXIT_FAILURE; }
    if (!test_my_atof("-.008", -0.008)) { return EXIT_FAILURE; }
    if (!test_my_atof("0e-3", 0)) { return EXIT_FAILURE; }
    if (!test_my_atof("1e+3", 1000)) { return EXIT_FAILURE; }
    if (!test_my_atof("1e-3", 0.001)) { return EXIT_FAILURE; }
    if (!test_my_atof("1e3", 1000)) { return EXIT_FAILURE; }
    if (!test_my_atof("+1e-3", 0.001)) { return EXIT_FAILURE; }
    printf("All tests performed successfully\n");
    return EXIT_SUCCESS;
}

double my_atof(char s[]) {
    int i = 0;
    for (i = 0; isspace(s[i]); i++);
    int sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-') { i++; }
    double val;
    for (val = 0.0; isdigit(s[i]); i++) { val = 10.0 * val + (s[i] - '0'); }
    if (s[i] == '.') { i++; }
    double power;
    for (power = 1.0; isdigit(s[i]); i++) {
        val = 10.0 * val + (s[i] - '0');
        power *= 10.0;
    }
    val = sign * val / power;

    if (s[i] == 'e' || s[i] == 'E') {
        sign = (s[++i] == '-') ? 0 : 1;
        if (s[i] == '+' || s[i] == '-') { i++; }
        int exp = 0;
        for (exp = 0; isdigit(s[i]); i++) { exp = 10 * exp + (s[i] - '0'); }
        if (sign) {
            for (; exp > 0; exp--) { val *= 10; }
        } else {
            for (; exp > 0; exp--) { val /= 10; }
        }
    }
    return val;
}

enum truth test_my_atof(char s[], double expected) {
    double res = atof(s);
    double abs_res = (res < 0) ? -res : res;
    double abs_exp = (res < 0) ? -expected : expected;

    if (abs_res < 1e-6 && abs_exp > 1e-6) {
        printf("Error: atof(s) conversion issue\n");
        printf("Input: %s, result: %e, expected: %e\n", s, res, expected);
        return FALSE;
    }
    double denom = ((res - expected) < 0) ? (expected - res) : res - expected;
    double numer = (abs_res > abs_exp) ? abs_res : abs_exp;

    if (denom / numer > 1e-6) {
        printf("Error: atof(s) conversion issue\n");
        printf("Input: %s, result: %e, expected: %e\n", s, res, expected);
        return FALSE;
    }
    return TRUE;
}