/**
 * @file ex5-4.c
 * @author Felix Lempriere
 * @brief Solution to Exercise 5.4 from The C Programming Language, 2nd Edition.
 *
 * Write the function `strend(s, t)`, which returns 1 if the string `t` occurs
 * at the end of the string `s` and zero otherwise.
 * @version 0.1
 * @date 2025-05-09
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
 * @brief size to allocate the string buffers
 *
 */
#define STR_BUF 100

/**
 * @brief Indicates if the string s is ended by the substring t.
 *
 * @param s
 * @param t
 * @return 1 if the string t occurs at the end of s, else
 * @return 0.
 */
int strend(char* s, char* t);

/**
 * @brief tests strend(s, t), by calling the function and comparing it to
 * the expected result. An error diagnostic is printed if the tests fail.
 *
 * @param s
 * @param t
 * @param expected
 * @return TRUE if test passed, else
 * @return FALSE.
 */
enum truth test_strend(char* s, char* t, int expected);

/**
 * @brief Test driver for my strcat.
 *
 * @return EXIT_SUCCESS if all tests passed successfully, else
 * @return EXIT_FAILURE
 */
int main(void) {
    if (!test_strend("", "", 1)) { return EXIT_FAILURE; }
    if (!test_strend("a", "", 1)) { return EXIT_FAILURE; }
    if (!test_strend("ab", "b", 1)) { return EXIT_FAILURE; }
    if (!test_strend("aba", "ba", 1)) { return EXIT_FAILURE; }
    if (!test_strend("ab", "a", 0)) { return EXIT_FAILURE; }
    if (!test_strend("ab", "aba", 0)) { return EXIT_FAILURE; }
    printf("All tests passed successfully\n");
    return EXIT_SUCCESS;
}

int strend(char* s, char* t) {
    char* st_s = s;
    char* st_t = t;

    while (*s) { s++; }
    while (*t) { t++; }

    for (; *s == *t; s--, t--) {
        if (t == st_t || s == st_s) { break; }
    }
    if (*s == *t && t == st_t) {
        return 1;
    } else {
        return 0;
    }
}

enum truth test_strend(char* s, char* t, int expected) {
    int res = strend(s, t);
    if (res != expected) {
        printf("Error: Compared %s and %s\n", s, t);
        printf("Error: result: %d, expected: %d\n", res, expected);
        return FALSE;
    }
    return TRUE;
}