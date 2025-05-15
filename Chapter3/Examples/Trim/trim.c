/**
 * @file trim.c
 * @author Felix Lempriere
 * @brief trim function, removes all trailing blanks, tabs, newlines.
 *
 * Demonstrates early exit from a loop through the use of a break
 * statement.
 * @version 0.1
 * @date 2025-04-30
 *
 * @copyright Copyright (c) 2025
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @brief maximum line buffer size
 *
 */
#define MAX_SIZE 100

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
 * @brief Trims trailing blanks, tabs and newlines
 *
 * @param s string to trim
 * @return index in s where trim finished. If the entire string is consumed then
 * @return -1.
 */
int trim(char s[]);

/**
 * @brief Tests the function trim.
 *
 * Given an input string s, compares the result of trim(s) to the expected
 * output. Prints an error diagnostic if they disagree.
 *
 * @param in test string
 * @param expected expected result of trim(s).
 * @return TRUE if the results agree, else
 * @return FALSE
 *
 */
enum truth test_trim(char in[], char expected[]);

/**
 * @brief Test driver for trim
 *
 * @return EXIT_SUCCESS if all tests pass, else
 * @return EXIT_FAILURE.
 */
int main(void) {
    if (!test_trim("", "")) { return EXIT_FAILURE; }
    if (!test_trim("\n", "")) { return EXIT_FAILURE; }
    if (!test_trim("\t", "")) { return EXIT_FAILURE; }
    if (!test_trim(" ", "")) { return EXIT_FAILURE; }
    if (!test_trim(" a", " a")) { return EXIT_FAILURE; }
    if (!test_trim("\ta", "\ta")) { return EXIT_FAILURE; }
    if (!test_trim("\na", "\na")) { return EXIT_FAILURE; }
    if (!test_trim("a ", "a")) { return EXIT_FAILURE; }
    if (!test_trim("a\t", "a")) { return EXIT_FAILURE; }
    if (!test_trim("a\n", "a")) { return EXIT_FAILURE; }
    if (!test_trim("a  ", "a")) { return EXIT_FAILURE; }
    if (!test_trim("a\t\t", "a")) { return EXIT_FAILURE; }
    if (!test_trim("a\n\n", "a")) { return EXIT_FAILURE; }
    if (!test_trim("a \t\n", "a")) { return EXIT_FAILURE; }
    printf("All tests passed successfully\n");
    return EXIT_SUCCESS;
}

int trim(char s[]) {
    int n;
    for (n = strlen(s) - 1; n >= 0; n--) {
        if (s[n] != ' ' && s[n] != '\t' && s[n] != '\n') { break; }
    }
    s[n + 1] = '\0';
    return n;
}

enum truth test_trim(char in[], char expected[]) {
    char intermediate[MAX_SIZE];
    int i;
    for (i = 0; i < MAX_SIZE && in[i] != '\0'; i++) { intermediate[i] = in[i]; }
    intermediate[i] = '\0';
    trim(intermediate);
    if (strcmp(intermediate, expected)) {
        printf("Error converting %s, produced %s,\n", in, intermediate);
        printf("Expected: %s.\n", expected);
        return FALSE;
    }
    return TRUE;
}