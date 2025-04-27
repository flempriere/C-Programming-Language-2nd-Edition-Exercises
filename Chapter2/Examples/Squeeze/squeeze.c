/**
 * @file squeeze.c
 * @author Felix Lempriere
 * @brief Implements a function squeeze that removes all instances of a
 * character c from the string s.
 * @version 0.1
 * @date 2025-04-26
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
 * @brief Deletes all instances of a character c from the string s
 *
 * @param s string buffer
 * @param c character to remove from s.
 */
void squeeze(char s[], int c);

/**
 * @brief Test to strings for equality.
 *
 * @param s
 * @param t
 * @return TRUE if equal, else
 * @return FALSE.
 */
enum truth my_streq(char s[], char t[]);

/**
 * @brief Checks if the result string res matches
 * the expected string expected string, prints error
 * diagnostics if not.
 *
 * @param res result string
 * @param expected expected string
 * @return TRUE if match, else
 * @return FALSE.
 */
enum truth test_string(char res[], char expected[]);

/**
 * @brief Test driver for squeeze
 *
 * @return EXIT_SUCCESS if all tests passed successfully, else
 * @return EXIT_FAILURE.
 */
int main(void) {
    int c = 'a';
    char s[] = "A string with a value";
    char s1[] = "test string";
    char s2[] = "";

    squeeze(s, c);
    if (!test_string(s, "A string with  vlue")) { return EXIT_FAILURE; }
    squeeze(s1, c);
    if (!test_string(s1, "test string")) { return EXIT_FAILURE; }
    squeeze(s2, c);
    if (!test_string(s2, "")) { return EXIT_FAILURE; }
    printf("All tests passed\n");
    return EXIT_SUCCESS;
}

void squeeze(char s[], int c) {
    int j = 0;
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] != c) { s[j++] = s[i]; }
    }
    s[j] = '\0';
}

enum truth my_streq(char s[], char t[]) {
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] != t[i]) { return FALSE; }
    }
    return TRUE;
}

enum truth test_string(char res[], char expected[]) {
    if (!my_streq(res, expected)) {
        printf("Error: string %s, expected: %s\n", res, expected);
        return FALSE;
    }
    return TRUE;
}