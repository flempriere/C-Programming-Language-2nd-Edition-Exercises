/**
 * @file strncpy.c
 * @author Felix Lempriere
 * @brief Pointer implementation of strncpy in partial completion of Exercise
 * 5.5 from The C Programming Language, 2nd Edition.
 * @version 0.1
 * @date 2025-05-09
 *
 * @copyright Copyright (c) 2025
 *
 */

#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Maximum size for the string
 *
 */
#define STRSIZE 100

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
 * @brief Copies n characters from ct to s.
 *
 * Copies n characters from ct to s, if ct is less than n characters long, s
 * is padded with null characters to a total size of n.
 *
 * @param s destrination for copy
 * @param ct source for copy
 * @param n number of characters to copy
 * @return char* pointer to destination string.
 */
char* my_strncpy(char* s, char* ct, unsigned n);

/**
 * @brief Tests strncpy printing an error diagnostic if the test fails.
 *
 * @param in input string to copy
 * @param n number of characters to copy
 * @return TRUE if test passed, else
 * @return FALSE
 */
enum truth test_strncpy(char in[], unsigned n);

/**
 * @brief Test driver for strncpy
 *
 * @return EXIT_SUCCESS if all tests passed, else
 * @return EXIT_FAILURE.
 */
int main(void) {
    if (!test_strncpy("", STRSIZE)) { return EXIT_FAILURE; }
    if (!test_strncpy("a", STRSIZE)) { return EXIT_FAILURE; }
    if (!test_strncpy("abc", STRSIZE)) { return EXIT_FAILURE; }
    if (!test_strncpy("abc", 2)) { return EXIT_FAILURE; }
    printf("All tests passed successfully\n");
    return EXIT_SUCCESS;
}

char* my_strncpy(char* s, char* ct, unsigned n) {
    char* ret = s;
    for (; n && (*s = *ct); s++, ct++, n--);
    for (; n; --n) { *s++ = '\0'; }    // pad any remaining characters
    return ret;
}

enum truth test_strncpy(char* in, unsigned n) {
    char s[STRSIZE];
    for (int i = 0; i < STRSIZE; i++) { s[i] = '\0'; }
    my_strncpy(s, in, n);
    for (unsigned i = 0; i < n && s[i]; i++) {
        if (s[i] != in[i]) { return FALSE; }
    }
    return TRUE;
}