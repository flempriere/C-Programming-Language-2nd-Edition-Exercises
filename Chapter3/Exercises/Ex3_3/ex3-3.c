/**
 * @file ex3-3.c
 * @author Felix Lempriere
 * @brief Solution to Exercise 3.3 from The C Programming Language, 2nd Edition.
 *
 * Write a function `expand(s1, s2)` that expands shorthand notations like
 * `a-z` in the string `s1` into the equivalent complete list `abc...xyz` in
 * `s2`. Allow for letters of either case and digits, and be prepared to handle
 * cases like `a-b-c` and `a-z0-9` and `-a-z`. Arrange that a leading or
 * trailing `-` is taken literally.
 *
 * Specially we handle the following cases as follows
 * 1. Leading '-' ignored.
 * 2. Trailing '-' ignored.
 * 3. a-c -> abc
 * 4. a-b-c -> abc
 * 5. 0-3 -> 0123
 * 6. a-A -> ignored
 * 7. A-a -> ignored
 * 8. 0-a -> treated as hexdigit expansion.
 * 9. 0-B -> treated as hexidigit expansion.
 * 10. 3-0 -> 3210
 * 11. a-a -> unchanged
 * Should also treat ... as equivalent.
 *
 * @version 0.1
 * @date 2025-04-28
 *
 * @copyright Copyright (c) 2025
 *
 */

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @brief maximum line buffer size
 *
 */
#define MAX_SIZE 100

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
 * @brief Enum to track if we are matching lowercase expansions, uppercase
 * expansions, or hex digit expansions.
 *
 */
enum parse_state {
    NONE,
    LOWER,
    UPPER,
    DIGIT
};

/**
 * @brief Expands shorthand notatation like a-z in the src string and stores the
 * expanded results in dest.
 *
 * Expands out shorthand notations designated with either a - or ..., cases must
 * match, i.e. a-c is expanded but a-C is not. decimal expansions like 0...9 are
 * expanded normally but expressions like 8...B are treated as a hexadecimal
 * expansion.
 *
 * @warning dest must be sufficiently sized to store the expansion of src.
 *
 * @param src string to expand
 * @param dest dest contains the expanded string.
 */
void expand(char src[], char dest[]);

/**
 * @brief Checks if there exists a valid expansion starting at the character at
 * position i in the string s.
 *
 * @param s string being expanded
 * @param i index of the chracter to check
 * @return Number of characters to be consumed by a valid expansion, else
 * @return 0 if no valid expansion.
 */
int has_expansion(char s[], int i);

/**
 * @brief Stores the expansion from start to stop in the string s, starting at
 * position i.
 *
 * @param s string to store expansion in
 * @param i index to start the expansion
 * @param start character starting the expansion
 * @param stop character ending the expansion
 *
 * @pre start and stop must be a valid expansion pair, if
 * - start is upper case, stop must be upper case or a digit.
 * - start is lower case, start must be lower case or a digit.
 * - start is a digit, stop must be a valid hexadecimal digit.
 *
 * @return Next free index in string s.
 */
int expand_substring(char s[], int i, char start, char stop);

/**
 * @brief Tests the expand function by expanding the string in, and comparing
 * with expected. If they don't agree an error diagnostic is printed.
 *
 * @param in string to expand
 * @param expected expected result of expanding in
 * @return TRUE expand(in, dest) == expected (as lexigraphical equality) else,
 * @return FALSE.
 */
enum truth test_expand(char in[], char expected[]);

/**
 * @brief Test driver for expand(src, dest)
 *
 * @return EXIT_SUCCESS if all tests passed successfully, else
 * @return EXIT_FAILURE.
 *
 */
int main(void) {
    if (!test_expand("", "")) { return EXIT_FAILURE; }
    if (!test_expand("0", "0")) { return EXIT_FAILURE; }
    if (!test_expand("a", "a")) { return EXIT_FAILURE; }
    if (!test_expand("A", "A")) { return EXIT_FAILURE; }
    if (!test_expand("-", "-")) { return EXIT_FAILURE; }
    if (!test_expand("-A", "-A")) { return EXIT_FAILURE; }
    if (!test_expand("A-", "A-")) { return EXIT_FAILURE; }
    if (!test_expand("a-c", "abc")) { return EXIT_FAILURE; }
    if (!test_expand("a-b-c", "abc")) { return EXIT_FAILURE; }
    if (!test_expand("c-a", "cba")) { return EXIT_FAILURE; }
    if (!test_expand("c-b-a", "cba")) { return EXIT_FAILURE; }
    if (!test_expand("0-3", "0123")) { return EXIT_FAILURE; }
    if (!test_expand("3-0", "3210")) { return EXIT_FAILURE; }
    if (!test_expand("a-B", "a-B")) { return EXIT_FAILURE; }
    if (!test_expand("B-a", "B-a")) { return EXIT_FAILURE; }
    if (!test_expand("0-a", "0123456789a")) { return EXIT_FAILURE; }
    if (!test_expand("0-B", "0123456789AB")) { return EXIT_FAILURE; }
    if (!test_expand("C-8", "CBA98")) { return EXIT_FAILURE; }
    if (!test_expand("a-a", "a-a")) { return EXIT_FAILURE; }
    if (!test_expand("1-1", "1-1")) { return EXIT_FAILURE; }
    if (!test_expand("...", "...")) { return EXIT_FAILURE; }
    if (!test_expand("...a", "...a")) { return EXIT_FAILURE; }
    if (!test_expand("a...", "a...")) { return EXIT_FAILURE; }
    if (!test_expand("1...3", "123")) { return EXIT_FAILURE; }
    if (!test_expand("a...c", "abc")) { return EXIT_FAILURE; }
    if (!test_expand("c...a", "cba")) { return EXIT_FAILURE; }
    if (!test_expand("8...C", "89ABC")) { return EXIT_FAILURE; }
    if (!test_expand("C...8", "CBA98")) { return EXIT_FAILURE; }
    if (!test_expand("A..B", "A..B")) { return EXIT_FAILURE; }
    if (!test_expand("a-z0-9", "abcdefghijklmnopqrstuvwxyz0123456789")) {
        return EXIT_FAILURE;
    }
    if (!test_expand("-a-z", "-abcdefghijklmnopqrstuvwxyz")) {
        return EXIT_FAILURE;
    }
    printf("All tests passed successfully\n");
    return EXIT_SUCCESS;
}

void expand(char src[], char dest[]) {
    int j = 0;
    int k;
    for (int i = 0; src[i] != '\0';) {
        if ((src[i + 1] == '-' || src[i + 1] == '.') &&
            (k = has_expansion(src, i))) {
            j = expand_substring(dest, j, src[i], src[i + k]);
            i += k;
        } else {
            dest[j++] = src[i++];
        }
    }
}

int has_expansion(char s[], int i) {
    enum parse_state state =
        islower(s[i]) ?
            LOWER :
            (isupper(s[i]) ? UPPER : (isdigit(s[i]) ? DIGIT : NONE));
    if (state == NONE) { return 0; }
    int j = 1;
    switch (s[i + j]) {
    case '.':
        int dots = 0;
        while (s[i + j] == '.') {
            dots++;
            j++;
        }
        if (dots != 3) { return 0; }
        break;
    case '-':
        j++;
        break;
    default:
        return 0;
        break;
    }
    switch (state) {
    case LOWER:
        j = (islower(s[i + j]) || isdigit(s[i + j])) ? j : 0;
        break;
    case UPPER:
        j = (isupper(s[i + j]) || isdigit(s[i + j])) ? j : 0;
        break;
    case DIGIT:
        char c = tolower(s[i + j]);
        j = (isdigit(s[i + j])) || ('a' <= c && c <= 'f') ? j : 0;
        break;
    case NONE:
        j = 0;
        break;
    }
    j = (s[i] == s[i + j]) ? 0 : j;
    return j;
}

int expand_substring(char s[], int i, char start, char stop) {
    if (isupper(start) || islower(start)) {
        if (isupper(stop) || islower(stop)) {    // normal alphabetic expansion
            while (start < stop) { s[i++] = start++; }
            while (start > stop) { s[i++] = start--; }    // handles a-d or d-a.
        } else {
            while (tolower(start) >= 'a') { s[i++] = start--; }
            start = '9';
            while (start > stop) { s[i++] = start--; }
        }
    } else {    // start is a digit
        while (start < stop && isdigit(start)) { s[i++] = start++; }
        while (start > stop) { s[i++] = start--; }
        if (!isdigit(stop)) {    // need to expand hex part
            start = isupper(stop) ? 'A' : 'a';
            while (start < stop) { s[i++] = start++; }
        }
    }
    return i;
}

enum truth test_expand(char in[], char expected[]) {
    char intermediate[MAX_SIZE];
    for (int i = 0; i < MAX_SIZE; i++) { intermediate[i] = 0; }

    expand(in, intermediate);
    if (strcmp(intermediate, expected)) {
        printf("Error escaping %s produced %s\n", in, intermediate);
        printf("Expected: %s\n", expected);
        return FALSE;
    }
    return TRUE;
}