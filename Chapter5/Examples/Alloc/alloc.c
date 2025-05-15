/**
 * @file alloc.c
 * @author Felix Lempriere
 * @brief Implementation of a simple allocator demonstrating pointer address
 * arithmetic.
 * @version 0.1
 * @date 2025-05-09
 *
 * @copyright Copyright (c) 2025
 *
 */

#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Size of the memory buffer.
 *
 */
#define ALLOCSIZE 1000

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

/**
 * @brief free storage pointed to by p
 *
 * @param p
 */
void afree(char* p);

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
 * @brief Tests allocating n bytes then freeing them
 *
 * @param n
 * @return TRUE if n bytes successfully allocated and freed, else
 * @return FALSE
 */
enum truth test_alloc(int n);

int main(void) {
    if (!test_alloc(0)) { return EXIT_FAILURE; }
    if (!test_alloc(1)) { return EXIT_FAILURE; }
    if (!test_alloc(10)) { return EXIT_FAILURE; }
    if (!test_alloc(ALLOCSIZE)) { return EXIT_FAILURE; }
    if (!test_alloc(ALLOCSIZE + 1)) { return EXIT_FAILURE; }
    printf("All tests passed successfully\n");
    return EXIT_SUCCESS;
}

char* alloc(int n) {
    /* Check we have space to fit the request. */
    if (allocbuf + ALLOCSIZE - allocp >= n) {
        allocp += n;
        return allocp - n;
    } else {
        return 0;
    }
}

void afree(char* p) {
    if (p >= allocbuf && p < allocbuf + ALLOCSIZE) { allocp = p; }
}

enum truth test_alloc(int n) {
    char* p = allocp;
    char* res = alloc(n);
    if (n <= ALLOCSIZE) {
        if (res != p) {
            printf("Error: alloc inconsistent\n");
            printf("Result: %p, Expected: %p\n", res, p);
            return FALSE;
        }
        if (p + n != allocp) {
            printf("Error: alloc inconsistent\n");
            printf("Result: %p, Expected: %p\n", allocp, p + n);
            return FALSE;
        }
    } else {
        if (res != 0) {
            printf("Error: alloc inconsistent\n");
            printf("Result: %p, expected: 0\n", res);
            return FALSE;
        }
        return TRUE;
    }
    afree(res);
    if (res != allocp) {
        printf("Error: afree inconsistent\n");
        printf("Result: %p, Expected: %p\n", allocp, res);
        return FALSE;
    }
    return TRUE;
}