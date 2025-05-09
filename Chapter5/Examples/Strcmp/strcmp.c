/**
 * @file strcmp.c
 * @author Felix Lempriere
 * @brief  Two versions of string comparison demonstrating the use of pointer vs
 * array syntax.
 * @version 0.1
 * @date 2025-05-09
 *
 * @copyright Copyright (c) 2025
 *
 */

#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Maximum size for the string
 *
 */
#define STRSIZE 100

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
 * @brief Lexigraphically compare strings, using an array syntax.
 *
 * @param s
 * @param t
 *
 * @return positive number if s is lexigraphically greater than t, else
 * @return 0 if s and t are lexigraphically equal, else
 * @return negative number if s is lexigraphically less than t.
 */
int strcmp_a(char* s, char* t);

/**
 * @brief Lexigraphically compare strings, using a pointer syntax.
 *
 * @param s
 * @param t
 *
 * @return positive number if s is lexigraphically greater than t, else
 * @return 0 if s and t are lexigraphically equal, else
 * @return negative number if s is lexigraphically less than t.
 */
int strcmp_p(char* s, char* t);

/**
 * @brief Test driver for strcmp implementations.
 *
 * @return EXIT_SUCCESS if all tests pass successfully, else
 * @return EXIT_FAILURE.
 */
int main(void) {
    int res;

    printf("Testing array syntax implementation\n");

    if ((res = strcmp_a("", "")) != 0) {
        printf("Error: expected: %d, result: %d\n", 0, res);
        return EXIT_FAILURE;
    }
    if ((res = strcmp_a("", "a")) >= 0) {
        printf("Error: expected empty string to be less than %s\n", "a");
        printf("Error: result: %d\n", res);
        return EXIT_FAILURE;
    }
    if ((res = strcmp_a("a", "")) <= 0) {
        printf("Error: expected empty string to be greater than %s\n", "a");
        printf("Error: result: %d\n", res);
        return EXIT_FAILURE;
    }
    if ((res = strcmp_a("a", "a")) != 0) {
        printf("Error: expected: %d, result: %d\n", 0, res);
        return EXIT_FAILURE;
    }
    if ((res = strcmp_a("a", "b")) >= 0) {
        printf("Error: expected %s to be less than %s\n", "a", "b");
        printf("Error: result: %d\n", res);
        return EXIT_FAILURE;
    }
    if ((res = strcmp_a("b", "a")) <= 0) {
        printf("Error: expected %s to be greater than %s\n", "b", "a");
        printf("Error: result: %d\n", res);
        return EXIT_FAILURE;
    }
    if ((res = strcmp_a("abc", "abc")) != 0) {
        printf("Error: expected: %d, result: %d\n", 0, res);
        return EXIT_FAILURE;
    }
    if ((res = strcmp_a("abc", "cba")) >= 0) {
        printf("Error: expected %s to be less than %s\n", "abc", "cba");
        printf("Error: result: %d\n", res);
        return EXIT_FAILURE;
    }
    if ((res = strcmp_a("cba", "abc")) <= 0) {
        printf("Error: expected %s to be greater than %s\n", "cba", "abc");
        printf("Error: result: %d\n", res);
        return EXIT_FAILURE;
    }
    if ((res = strcmp_a("ab", "aba")) >= 0) {
        printf("Error: expected %s to be less than %s\n", "ab", "aba");
        printf("Error: result: %d\n", res);
        return EXIT_FAILURE;
    }
    if ((res = strcmp_a("aba", "ab")) <= 0) {
        printf("Error: expected %s to be greater than %s\n", "aba", "ab");
        printf("Error: result: %d\n", res);
        return EXIT_FAILURE;
    }

    printf("Testing pointer implementation\n");

    if ((res = strcmp_p("", "")) != 0) {
        printf("Error: expected: %d, result: %d\n", 0, res);
        return EXIT_FAILURE;
    }
    if ((res = strcmp_p("", "a")) >= 0) {
        printf("Error: expected empty string to be less than %s\n", "a");
        printf("Error: result: %d\n", res);
        return EXIT_FAILURE;
    }
    if ((res = strcmp_p("a", "")) <= 0) {
        printf("Error: expected empty string to be greater than %s\n", "a");
        printf("Error: result: %d\n", res);
        return EXIT_FAILURE;
    }
    if ((res = strcmp_p("a", "a")) != 0) {
        printf("Error: expected: %d, result: %d\n", 0, res);
        return EXIT_FAILURE;
    }
    if ((res = strcmp_p("a", "b")) >= 0) {
        printf("Error: expected %s to be less than %s\n", "a", "b");
        printf("Error: result: %d\n", res);
        return EXIT_FAILURE;
    }
    if ((res = strcmp_p("b", "a")) <= 0) {
        printf("Error: expected %s to be greater than %s\n", "b", "a");
        printf("Error: result: %d\n", res);
        return EXIT_FAILURE;
    }
    if ((res = strcmp_p("abc", "abc")) != 0) {
        printf("Error: expected: %d, result: %d\n", 0, res);
        return EXIT_FAILURE;
    }
    if ((res = strcmp_p("abc", "cba")) >= 0) {
        printf("Error: expected %s to be less than %s\n", "abc", "cba");
        printf("Error: result: %d\n", res);
        return EXIT_FAILURE;
    }
    if ((res = strcmp_p("cba", "abc")) <= 0) {
        printf("Error: expected %s to be greater than %s\n", "cba", "abc");
        printf("Error: result: %d\n", res);
        return EXIT_FAILURE;
    }
    if ((res = strcmp_p("ab", "aba")) >= 0) {
        printf("Error: expected %s to be less than %s\n", "ab", "aba");
        printf("Error: result: %d\n", res);
        return EXIT_FAILURE;
    }
    if ((res = strcmp_p("aba", "ab")) <= 0) {
        printf("Error: expected %s to be greater than %s\n", "aba", "ab");
        printf("Error: result: %d\n", res);
        return EXIT_FAILURE;
    }
    printf("All tests passed successfully\n");
    return EXIT_SUCCESS;
}

int strcmp_a(char* s, char* t) {
    int i;
    for (i = 0; s[i] == t[i]; i++) {
        if (s[i] == '\0') { return 0; }
    }
    return s[i] - t[i];
}

int strcmp_p(char* s, char* t) {
    for (; *s == *t; s++, t++) {
        if (*s == '\0') { return 0; }
    }
    return *s - *t;
}