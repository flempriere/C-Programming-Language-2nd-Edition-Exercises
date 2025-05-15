/**
 * @file ex4_13.c
 * @author Felix Lempriere
 * @brief Solution to Exercise 4.13 from The C Programming Language, 2nd Edition.
 *
 * Write a recursive version of the function `reverse(s)`, which reverses the
 * string `s` in place.
 * 
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
 * @brief Reverse a string s inplace.
 *
 * @param s string to reverse.
 */
void reverse(char s[]);

/**
 * @brief Recursive reverse subroutine.
 *
 * Swaps the characters s[i] and s[j].
 * 
 * @param s string to reverse
 * @param i index to swap
 * @param j index to swap
 */
void reverse_r(char s[], int i, int j);

/**
 * @brief Swaps two characters in a string
 * 
 * @param s string
 * @param i index to swap
 * @param j index to swap
 */
void swap(char s[], int i, int j);

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
 * @brief Test reverse(in) and compare to the expected.
 *
 * Given a string in, runs reverse on it and compares
 * the output to expected. Prints an error diagnostic if they disagree.
 *
 * @param in input string
 * @param expected expected result of reverse(in)
 * @return TRUE if reverse(in) == expected (as string equality), else
 * @return FALSE.
 */
enum truth test_reverse(char in[], char expected[]);

/**
 * @brief Test driver for reverse
 *
 * @return EXIT_SUCCESS if all tests passed, else
 * @return EXIT_FAILURE
 */
int main(void) {
    char s[] = "";
    if (!test_reverse(s, "")) { return EXIT_FAILURE; }
    char s1[] = "a";
    if (!test_reverse(s1, "a")) { return EXIT_FAILURE; }
    char s2[] = "ab";
    if (!test_reverse(s2, "ba")) { return EXIT_FAILURE; }
    char s3[] = "abc";
    if (!test_reverse(s3, "cba")) { return EXIT_FAILURE; }
    printf("All tests passed successfully\n");
    return EXIT_SUCCESS;
}

void reverse(char s[]) {
    reverse_r(s, 0, strlen(s) - 1);
}

void reverse_r(char s[], int i, int j) {
    if (i < j) {
        swap(s, i, j);
        reverse_r(s, ++i, --j);
    }
}

void swap(char s[], int i, int j) {
    char t = s[j];
    s[j] = s[i];
    s[i] = t;
}

enum truth test_reverse(char in[], char expected[]) {
    reverse(in);
    if (strcmp(in, expected)) {
        printf("Error: string %s, expected: %s\n", in, expected);
        return FALSE;
    }
    return TRUE;
}