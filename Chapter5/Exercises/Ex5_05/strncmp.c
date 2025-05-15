/**
 * @file strncmp.c
 * @author Felix Lempriere
 * @brief Pointer implementation of strncmp in partial completion of Exercise
 * 5.5 from The C Programming Language, 2nd Edition.
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
 * @brief Lexigraphically compare strings, using up to n characters.
 *
 * @param s first string
 * @param t second string
 * @param n Maximum number of characters to compare
 *
 * @return positive number if s is lexigraphically greater than t, else
 * @return 0 if s and t are lexigraphically equal, else
 * @return negative number if s is lexigraphically less than t.
 */
int my_strncmp(char* s, char* ct, unsigned int n);

/**
 * @brief Test driver for strncmp implementations.
 *
 * @return EXIT_SUCCESS if all tests pass successfully, else
 * @return EXIT_FAILURE.
 */
int main(void) {
    int res;

    if ((res = my_strncmp("", "", STRSIZE)) != 0) {
        printf("Error: expected: %d, result: %d\n", 0, res);
        return EXIT_FAILURE;
    }
    if ((res = my_strncmp("", "a", STRSIZE)) >= 0) {
        printf("Error: expected empty string to be less than %s\n", "a");
        printf("Error: result: %d\n", res);
        return EXIT_FAILURE;
    }
    if ((res = my_strncmp("a", "", STRSIZE)) <= 0) {
        printf("Error: expected empty string to be greater than %s\n", "a");
        printf("Error: result: %d\n", res);
        return EXIT_FAILURE;
    }
    if ((res = my_strncmp("a", "a", STRSIZE)) != 0) {
        printf("Error: expected: %d, result: %d\n", 0, res);
        return EXIT_FAILURE;
    }
    if ((res = my_strncmp("a", "b", STRSIZE)) >= 0) {
        printf("Error: expected %s to be less than %s\n", "a", "b");
        printf("Error: result: %d\n", res);
        return EXIT_FAILURE;
    }
    if ((res = my_strncmp("b", "a", STRSIZE)) <= 0) {
        printf("Error: expected %s to be greater than %s\n", "b", "a");
        printf("Error: result: %d\n", res);
        return EXIT_FAILURE;
    }
    if ((res = my_strncmp("abc", "abc", STRSIZE)) != 0) {
        printf("Error: expected: %d, result: %d\n", 0, res);
        return EXIT_FAILURE;
    }
    if ((res = my_strncmp("abc", "cba", STRSIZE)) >= 0) {
        printf("Error: expected %s to be less than %s\n", "abc", "cba");
        printf("Error: result: %d\n", res);
        return EXIT_FAILURE;
    }
    if ((res = my_strncmp("cba", "abc", STRSIZE)) <= 0) {
        printf("Error: expected %s to be greater than %s\n", "cba", "abc");
        printf("Error: result: %d\n", res);
        return EXIT_FAILURE;
    }
    if ((res = my_strncmp("ab", "aba", STRSIZE)) >= 0) {
        printf("Error: expected %s to be less than %s\n", "ab", "aba");
        printf("Error: result: %d\n", res);
        return EXIT_FAILURE;
    }
    if ((res = my_strncmp("aba", "ab", STRSIZE)) <= 0) {
        printf("Error: expected %s to be greater than %s\n", "aba", "ab");
        printf("Error: result: %d\n", res);
        return EXIT_FAILURE;
    }
    if ((res = my_strncmp("aba", "ab", 2))) {
        printf("Error: expected %s to be equal to %s for n = 2\n", "aba", "ab");
        printf("Error: result: %d\n", res);
        return EXIT_FAILURE;
    }
    if ((res = my_strncmp("aba", "ab", 1))) {
        printf("Error: expected %s to be equal to %s for n = 1\n", "aba", "ab");
        printf("Error: result: %d\n", res);
        return EXIT_FAILURE;
    }
    if ((res = my_strncmp("ab", "aba", 2))) {
        printf("Error: expected %s to be equal for n = 2 to %s\n", "ab", "aba");
        printf("Error: result: %d\n", res);
        return EXIT_FAILURE;
    }
    if ((res = my_strncmp("ab", "aba", 1))) {
        printf("Error: expected %s to equal to %s for n = 1\n", "ab", "aba");
        printf("Error: result: %d\n", res);
        return EXIT_FAILURE;
    }
    printf("All tests passed successfully\n");
    return EXIT_SUCCESS;
}

int my_strncmp(char* s, char* ct, unsigned int n) {
    for (; n && (*s == *ct); s++, ct++, n--) {
        if (*s == '\0') { return 0; }
    }
    return (n) ? (*s - *ct) : 0;
}