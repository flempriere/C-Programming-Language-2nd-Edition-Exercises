/**
 * @file find.c
 * @author Felix Lempriere
 * @brief An improved version of the pattern-matching program in Chapter 4 that
 * takes in the pattern to be matched as a command line argument.
 *
 * @version 0.1
 * @date 2025-05-11
 *
 * @copyright Copyright (c) 2025
 *
 */

#include <stdio.h>
#include <string.h>

/**
 * @brief Maximum size of an input line.
 *
 */
#define MAXLINE 1000

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
int get_line(int lim, char* line);

/**
 * @brief Find program. Takes a pattern to match as the first command-line
 * argument, then reads lines from stdin and reports the first match in a line
 * if it exists.
 *
 * @param argc
 * @param argv
 * @return int The number of matched lines.
 */
int main(int argc, char* argv[]) {
    char line[MAXLINE];
    int found = 0;

    if (argc != 2) {
        printf("Usage: find pattern\n");
    } else {
        while (get_line(MAXLINE, line) > 0) {
            if (strstr(line, argv[1]) != NULL) {
                printf("%s", line);
                found++;
            }
        }
    }
    return found;
}

int get_line(int lim, char* line) {
    int i = 0;
    int c = 0;
    while (--lim > 0 && (c = getchar()) != EOF && c != '\n') { line[i++] = c; }
    if (c == '\n') { line[i++] = c; }
    line[i] = '\0';
    return i;
}