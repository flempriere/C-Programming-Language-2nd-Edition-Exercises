/**
 * @file strncat.c
 * @author Felix Lempriere
 * @brief Pointer implementation of strncat in partial completion of Exercise
 * 5.5 from The C Programming Language, 2nd Edition.
 * @version 0.1
 * @date 2025-05-09
 *
 * @copyright Copyright (c) 2025
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @brief size to allocate the string buffers
 *
 */
#define STR_BUF 100

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
 * @brief Concatenate at most n characters from t onto s.
 *
 * @param s destination string
 * @param t source string
 * @param n Maximum number of characters to copy.
 * @return char* pointer to s
 */
char* my_strncat(char* s, char* t, unsigned n);

/**
 * @brief Tests the implementation of strncat. By copying s to
 * an intermediate register and calling my_strncat(s, t, n). If this does
 * not match the expected an error diagnostic is printed.
 *
 * @param s first part of the concatenated string
 * @param t second part of the concatenated string
 * @param n maximum number of characters to copy.
 * @param expected Expected result of my_strncat(s,t, n).
 *
 * @return TRUE if test passes, else
 * @return FALSE
 */
enum truth test_strncat(char* s, char* t, unsigned n, char* expected);

/**
 * @brief Test driver for strcmp implementations.
 *
 * @return EXIT_SUCCESS if all tests pass successfully, else
 * @return EXIT_FAILURE.
 */
int main(void) {
    char s[STR_BUF] = "";
    char s1[STR_BUF] = "First";
    char s2[STR_BUF] = "Second";

    if (!test_strncat("First", "", STR_BUF, "First")) { return EXIT_FAILURE; }
    if (!test_strncat(s, "First", STR_BUF, "First")) { return EXIT_FAILURE; }
    if (!test_strncat(s1, s2, STR_BUF, "FirstSecond")) { return EXIT_FAILURE; }
    if (!test_strncat(s1, s2, 0, "First")) { return EXIT_FAILURE; }
    if (!test_strncat(s, s2, 3, "Sec")) { return EXIT_FAILURE; }

    printf("All tests passed successfully\n");
    return EXIT_SUCCESS;
}
char* my_strncat(char* s, char* ct, unsigned n) {
    char* ret = s;
    while (*s) { s++; }
    for (; n && (*s = *ct); s++, ct++, n--);
    if (n) { *s = '\0'; }
    return ret;
}

enum truth test_strncat(char* s, char* t, unsigned int n, char* expected) {
    char res[STR_BUF];
    for (int i = 0; i < STR_BUF; i++) { res[i] = '\0'; }
    strcpy(res, s);
    my_strncat(res, t, n);
    if (strcmp(res, expected)) {
        printf("Error: concatenation failed\n");
        printf("Expected: %s,  Result: %s\n", expected, res);
        return FALSE;
    }
    return TRUE;
}