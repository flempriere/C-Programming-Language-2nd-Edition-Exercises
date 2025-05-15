/**
 * @file strindex.c
 * @author Felix Lempriere
 * @brief basic pattern matching routine demonstrating the use of functions to
 * break up code.
 *
 * @version 0.1
 * @date 2025-04-30
 *
 * @copyright Copyright (c) 2025
 *
 */

#include <stdio.h>

/**
 * @brief Maximum input line length
 *
 */
#define MAXLINE 1000

/**
 * @brief Gets a line from standard input and stores it in line.
 *
 * @param line line to read into
 * @param lim maximum size of input
 * @return length of the input line read, if no line is read then,
 * @return 0.
 */
int get_line(char line[], int lim);

/**
 * @brief Finds the first occurence of the pattern pat, in the string src.
 *
 * @param src string to search.
 * @param pat pattern to match
 * @return index denoting the start of the first match, else
 * @return -1 if not match is found.
 */
int strindex(char src[], char pat[]);

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
    char line[MAXLINE];
    int found = 0;
    while (get_line(line, MAXLINE) > 0) {
        if (strindex(line, pattern) >= 0) {
            printf("%s", line);
            found++;
        }
    }
    return found;
}

int get_line(char line[], int lim) {
    int i = 0;
    int c = 0;
    while (--lim > 0 && (c = getchar()) != EOF && c != '\n') { line[i++] = c; }
    if (c == '\n') { line[i++] = c; }
    line[i] = '\0';
    return i;
}

int strindex(char src[], char pat[]) {
    for (int i = 0, k; src[i] != '\0'; i++) {
        k = 0;
        for (int j = i; pat[k] != '\0' && src[j] == pat[k]; j++, k++);
        if (k > 0 && pat[k] == '\0') { return i; }
    }
    return -1;
}