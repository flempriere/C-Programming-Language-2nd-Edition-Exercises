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
 * @return 1 if equal, else
 * @return 0.
 */
int my_streq(char s[], char t[]);

int main(void) {
    int c = 'a';
    char s[] = "A string with a value";
    char s_expected[] = "A string with  vlue";

    char s1[] = "test string";
    char s1_expected[] = "test string";

    char s2[] = "";
    char s2_expected[] = "";

    squeeze(s, c);
    if (!my_streq(s, s_expected)) {
        printf("Error: string %s, expected: %s\n", s, s_expected);
        return EXIT_FAILURE;
    }

    squeeze(s1, c);
    if (!my_streq(s1, s1_expected)) {
        printf("Error: string %s, expected: %s\n", s1, s1_expected);
        return EXIT_FAILURE;
    }

    squeeze(s2, c);
    if (!my_streq(s2, s2_expected)) {
        printf("Error: string %s, expected: %s\n", s2, s2_expected);
        return EXIT_FAILURE;
    }
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

int my_streq(char s[], char t[]) {
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] != t[i]) { return 0; }
    }
    return 1;
}