/**
 * @file longest_line_v2.c
 * @author Felix Lempriere
 * @brief Implementation of the longest line example program using extern
 * variables.
 * @version 0.1
 * @date 2025-04-21
 *
 * @copyright Copyright (c) 2025
 *
 */

#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Maximum size of an input line
 *
 */
#define MAXLINE 1000

/**
 * @brief Length of the largest line seen so far.
 *
 */
int max;

/**
 * @brief buffer to store the current line.
 *
 */
char line[MAXLINE];

/**
 * @brief buffer containing the current longest line.
 *
 */
char longest[MAXLINE];

/**
 * @brief Reads in a line from stdin and stores it in the global
 * line buffer
 *
 * @return int number of characters in the string.
 */
int get_line(void);

/**
 * @brief Copies the contents of the line buffer into the
 * longest buffer.
 *
 */
void copy(void);

/**
 * @brief Reads input from stdin and prints the largest
 * line on stdout.
 *
 * @return EXIT_SUCCESS
 */
int main(void) {
    int len;
    extern int max;
    extern char longest[];

    max = 0;
    while ((len = get_line()) > 0) {
        if (len > max) {
            max = len;
            copy();
        }
    }
    if (max > 0) { printf("%s", longest); }
    return EXIT_SUCCESS;
}

int get_line(void) {
    extern char line[];

    int i = 0;
    int c;
    for (; i < MAXLINE - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
        line[i] = c;
    }
    if (c == '\n') {
        line[i] = c;
        ++i;
    }
    line[i] = '\0';
    return i;
}

void copy(void) {
    int i;
    extern char line[];
    extern char longest[];

    i = 0;
    while ((longest[i] = line[i]) != '\0') { ++i; }
}