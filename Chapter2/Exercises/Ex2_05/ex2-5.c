/**
 * @file ex2-5.c
 * @author Felix Lempriere
 * @brief Solution to Exercise 2.5 from The C Programming Language, 2nd Edition
 *
 * Write the function `any(s1, s2)` which returns the first location in the
 * string `s1` where any character from the string `s2` occurs, or -1 if s1
 * contains no characters from `s2`. (The standard library function strpbrk
 * does the same job but returns a pointer to the location.)
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
 * @brief Indicates that no match was found.
 *
 * @see any
 */
#define NO_MATCH -1

/**
 * @brief Returns the index corresponding to the first
 * occurence of a character c in s1, that also occurs
 * in s2.
 *
 * @param s1 string to search
 * @param s2 string containing characters to match against.
 * @return index of the first match, else
 * @return NO_MATCH if no match is found.
 *
 * @see NO_MATCH
 */
int any(char s1[], char s2[]);

/**
 * @brief Check that the result of idx, matches expected
 * and print a diagnostic otherwise.
 *
 * @param s1 string to search in.
 * @param s2 string containing characters to search for.
 * @param expected expected value of s1 after performing any(s1, s2).
 * @return TRUE if result of any(s1, s2) matches expected, else
 * @return FALSE.
 */
enum truth test_any(char s1[], char s2[], int expected);
/**
 * @brief Test driver for the function any.
 *
 * @return EXIT_SUCCESS if all tests passed, else
 * @return EXIT_FAILURE
 */
int main(void) {
    char s[] = "abc def";
    char tst1[] = "";
    char tst2[] = " ";
    char tst3[] = "a";
    char tst4[] = "bdf";

    if (!test_any(s, tst1, NO_MATCH)) { return EXIT_FAILURE; }
    if (!test_any(s, tst2, 3)) { return EXIT_FAILURE; }
    if (!test_any(s, tst3, 0)) { return EXIT_FAILURE; }
    if (!test_any(s, tst4, 1)) { return EXIT_FAILURE; }
    printf("All tests passed successfully\n");
    return EXIT_SUCCESS;
}

int any(char s1[], char s2[]) {
    for (int i = 0; s1[i] != '\0'; i++) {
        for (int j = 0; s2[j] != '\0'; j++) {
            if (s1[i] == s2[j]) { return i; }
        }
    }
    return NO_MATCH;
}

enum truth test_any(char s1[], char s2[], int expected) {
    int res;
    if ((res = any(s1, s2)) != expected) {
        printf("Error: input: %s, output: %s\n", s1, s2);
        printf("Error: result: %d, expected: %d\n", res, expected);
        return FALSE;
    }
    return TRUE;
}