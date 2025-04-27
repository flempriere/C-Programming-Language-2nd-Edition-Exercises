/**
 * @file ex3-2.c
 * @author Felix Lempriere
 * @brief Solution to Exercise 3.2 from The C Programming Language, 2nd Edition
 *
 * Write a function `escape(s, t)` that converts characters like newline and tab
 * into visible escape sequences like `\n` and `\t` as it copies the string t
 * to s. Use a `switch`. Write a function `unescape(s,t)` that does the reverse.
 * @version 0.1
 * @date 2025-04-28
 *
 * @copyright Copyright (c) 2025
 *
 */

#include <stdio.h>
#include <stdlib.h>

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
 * @brief Test driver for escape and unescape.
 *
 * @return EXIT_SUCCESS
 */
int main(void) { return EXIT_SUCCESS; }

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
            dest[j++] = 'b';
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
        case '\\':
            dest[j++] = '\\';
            dest[j++] = '\\';
            break;
        case '\?':
            dest[j++] = '\\';
            dest[j++] = '?';
            break;
        case '\'':
            dest[j++] = '\\';
            dest[j++] = '\'';
            break;
        case '\"':
            dest[j++] = '\\';
            dest[j++] = '"';
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
            case 't':
                dest[j++] = '\t';
                break;
            case 'v':
                dest[j++] = '\v';
                break;
            case '\\':
                dest[j++] = '\\';
                break;
            case '?':
                dest[j++] = '\?';
                break;
            case '\'':
                dest[j++] = '\'';
                break;
            case '"':
                dest[j++] = '\"';
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