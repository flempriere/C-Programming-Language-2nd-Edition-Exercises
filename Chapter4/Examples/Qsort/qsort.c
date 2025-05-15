/**
 * @file qsort.c
 * @author Felix Lempriere
 * @brief Demonstrates recursion through the qsort sorting
 * algorithm.
 *
 * @version 0.1
 * @date 2025-05-07
 *
 * @copyright Copyright (c) 2025
 *
 */

#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Size of an individual test case
 *
 */
#define TEST_SIZE 100000

/**
 * @brief Number of test cases to run
 *
 */
#define N_TESTS 100

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
 * @brief Sorts an array using  qsort.
 *
 * Sorts the array from a[left] to a[right] in ascending order
 *
 * @param a array to sort.
 * @param left left index to sort from.
 * @param right right index to sort to.
 */
void Qsort(int a[], int left, int right);

/**
 * @brief Swaps the elements in the indices i and j in the array a.
 *
 * @param a array
 * @param i array index
 * @param j array index
 */
void swap(int a[], int i, int j);

/**
 * @brief Runs a test of qsort by filling an array a of size len,
 * performing qsort and checking the resulting array is sorted.
 *
 * @param len size of the array
 * @param a array to store and then sort
 * @return TRUE if the array is sorted, else
 * @return FALSE.
 */
enum truth test_qsort(int len, int a[]);

/**
 * @brief Test driver for Shellsort
 *
 * Runs N_TESTS, each consisting of randomly populating an array of size
 * TEST_SIZE, calling shellsort and then checking the output is sorted.
 *
 * @return EXIT_SUCCESS if all tests pass, else
 * @return EXIT_FAILURE
 *
 * @remark uses a fixed seed to ensure consistency across tests.
 *
 * @see N_TESTS, @see TEST_SIZE
 */
int main(void) {
    srand(0);
    int a[TEST_SIZE];
    for (int i = 0; i < N_TESTS; i++) {
        if (!test_qsort(TEST_SIZE, a)) { return EXIT_FAILURE; }
    }
    printf("All tests passed successfully\n");
    return EXIT_SUCCESS;
}

void Qsort(int a[], int left, int right) {
    if (left >= right) { return; }
    swap(a, left, (left + right) / 2);
    int last = left;
    for (int i = left + 1; i <= right; i++) {
        if (a[i] < a[left]) { swap(a, ++last, i); }
    }
    swap(a, left, last);
    Qsort(a, left, last - 1);
    Qsort(a, last + 1, right);
}

enum truth test_qsort(int len, int a[]) {
    for (int i = 0; i < len; i++) { a[i] = rand(); }
    Qsort(a, 0, len - 1);
    if (len < 2) { return TRUE; }
    int prev = a[0];
    for (int i = 1; i < len; i++) {
        if (a[i] < prev) { return FALSE; }
        prev = i;
    }
    return TRUE;
}

void swap(int a[], int i, int j) {
    int tmp = a[i];
    a[i] = a[j];
    a[j] = tmp;
}