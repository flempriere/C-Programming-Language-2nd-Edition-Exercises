/**
 * @file find.c
 * @author Felix Lempriere
 * @brief Extension of find demonstrating the UNIX convention for optional
 * arguments.
 *
 * Find accepts the format find -x -n pattern. Where -x means invert
 * i.e. ignore matching lines and -n means to number the lines.
 *
 * The program should also accept the combined notation -nx or -xn
 * @version 0.1
 * @date 2025-05-11
 *
 * @copyright Copyright (c) 2025
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @brief Maximum size of an input line.
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
int get_line(int lim, char* line);

/**
 * @brief Find program. Takes a pattern to match as the first command-line
 * argument, then reads lines from stdin and reports the first match in a line
 * if it exists.
 *
 * Accepts the following optional arguments
 * 1. -x To print non-matching lines rather than matching.
 * 2. -n To print the line numbers with printed lines.
 *
 * @param argc
 * @param argv
 * @return int The number of matched lines.
 */
int main(int argc, char* argv[]) {
    int except = 0;
    int number = 0;
    int found = 0;
    while (--argc > 0 && (*++argv)[0] == '-') {
        for (int c; (c = *++argv[0]);) {
            switch (c) {
            case 'x':
                except = 1;
                break;
            case 'n':
                number = 1;
                break;
            default:
                printf("Illegal option %c\n", c);
                argc = 0;
                found = -1;
                break;
            }
        }
    }
    if (argc != 1) {
        printf("Usage: find -x -n pattern\n");
    } else {
        char line[MAXLINE];
        long lineno = 0;
        while(get_line(MAXLINE, line)) {
            lineno++;
            if ((strstr(line, *argv) != NULL) != except) {
                if (number) {
                    printf("%ld:", lineno);
                }
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
