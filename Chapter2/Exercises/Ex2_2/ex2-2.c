/**
 * @file ex2-2.c
 * @author Felix Lempriere
 * @brief Solution to Exercise 2.2 from The C Programming Language, 2nd Edition.
 *
 * Give a loop equivalent to the for loop
 * ```
 * for (int i = 0; i < lim - 1 && (c = getchar()) != '\n' && c != EOF)
 * ```
 *
 * without using the logic operators && or ||.
 * @version 0.1
 * @date 2025-04-26
 *
 * @copyright Copyright (c) 2025
 *
 */

#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Maximum length of a line.
 *
 */
#define MAXLINE 10

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
 * @brief Reads a line from stdin into the buffer line.
 *
 * @param line buffer to read the line into.
 *
 * @return int >= 0, number of characters read into the buffer.
 */
int get_line(char line[]);

/**
 * @brief Prints a null-terminated line.
 *
 * @param line null-terminated string.
 */
void print_line(char line[]);

/**
 * @brief Reads a line from stdin and prints it out.
 *
 * @return EXIT_SUCCESS
 */
int main(void) {
    char line[MAXLINE];
    int len = get_line(line);
    if (len > 0) { print_line(line); }
    putchar('\n');
    return EXIT_SUCCESS;
}

int get_line(char line[]) {
    int i = 0;
    enum truth read_flag = TRUE;

    while (read_flag) {
        int c;
        if (i >= MAXLINE - 1) {
            read_flag = FALSE;
        } else if ((c = getchar()) == EOF) {
            read_flag = FALSE;
        } else if (c == '\n') {
            read_flag = FALSE;
        } else {
            line[i] = c;
            i++;
        }
    }
    line[i] = '\0';
    return i;
}

void print_line(char line[]) {
    for (int i = 0; line[i] != '\0'; ++i) { putchar(line[i]); }
}