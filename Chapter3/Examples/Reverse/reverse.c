/**
 * @file reverse.c
 * @author Felix Lempriere
 * @brief Example Implementation of string reversal utilising the comma operator
 *
 * @version 0.1
 * @date 2025-04-28
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
    for (int i = 0, j = strlen(s) - 1; i < j; i++, j--) {
        int c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}

enum truth my_streq(char s[], char t[]) {
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] != t[i]) { return FALSE; }
    }
    return TRUE;
}

enum truth test_reverse(char in[], char expected[]) {
    reverse(in);
    if (strcmp(in, expected)) {
        printf("Error: string %s, expected: %s\n", in, expected);
        return FALSE;
    }
    return TRUE;
}