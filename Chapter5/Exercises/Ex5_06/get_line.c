/**
 * @file get_line.c
 * @author Felix Lempriere
 * @brief Pointer implementation of getline in partial fulfillment of
 * Exercise 5.6 from The C Programming Language, 2nd Edition.
 *
 * @version 0.1
 * @date 2025-05-10
 *
 * @copyright Copyright (c) 2025
 *
 */

#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Maximum size of an input line.
 *
 */
#define MAXLINE 1000

/**
 * @brief Reads a line from standard input and returns the
 * length of the line read.
 *
 * @param maxline maximum size of an input line.
 * @param s buffer to store the read line in, the indices [0, maxline) must
 * be valid.
 *
 * @return length of the parsed line, 0 is returned if no line is read.
 */
int get_line(int maxline, char* line);

/**
 * @brief Client driver for get_line. Reads line from stdin and echoes them
 * back out on stdout.
 *
 * @return EXIT_SUCCESS on exit.
 */
int main(void) {
    char line[MAXLINE];

    while (get_line(MAXLINE, line)) { printf("%s\n", line); }
    return EXIT_SUCCESS;
}

int get_line(int maxline, char* line) {
    int c = EOF;
    char* s = line;
    for (; (maxline > 1) && (c = getchar()) != EOF && c != '\n'; --maxline) {
        *line++ = c;
    }
    if (maxline > 1 && c == '\n') { *line++ = c; }
    *line = '\0';
    return line - s;
}