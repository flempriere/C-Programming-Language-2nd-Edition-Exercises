/**
 * @file ex5-16.c
 * @author Felix Lempriere
 * @brief Solution to Exercise 5.16 from The C Programming Language, 2nd
 * Edition.
 *
 * Add the -d ("directory order") option, which makes comparisons only on
 * letters, numbers and blanks. Make sure it works in conjunction with -f
 * and -r.
 *
 * @version 0.1
 * @date 2025-05-16
 *
 * @copyright Copyright (c) 2025
 *
 */

#include <ctype.h>
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
 * @brief Enum containing options, options set to powers of two
 * to allow bit-packing.
 *
 */
enum option_flags {
    NONE = 0,
    NUMERIC = 1,
    REVERSE = 2,
    FOLD = 4,
    DIR = 8
};

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

// comparison functions

/**
 * @brief Makes the cast to a comparison function a bit more readable.
 *
 * @param f comparison function to cast
 */
#define CAST_COMPARISON_FUNCTION(f) ((int (*)(void*, void*))(f))

/**
 * @brief Comparison function that compares two strings lexigraphically,
 * with upper case and lower case characters considered equal.
 *
 * @param s1 first string to compare
 * @param s2 second string to compare
 * @return int, after converting s1 and s2 to all lower case,
 * @return < 0, if s1 < s2,
 * @return 0, if s1 == s2, else,
 * @return > 0 if s1 > s2.
 */
int foldcmp(char* s1, char* s2);

/**
 * @brief Comparison function that compares two strings in directory order,
 * which is lexigraphical but only considering letters, numbers and blanks.
 *
 * @param s1 first string to compare
 * @param s2 second string to compare
 * @return int, after converting s1 and s2 to directory form,
 * @return < 0, if s1 < s2,
 * @return 0, if s1 == s2, else,
 * @return > 0 if s1 > s2.
 */
int dircmp(char* s1, char* s2);

/**
 * @brief Comparison function that compares two strings in folded directory
 * order, which is lexigraphical but only considering letters, numbers
 * and blanks with all upper case characters considered equal to their lower
 * case counterpart.
 *
 * @param s1 first string to compare
 * @param s2 second string to compare
 * @return int, after converting s1 and s2 to directory form,
 * @return < 0, if s1 < s2,
 * @return 0, if s1 == s2, else,
 * @return > 0 if s1 > s2.
 */
int folddircmp(char* s1, char* s2);

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

/**
 * @brief Takes in an options string and returns the appropriate comparison
 * function.
 *
 * @param options options flag enum containing the appropriately set flags
 *
 * @return int(*)(void*, void*) comparison flag
 */
int (*select_comparator(enum option_flags options))(void*, void*);
// enum

/**
 * @brief global variable used to reverse the direction of a sort.
 *
 */
int order = 1;

int main(int argc, char* argv[]) {
    unsigned options = 0; /* flag containing options */
    while (--argc > 0 && (*++argv)[0] == '-') {
        for (char c = *++argv[0]; c; c = *++argv[0]) {
            switch (c) {
            case 'n':
                options |= NUMERIC;
                break;
            case 'r':
                options |= REVERSE;
                order = -1;
                break;
            case 'f':
                options |= FOLD;
                break;
            case 'd':
                options |= DIR;
                break;
            default:
                printf("sort: illegal option %c\n", c);
                return EXIT_FAILURE;
            }
        }
    }

    int nlines = read_lines(MAXLINES, lineptr);
    if (nlines >= 0) {
        my_qsort((void**) lineptr, 0, nlines - 1, select_comparator(options));
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
        if (order * (*comp)(lineptr[i], lineptr[left]) < 0) {
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

int foldcmp(char* s1, char* s2) {
    for (; tolower(*s1) == tolower(*s2); s1++, s2++) {
        if (*s1 == '\0') { return 0; }
    }
    return tolower(*s1) - tolower(*s2);
}

int dircmp(char* s1, char* s2) {
    do {
        for (; !isalnum(*s1) && !isblank(*s1) && *s1 != '\0'; s1++);
        for (; !isalnum(*s2) && !isblank(*s2) && *s2 != '\0'; s2++);
        if (*s1 == *s2 && *s1 == '\0') { return 0; }
    } while (*s1++ == *s2++);
    return *--s1 - *--s2;
}

int folddircmp(char* s1, char* s2) {
    char c;
    char d;
    do {
        for (; !isalnum(*s1) && !isblank(*s1) && *s1 != '\0'; s1++);
        for (; !isalnum(*s2) && !isblank(*s2) && *s2 != '\0'; s2++);
        c = tolower(*s1++);
        d = tolower(*s2++);
        if (c == d && c == '\0') { return 0; }
    } while (c == d);
    return c - d;
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

int (*select_comparator(enum option_flags options))(void*, void*) {
    if (options & NUMERIC) {
        return CAST_COMPARISON_FUNCTION(numcmp);
    } else if ((options & FOLD) && (options & DIR)) {
        return CAST_COMPARISON_FUNCTION(folddircmp);
    } else if (options & FOLD) {
        return CAST_COMPARISON_FUNCTION(foldcmp);
    } else if (options & DIR) {
        return CAST_COMPARISON_FUNCTION(dircmp);
    } else {
        return CAST_COMPARISON_FUNCTION(strcmp);
    }
}