/**
 * @file strindex.c
 * @author Felix Lempriere
 * @brief Pointer implementation of strindex in partial fulfillment of
 * Exercise 5.6 from The C Programming Language, 2nd Edition.
 *
 * @version 0.1
 * @date 2025-04-30
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
 * @brief Finds the first occurence of the pattern pat, in the string src.
 *
 * @param src string to search.
 * @param pat pattern to match
 * @return index denoting the start of the first match, else
 * @return -1 if not match is found.
 */
int strindex(char* src, char* pat);

/**
 * @brief Tests strindex on the input string in, and compares the output
 * against the expected result expected.
 *
 * Performs strindex(in, pattern) and compares against the expected output. If
 * the results disagree then an error diagnostic is reported.
 *
 * @param in input string to test the match
 * @param expected expected output
 * @return TRUE if strindex(in, pattern) == expected, else
 * @return FALSE
 */
enum truth test_strindex(char* in, int expected);

/**
 * @brief Fixed search pattern.
 *
 */
char pattern[] = "ould";

/**
 * @brief pattern matching implementation.
 *
 * @return int, the number of matches found.
 */
int main(void) {
    if (!test_strindex("", -1)) { return EXIT_FAILURE; }
    if (!test_strindex("ould", 0)) { return EXIT_FAILURE; }
    if (!test_strindex("could", 1)) { return EXIT_FAILURE; }
    if (!test_strindex("could would should", 1)) { return EXIT_FAILURE; }
    printf("All tests passed successfully\n");
    return EXIT_SUCCESS;
}

int strindex(char src[], char pat[]) {
    char* a = src;
    for (; *src != '\0'; src++) {
        char* c = pat;
        for (char* b = src; *c != '\0' && *b == *c; b++, c++);
        if (c > pat && *c == '\0') { return src - a; }
    }
    return -1;
}

enum truth test_strindex(char in[], int expected) {
    int res = strindex(in, pattern);
    if (res != expected) {
        printf("Error during strrindex of %s against %s\n", in, pattern);
        printf("Result: %d, Expected: %d\n", res, expected);
        return FALSE;
    }
    return TRUE;
}