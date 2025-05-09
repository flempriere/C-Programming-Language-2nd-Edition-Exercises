/**
 * @file ex5-3.c
 * @author Felix Lempriere
 * @brief Solution to Exercise 5.3 from The C Programming Language, 2nd Edition.
 *
 * Write a pointer version of the function `strcat` that we showed in Chapter 2:
 * `strcat(s, t)` copies the string t to the end of the string t.
 *
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
 * @brief Concatenate t to the end of s.
 * S must be large enough to add t.
 *
 * @param s first string
 * @param t string to append to s.
 */
void my_strcat(char s[], char t[]);

/**
 * @brief Compare two strings for equality
 *
 * @param s
 * @param t
 * @return TRUE if equal else,
 * @return FALSE
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
    while(*s != '\0') {
        s++;
    }
    while((*s++ = *t++));
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