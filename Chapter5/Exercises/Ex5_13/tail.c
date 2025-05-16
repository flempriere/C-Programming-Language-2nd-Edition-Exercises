/**
 * @file tail.c
 * @author Felix Lempriere
 * @brief Solution to Exercise 5.13 from The C Programming Language, 2nd Edition
 *
 * Write the program tail, which prints the last n lines of its input.
 * By default, n is 10, let us say, but it can be changed by an optional
 * argument, so that
 *      tail -n
 * prints the last n lines. The program should behave rationally no matter
 * how unreasonable the input or the value of n. Write the program so it makes
 * the best use of available storage; lines shoudl be stored as in the sorting
 * program of Section 5.6, not in a two-dimensional array of fixed size.
 * @version 0.1
 * @date 2025-05-16
 *
 * @copyright Copyright (c) 2025
 *
 */

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

// tail parameters
/**
 * @brief Default number of lines to print
 *
 */
#define DEFAULT_LINES 10

/**
 * @brief Maximum number of lines that tail can be called with
 *
 */
#define MAX_LINES 5000

/**
 * @brief Maximum size of any given input line
 *
 */
#define MAX_SIZE 100

// queue variables

/**
 * @brief Queue containing lines
 *
 */
char* line_queue[MAX_LINES + 1];

/**
 * @brief Capacity of the line queue
 *
 */
int queue_capacity = DEFAULT_LINES + 1;

/**
 * @brief Head of the queue
 *
 */
int qh;

/**
 * @brief tail of the queue
 *
 */
int qt;

/**
 * @brief Put the item i on the Queue
 *
 * @param i
 */
void QUEUEput(char* i);

/**
 * @brief Gets an item from the Queue
 *
 * @return char* next item in the Queue returned in a FIFO manner.
 */
char* QUEUEget(void);

/**
 * @brief Checks if the Queue is empty
 *
 * @return non-zero value if the Queue is empty, else
 * @return false
 */
int QUEUEempty(void);

// get line

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

// line buffer

/**
 * @brief amount of memory needed to store all the words
 *
 */
#define ALLOC_SIZE (MAX_SIZE * MAX_LINES)

/**
 * @brief buffer to store the line values
 * 
 */
char buf[ALLOC_SIZE];

int main(int argc, char* argv[]) {
    qh = queue_capacity;    // set default
    if (--argc) {
        switch (**(++argv)) {
        case '-':
            if (isdigit((*argv)[1])) {
                queue_capacity = atoi(*argv + 1);
                if (queue_capacity > MAX_LINES) {
                    queue_capacity = MAX_LINES;
                } else if (!queue_capacity) {
                    return EXIT_SUCCESS;
                }
                queue_capacity++;
                qh = queue_capacity;
            } else {
                goto error;
            }
            break;
        default:
        error:
            printf("Error: call structure: %s -n\n", argv[-1]);
            return EXIT_FAILURE;
        }
    }
    char* bufp = buf;
    while (get_line(MAX_SIZE, bufp)) {
        QUEUEput(bufp);
        bufp = buf + (bufp + MAX_SIZE - buf) %
                         ALLOC_SIZE;    // buffer wraps around if reaches end
    }
    while (!QUEUEempty()) { printf("%s", QUEUEget()); }
    return EXIT_SUCCESS;
}

void QUEUEput(char* i) {
    if (qt + 1 == qh) {
        qh %= queue_capacity;
        qh++;
    }
    line_queue[qt++] = i;
    qt %= queue_capacity;
}

char* QUEUEget(void) {
    qh %= queue_capacity;
    return line_queue[qh++];
}

int QUEUEempty(void) { return ((qh % queue_capacity) == qt); }

int get_line(int maxline, char* line) {
    int c = EOF;
    char* s = line;
    for (; (maxline > 2) && (c = getchar()) != EOF && c != '\n'; --maxline) {
        *line++ = c;
    }
    if (c == EOF) { return 0; }
    *line++ = '\n';
    *line = '\0';
    return line - s;
}