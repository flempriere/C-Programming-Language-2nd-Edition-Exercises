/**
 * @file ex2-4.c
 * @author Felix Lempriere
 * @brief Solution to Exercise 2.4 from The C Programming Language, 2nd Edition.
 *
 * Write an alternate version of `squeeze(s1, s2)` that deltes each character
 * in `s1` that matches any character in the string s2.
 *
 * @version 0.1
 * @date 2025-04-26
 *
 * @copyright Copyright (c) 2025
 *
 */

#include <stdio.h>
#include <stdlib.h>

/**
 * @brief The number of printable ASCII numbers.
 *
 */
#define N_PRINTABLE_ASCII 128

/**
 * @brief Indicates a character has already been seen.
 *
 */
#define SEEN 1

/**
 * @brief Indicates a character has not been seen
 *
 */
#define NOT_SEEN 0

/**
 * @brief Initialises an array a of length len, to the value val
 *
 * @param len
 * @param a
 * @param val
 */
void init_array(int len, int a[], int val);

/**
 * @brief Squeeze the string s1, by s2, removing all
 * characters in s1, that appear in s2.
 *
 * @param s1 String to squeeze
 * @param s2 String containing the characters to squeeze from s1.
 */
void squeeze(char s1[], char s2[]);

/**
 * @brief Squeeze the character c, from the string s.
 *
 * @param s string to squeeze
 * @param c Character to remove.
 */
void squeeze_char(char s[], int c);

/**
 * @brief Compare two strings for equality.
 *
 * @param s
 * @param t
 * @return 1 if equal, else
 * @return 0.
 */
int my_streq(char s[], char t[]);

/**
 * @brief Checks if the result string res matches
 * the expected string expected string, prints error
 * diagnostics if not.
 *
 * @param res result string
 * @param expected expected string
 * @return 1 if match, else
 * @return 0.
 */
int test_string(char res[], char expected[]);
/**
 * @brief Test driver for squeeze.
 *
 * @return EXIT_SUCCESS
 */
int main(void) {
    char c[] = "a";
    char s[] = "A string with a value";
    char s_expected[] = "A string with  vlue";

    char s1[] = "test string";
    char s1_expected[] = "test string";

    char s2[] = "";
    char s2_expected[] = "";

    squeeze(s, c);
    if (!test_string(s, s_expected)) { return EXIT_FAILURE; }

    squeeze(s1, c);
    if (!test_string(s1, s1_expected)) { return EXIT_FAILURE; }
    if (!test_string(s2, s2_expected)) { return EXIT_FAILURE; }

    char tst2[] = "Aiue";
    char stst2_expected[] = " strng wth  vlu";
    char s1tst2_expected[] = "tst strng";

    squeeze(s, tst2);
    if (!test_string(s, stst2_expected)) { return EXIT_FAILURE; }
    squeeze(s1, tst2);
    if (!test_string(s1, s1tst2_expected)) { return EXIT_FAILURE; }
    squeeze(s1, s2);
    if (!test_string(s1, s1tst2_expected)) { return EXIT_FAILURE; }
    printf("All tests passed  successfully\n");
    return EXIT_SUCCESS;
}

void init_array(int len, int a[], int val) {
    for (int i = 0; i < len; i++) { a[i] = val; }
}

void squeeze(char s1[], char s2[]) {
    int char_set[N_PRINTABLE_ASCII];
    init_array(N_PRINTABLE_ASCII, char_set, NOT_SEEN);
    for (int i = 0; s2[i] != '\0'; ++i) {
        int c = s2[i];
        if (!char_set[c]) {
            squeeze_char(s1, c);
            char_set[c] = SEEN;
        }
    }
}

void squeeze_char(char s[], int c) {
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

int test_string(char res[], char expected[]) {
    if (!my_streq(res, expected)) {
        printf("Error: string %s, expected: %s\n", res, expected);
        return 0;
    }
    return 1;
}