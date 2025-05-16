/**
 * @file sort_lines_v2.c
 * @author Felix Lempriere
 * @brief Demonstrates the use of function pointers to provide modifiable
 * behaviour to a function through the use of a sorting function that can sort
 * strings numerically or lexigraphically.
 *
 * @version 0.1
 * @date 2025-05-16
 *
 * @copyright Copyright (c) 2025
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Line I/O

/**
 * @brief Maximum number of lines to be sorted.
 *
 */
#define MAXLINES 5000

/**
 * @brief Maximum length of any specific input line
 *
 */
#define MAXLEN 1000

/**
 * @brief Array storing pointers to the input lines.
 *
 */
char* lineptr[MAXLINES];

/**
 * @brief Reads up to maxlines from stdin and store them in the array of strings
 * pointed to by lineptr.
 *
 * @param maxlines maximum number of strings to store in the array.
 * @param lineptr pointer to an array of strings.
 *
 * @return number of lines read, if an error occurs then
 * @return -1.
 */
int read_lines(int maxlines, char* lineptr[]);

/**
 * @brief Writes the string stored in the array pointed to by lineptr to stdout.
 *
 * @param nlines number of lines in the array
 * @param lineptr array of strings.
 */
void write_lines(int nlines, char* lineptr[]);

/**
 * @brief Gets a line from standard input and stores it in line.
 *
 * @param line line to read into
 * @param lim maximum size of input
 * @return length of the input line read, if no line is read then,
 * @return 0.
 */
int get_line(char line[], int lim);

// Memory management

/**
 * @brief Size of the memory buffer
 *
 */
#define ALLOCSIZE (MAXLINES * MAXLEN)

/**
 * @brief Storage for alloc
 *
 */
static char allocbuf[ALLOCSIZE];

/**
 * @brief Next free position in the alloc buffer.
 *
 */
static char* allocp = allocbuf;

/**
 * @brief Allocate memory from the buffer
 *
 * @param n Number of bytes to allocate
 * @return char* pointer to allocated memory.
 */
char* alloc(int n);

// sort functionality

/**
 * @brief Sorts the char* points in lineptr between left and right.
 *
 * @param lineptr array of strings to sort
 * @param left left index to sort from (inclusive)
 * @param right right index to sort to (inclusive)
 * @param comp comparison function to use to determine ordering, comp must
 * satisfy:
 *      - comp(a, b) < 0 if a < b,
 *      - comp(a, b) == 0, if a = b,
 *      - comp(a, b) > 0 if a > b
 */
void my_qsort(void* lineptr[], int left, int right, int (*comp)(void*, void*));

/**
 * @brief Swap the pointers v[i] and v[j] in the array v.
 *
 * @param v array of void pointers
 * @param i index of first pointer to swap
 * @param j index of second pointer to swap
 */
void swap(void* v[], int i, int j);

/**
 * @brief Comparison function that compares two strings numerically
 *
 * @param s1 first string to compare
 * @param s2 second string to compare
 * @return int, after converting s1 and s2 to doubles, returns < 0, if s1 < s2,
 * @return 0, if s1 == s2, else,
 * @return > 0 if s1 > s2.
 *
 * @warning Behaviour is undefined if s1 or s2 cannot be converted to floats
 */
int numcmp(char* s1, char* s2);

int main(int argc, char* argv[]) {
    int numeric = 0;
    if (argc > 1 && strcmp(argv[1], "-n") == 0) { numeric = 1; }

    int nlines = read_lines(MAXLINES, lineptr);
    if (nlines >= 0) {
        my_qsort((void**) lineptr, 0, nlines - 1,
                 (numeric) ? (int (*)(void*, void*)) numcmp :
                             (int (*)(void*, void*)) strcmp);
        write_lines(nlines, lineptr);
        return EXIT_SUCCESS;
    } else {
        printf("input too big to sort\n");
        return EXIT_FAILURE;
    }
}

int read_lines(int maxlines, char* lineptr[]) {
    char* p;
    char line[MAXLEN];

    int nlines = 0;
    for (int len; (len = get_line(line, MAXLEN));) {
        if (nlines >= maxlines || (p = alloc(len + 1)) == NULL) {
            return -1;
        } else {
            if (line[len - 1] == '\n') { line[len - 1] = '\0'; };
            strcpy(p, line);
            lineptr[nlines++] = p;
        }
    }
    return nlines;
}

void write_lines(int nlines, char* lineptr[]) {
    while (nlines-- > 0) { printf("%s\n", *lineptr++); }
}

int get_line(char line[], int lim) {
    int i = 0;
    int c = 0;
    while (--lim > 0 && (c = getchar()) != EOF && c != '\n') { line[i++] = c; }
    if (c == '\n') { line[i++] = c; }
    line[i] = '\0';
    return i;
}

char* alloc(int n) {
    /* Check we have space to fit the request. */
    if (allocbuf + ALLOCSIZE - allocp >= n) {
        allocp += n;
        return allocp - n;
    } else {
        return NULL;
    }
}

void my_qsort(void* lineptr[], int left, int right, int (*comp)(void*, void*)) {
    if (left >= right) { return; }
    swap(lineptr, left, (left + right) / 2);
    int last = left;
    for (int i = left + 1; i <= right; i++) {
        if ((*comp)(lineptr[i], lineptr[left]) < 0) {
            swap(lineptr, ++last, i);
        }
    }
    swap(lineptr, left, last);
    my_qsort(lineptr, left, last - 1, comp);
    my_qsort(lineptr, last + 1, right, comp);
}

void swap(void* v[], int i, int j) {
    void* temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

int numcmp(char* s1, char* s2) {
    double v1 = atof(s1);
    double v2 = atof(s2);
    if (v1 < v2) {
        return -1;
    } else if (v1 > v2) {
        return 1;
    } else {
        return 0;
    }
}