/**
 * @file strcpy.c
 * @author Felix Lempriere
 * @brief Three versions of string copy demonstrating the use of pointer vs array
 * syntax.
 * @version 0.1
 * @date 2025-05-09
 *
 * @copyright Copyright (c) 2025
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
 * @brief Strcpy implementation using an internal array syntax.
 * 
 * @param s string to copy to.
 * @param t string to copy from.
 */
void strcpy_a(char* s, char* t);

/**
 * @brief strcpy implementation using an internal pointer syntax.
 * 
 * @param s string to copy to.
 * @param t string to copy from.
 */
void strcpy_p(char* s, char* t);

/**
 * @brief strcpy implementation using pointer and assignment operators.
 *
 * @param s string to copy to.
 * @param t string to copy from.
 */
void strcpy_o(char* s, char* t);

/**
 * @brief Test both implementations of strcpy,
 * by performing a copy and checking the strings equal.
 * 
 * @param in 
 * @return TRUE if test passed, else
 * @return FALSE.
 */
enum truth test_strcpy(char in[]);

/**
 * @brief Test driver for strcpy implementations
 * 
 * @return EXIT_SUCCESS if all tests passed, else
 * @return EXIT_FAILURE.
 */
int main(void) {
    if (!test_strcpy("")) {
        return EXIT_FAILURE;
    }
    if (!test_strcpy("a")) {
        return EXIT_FAILURE;
    }
    if (!test_strcpy("abc")) {
        return EXIT_FAILURE;
    }
    printf("All tests passed successfully\n");
    return EXIT_SUCCESS;
}

void strcpy_a(char* s, char* t) {
    int i = 0;
    while ((s[i] = t[i]) != '\0') { i++; }
}

void strcpy_p(char* s, char* t) {
    while ((*s = *t) != '\0') {
        s++;
        t++;
    }
}

void strcpy_o(char* s, char* t) {
    while ((*s++ = *t++));
}

enum truth test_strcpy(char in[]) {
    char t1[STRSIZE];
    char t2[STRSIZE];
    char t3[STRSIZE];

    strcpy_a(t1, in);
    if (strcmp(t1, in)) {
        printf("Error: mismatch after array-based string copy\n");
        printf("Result: %s, Output: %s\n", t1, in);
        return FALSE;
    }

    strcpy_p(t2, in);
    if (strcmp(t2, in)) {
        printf("Error: mismatch after pointer-based string copy\n");
        printf("Result: %s, Output: %s\n", t2, in);
        return FALSE;
    }

    strcpy_o(t3, in);
    if (strcmp(t3, in)) {
        printf("Error: mismatch after assignment operator string copy\n");
        printf("Result: %s, Output: %s\n", t3, in);
        return FALSE;
    }
    return TRUE;
}