/**
 * @file calculator.c
 * @author Felix Lempriere
 * @brief A rudimentary calculator implementation.
 *
 * Reads numbers one number per line printing the cumulative sum.
 * @version 0.1
 * @date 2025-04-30
 *
 * @copyright Copyright (c) 2025
 *
 */

#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Largest line we can read in.
 *
 */
#define MAXLINE 100

/**
 * @brief Reads a line from standard input and returns the
 * length of the line read. This variant strips newlines.
 *
 * @param maxline maximum size of an input line.
 * @param line buffer to store the read line in, the indices [0, maxline) must
 * be valid.
 *
 * @return length of the read input line, 0 is returned if no line is read.
 */
int get_line(int maxline, char line[]);

/**
 * @brief Basic calculator program for the cumulative sum of reals.
 *
 * @return EXIT_SUCESS
 */
int main(void) {
    char line[MAXLINE];
    double sum = 0.0;
    while (get_line(MAXLINE, line)) { printf("\t%g\n", sum += atof(line)); }
    return EXIT_SUCCESS;
}

int get_line(int maxline, char line[]) {
    int i = 0;
    int c = 0;
    while (--maxline > 0 && (c = getchar()) != EOF && c != '\n') {
        line[i++] = c;
    }
    if (c == '\n') { line[i++] = c; }
    line[i] = '\0';
    return i;
}