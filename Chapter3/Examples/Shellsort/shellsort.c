/**
 * @file shellsort.c
 * @author Felix Lempriere
 * @brief Demonstrates nested loop control, through the shellsort sorting
 * algorithm.
 *
 * @version 0.1
 * @date 2025-04-28
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
 * @brief Sorts an array using Shellsort.
 *
 * Sorts an array a of length len using Shellsort. After shellsort the array a
 * is in ascending order.
 *
 * @param len size of the array
 * @param a array to sort.
 */
void shellsort(int len, int a[]);

/**
 * @brief Runs a test of shellsort by filling an array a of size len,
 * performing shellsort and checking the resulting array is sorted.
 *
 * @param len size of the array
 * @param a array to store and then sort
 * @return TRUE if the array is sorted, else
 * @return FALSE.
 */
enum truth test_shellsort(int len, int a[]);

/**
 * @brief Test driver for Shellsort
 *
 * Runs N_TESTS, each consisting of randomly populating an array of size
 * TEST_SIZE, calling shellsort and then checking the output is sorted.
 *
 * @return EXIT_SUCCESS if all tests pass, else
 * @return EXIT_FAILURE
 *
 * @remark For consistency in testing we use a fixed seed, but this can
 * be changed if needed.
 *
 * @see N_TESTS, @see TEST_SIZE
 */
int main(void) {
    srand(0);
    int a[TEST_SIZE];
    for (int i = 0; i < N_TESTS; i++) {
        if (!test_shellsort(TEST_SIZE, a)) { return EXIT_FAILURE; }
    }
    printf("All tests passed successfully\n");
    return EXIT_SUCCESS;
}

void shellsort(int len, int a[]) {
    for (int gap = len / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < len; i++) {
            for (int j = i - gap; j >= 0 && (a[j] > a[j + gap]); j -= gap) {
                int temp = a[j];
                a[j] = a[j + gap];
                a[j + gap] = temp;
            }
        }
    }
}

enum truth test_shellsort(int len, int a[]) {
    for (int i = 0; i < len; i++) { a[i] = rand(); }
    shellsort(len, a);
    if (len < 2) { return TRUE; }
    int prev = a[0];
    for (int i = 1; i < len; i++) {
        if (a[i] < prev) { return FALSE; }
        prev = i;
    }
    return TRUE;
}