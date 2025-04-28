/**
 * @file ex3-2.c
 * @author Felix Lempriere
 * @brief Solution to Exercise 3.2 from The C Programming Language, 2nd Edition
 *
 * Write a function `escape(s, t)` that converts characters like newline and tab
 * into visible escape sequences like `\n` and `\t` as it copies the string t
 * to s. Use a `switch`. Write a function `unescape(s,t)` that does the reverse.
 *
 * @remark This version handles all the ASCII C0 control characters with an
 * escape sequence i.e. \\a (Bell), \\b (Backspace), \t (tab), \\n (newline), 
 * \v (vertical tab), \f (form feed), \r (carriage return). Note we exlude the
 * \0 symbol itself.
 * 
 * @version 0.1
 * @date 2025-04-28
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
 * @brief Maximum size of a string buffer.
 *
 */
#define MAX_LENGTH 100

/**
 * @brief Copies the string t to the string s, converting
 * escape sequence characters like newline and tab to their
 * visible equivalent.
 *
 * @warning s must be big enough to hold the escaped version of t.
 *
 * @param dest destination string
 * @param src source string
 */
void escape(char dest[], char src[]);

/**
 * @brief Copies the string t to the string s, converting escape sequences
 * into the corresponding characters, e.g. \\n -> newline and \t -> tab.
 *
 * @warning s must be big enough to hold the unescaped version of t.
 *
 * @param dest destination string
 * @param src source string
 */
void unescape(char dest[], char src[]);

/**
 * @brief Compare two strings for equality.
 *
 * @param s
 * @param t
 * @return TRUE if equal, else
 * @return FALSE.
 */
enum truth my_streq(char s[], char t[]);

/**
 * @brief Tests unescape and escape, by performing escape on the string
 * s, check this against the expected string and then checking that unescape
 * converts it back.
 *
 * @param s input string
 * @param expected expected string
 * @return TRUE if test passes, else
 * @return FALSE.
 */
enum truth test_string(char s[], char expected[]);

/**
 * @brief Test driver for escape and unescape.
 *
 * @return EXIT_SUCCESS if all tests passed, else
 * @return EXIT_FAILURE
 */
int main(void) {

    if (!test_string("", "")) {
        return EXIT_FAILURE;
    }
    if (!test_string("a", "a")) {
        return EXIT_FAILURE;
    }
    if (!test_string("abc", "abc")) {
        return EXIT_FAILURE;
    }
    if (!test_string("\a", "\\a")) {
        return EXIT_FAILURE;
    }
    if (!test_string("\b", "\\b")) {
        return EXIT_FAILURE;
    }
    if (!test_string("\f", "\\f")) {
        return EXIT_FAILURE;
    }
    if (!test_string("\n", "\\n")) {
        return EXIT_FAILURE;
    }
    if (!test_string("\r", "\\r")) {
        return EXIT_FAILURE;
    }
    if (!test_string("\t", "\\t")) {
        return EXIT_FAILURE;
    }
    if (!test_string("\v", "\\v")) {
        return EXIT_FAILURE;
    }
    if (!test_string("ab\acd\tef\n", "ab\\acd\\tef\\n")) {
        return EXIT_FAILURE;
    }
    printf("All tests passed successfully\n");
    return EXIT_SUCCESS; 
}

void escape(char dest[], char src[]) {
    int j = 0;
    for (int i = 0; src[i] != '\0'; i++) {
        switch (src[i]) {
        case '\a':
            dest[j++] = '\\';
            dest[j++] = 'a';
            break;
        case '\b':
            dest[j++] = '\\';
            dest[j++] = 'b';
            break;
        case '\f':
            dest[j++] = '\\';
            dest[j++] = 'f';
            break;
        case '\n':
            dest[j++] = '\\';
            dest[j++] = 'n';
            break;
        case '\r':
            dest[j++] = '\\';
            dest[j++] = 'r';
            break;
        case '\t':
            dest[j++] = '\\';
            dest[j++] = 't';
            break;
        case '\v':
            dest[j++] = '\\';
            dest[j++] = 'v';
            break;
        default:
            dest[j++] = src[i];
            break;
        }
    }
    dest[j] = '\0';
}

void unescape(char dest[], char src[]) {
    int j = 0;
    for (int i = 0; src[i] != '\0'; i++) {
        switch (src[i]) {
        case '\\':
            switch (src[++i]) {
            case 'a':
                dest[j++] = '\a';
                break;
            case 'b':
                dest[j++] = '\b';
                break;
            case 'f':
                dest[j++] = '\f';
                break;
            case 'n':
                dest[j++] = '\n';
                break;
            case 'r':
                dest[j++] = '\r';
                break;
            case 't':
                dest[j++] = '\t';
                break;
            case 'v':
                dest[j++] = '\v';
                break;
            default:
                dest[j++] = '\\';
                dest[j++] = src[i];
                break;
            }
            break;
        default:
            dest[j++] = src[i];
            break;
        }
    }
    dest[j] = '\0';
}

enum truth my_streq(char s[], char t[]) {
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] != t[i]) { return FALSE; }
    }
    return TRUE;
}

enum truth test_string(char s[], char expected[]) {
    char intermediate[MAX_LENGTH];
    char output[MAX_LENGTH];
    escape(intermediate, s);
    if (!my_streq(intermediate, expected)) {
        printf("Error escaping %s produced %s\n", s, intermediate);
        printf("Expected: %s\n", expected);
        return FALSE;
    }
    unescape(output, intermediate);
    if (!my_streq(s, output)) {
        printf("Error unescaping %s produced %s\n", intermediate, output);
        printf("Expected %s\n", s);
        return FALSE;
    }
    return TRUE;
}