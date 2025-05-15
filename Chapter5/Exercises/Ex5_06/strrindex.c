/**
 * @file strrindex.c
 * @author Felix Lempriere
 * @brief Pointer implementation of strrindex in partial fulfillment of
 * Exercise 5.6 from The C Programming Language, 2nd Edition.
 * @version 0.1
 * @date 2025-05-10
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
 * @brief External pattern to match
 *
 */
char pattern[] = "ould";

/**
 * @brief Finds the first occurence of the pattern pat, in the string src.
 *
 * @param src string to search.
 * @param pat pattern to match
 * @return index denoting the start of the first match, else
 * @return -1 if not match is found.
 */
int strrindex(char* src, char* pat);

/**
 * @brief Tests strrindex on the input string in, and compares the output
 * against the expected result expected.
 *
 * Performs strrindex(in, pattern) and compares against the expected output. If
 * the results disagree then an error diagnostic is reported.
 *
 * @param in input string to test the match
 * @param expected expected output
 * @return TRUE if strrindex(in, pattern) == expected, else
 * @return FALSE
 */
enum truth test_strrindex(char* in, int expected);

/**
 * @brief Test driver for strrindex
 *
 * @return EXIT_SUCCESS if all tests passed, else
 * @return EXIT_FAILURE
 */
int main(void) {
    if (!test_strrindex("", -1)) { return EXIT_FAILURE; }
    if (!test_strrindex("ould", 0)) { return EXIT_FAILURE; }
    if (!test_strrindex("could", 1)) { return EXIT_FAILURE; }
    if (!test_strrindex("could would should", 14)) { return EXIT_FAILURE; }
    printf("All tests passed successfully\n");
    return EXIT_SUCCESS;
}

int strrindex(char* src, char* pat) {
    char* a = src;
    int found = -1;
    for (; *src != '\0'; src++) {
        char* c = pat;
        for (char* b = src; *c != '\0' && *b == *c; b++, c++);
        if (c > pat && *c == '\0') { found = src - a; }
    }
    return found;
}

enum truth test_strrindex(char in[], int expected) {
    int res = strrindex(in, pattern);
    if (res != expected) {
        printf("Error during strrindex of %s against %s\n", in, pattern);
        printf("Result: %d, Expected: %d\n", res, expected);
        return FALSE;
    }
    return TRUE;
}