/**
 * @file strcat.c
 * @author Felix Lempriere
 * @brief Example program demonstrating concatenation of one string to another.
 * @version 0.1
 * @date 2025-04-26
 *
 * @copyright Copyright (c) 2025
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
 * @brief Concatenate t to the end of s.
 * S must be large enough to add t.
 *
 * @param s first string
 * @param t string to append to s.
 */
void my_strcat(char s[], char t[]);

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
 * @brief Test driver for my strcat.
 *
 * @return EXIT_SUCCESS if all tests passed successfully, else
 * @return EXIT_FAILURE
 */
int main(void) {
    char s[STR_BUF] = "";
    char s1[STR_BUF] = "First";
    char s2[STR_BUF] = "Second";

    my_strcat(s1, s);
    if (!test_string(s1, "First")) { return EXIT_FAILURE; }
    my_strcat(s, s1);
    if (!test_string(s, "First")) { return EXIT_FAILURE; }
    my_strcat(s1, s2);
    if (!test_string(s1, "FirstSecond")) { return EXIT_FAILURE; }
    printf("All tests passed successfully\n");
    return EXIT_SUCCESS;
}

void my_strcat(char s[], char t[]) {
    int i = 0;
    int j = 0;
    while (s[i] != '\0') {    // find the end of s
        i++;
    }
    while ((s[i++] = t[j++]) != '\0'); /* copy t */
}

enum truth test_string(char res[], char expected[]) {
    if (strcmp(res, expected)) {
        printf("Error: string %s, expected: %s\n", res, expected);
        return FALSE;
    }
    return TRUE;
}