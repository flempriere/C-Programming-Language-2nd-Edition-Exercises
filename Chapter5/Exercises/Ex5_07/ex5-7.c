/**
 * @file ex5-7.c
 * @author Felix Lempriere
 * @brief Solution to Exercise 5.7 from The C Programming Language, 2nd Edition
 *
 * Rewrite readlines to store lines in an array supplied by main, rather than
 * calling `alloc` to maintain storage. How much faster is the program?
 *
 * @version 0.1
 * @date 2025-05-10
 *
 * @copyright Copyright (c) 2025
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @brief Maximum number of lines to be sorted.
 *
 */
#define MAXLINES 500000

/**
 * @brief Maximum length of any specific input line
 *
 */
#define MAXLEN 1000

/**
 * @brief Size of the memory buffer.
 *
 */
#define ALLOCSIZE 500000000

/**
 * @brief Array storing pointers to the input lines.
 *
 */
char* lineptr[MAXLINES];

/**
 * @brief Buffer storing the strings to sort
 * 
 */
char buffer[ALLOCSIZE];

/**
 * @brief Reads up to maxline lines from stdin, and stores the pointers to them
 * in the array lineptr. The character array buffer is used to store the
 * underlying strings.
 *
 * @param maxlines maximum number of strings to store in the array.
 * @param lineptr pointer to an array of strings.
 * @param buffer buffer to store the strings in.
 * @param bufsize size of the buffer
 *
 * @return number of lines read, if an error ours then
 * @return -1.
 */
int read_lines(int maxlines, char* lineptr[], char buffer[], int bufsize);

/**
 * @brief Writes the string stored in the array pointed to by lineptr to stdout.
 *
 * @param nlines number of lines in the array
 * @param lineptr array of strings.
 */
void write_lines(int nlines, char* lineptr[]);

/**
 * @brief Sorts the char* points in lineptr between left and right.
 *
 * @param lineptr array of strings to sort
 * @param left left index to sort from (inclusive)
 * @param right right index to sort to (inclusive)
 */
void my_qsort(char* lineptr[], int left, int right);

/**
 * @brief Swap the pointers v[i] and v[j] in the array v.
 *
 * @param v array of character pointers
 * @param i index of first pointer to swap
 * @param j index of second pointer to swap
 */
void swap(char* v[], int i, int j);

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
 * @brief Sorts input lines.
 *
 * Reads input lines from stdin until an EOF is reached, then outputs the lines
 * in sorted order.
 *
 * @return EXIT_SUCCESS if line successfully read and sorted, else
 * @return EXIT_FAILURE.
 */
int main(void) {
    int nlines = read_lines(MAXLINES, lineptr, buffer, ALLOCSIZE);
    if (nlines >= 0) {
        my_qsort(lineptr, 0, nlines - 1);
        write_lines(nlines, lineptr);
        return EXIT_SUCCESS;
    } else {
        return EXIT_FAILURE;
    }
}

int read_lines(int maxlines, char* lineptr[], char buffer[], int bufsize) {
    char line[MAXLEN];
    char* buf_start = buffer;

    int nlines = 0;
    for (int len; (len = get_line(line, MAXLEN));) {
        if (nlines >= maxlines || (len + 1) > (buffer + bufsize - buf_start)) {
            return -1;
        } else {
            if (line[len - 1] == '\n') { line[len - 1] = '\0'; };
            strcpy(buffer, line);
            lineptr[nlines++] = buffer;
            buffer += len + 1;
        }
    }
    return nlines;
}

void write_lines(int nlines, char* lineptr[]) {
    while (nlines-- > 0) { printf("%s\n", *lineptr++); }
}

void my_qsort(char* lineptr[], int left, int right) {
    if (left >= right) { return; }
    swap(lineptr, left, (left + right) / 2);
    int last = left;
    for (int i = left + 1; i <= right; i++) {
        if (strcmp(lineptr[i], lineptr[left]) < 0) { swap(lineptr, ++last, i); }
    }
    swap(lineptr, left, last);
    my_qsort(lineptr, left, last - 1);
    my_qsort(lineptr, last + 1, right);
}

void swap(char* v[], int i, int j) {
    char* tmp = v[i];
    v[i] = v[j];
    v[j] = tmp;
}

int get_line(char line[], int lim) {
    int i = 0;
    int c = 0;
    while (--lim > 0 && (c = getchar()) != EOF && c != '\n') { line[i++] = c; }
    if (c == '\n') { line[i++] = c; }
    line[i] = '\0';
    return i;
}