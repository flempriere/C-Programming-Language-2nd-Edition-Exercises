/**
 * @file binary_search.c
 * @author Felix Lempriere
 * @brief Demonstrates multiway branching through a binary search algorithm.
 * @version 0.1
 * @date 2025-04-27
 *
 * @copyright Copyright (c) 2025
 *
 */

#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Error code for if binary search can't find a match.
 *
 * @see binary_search
 */
#define NOT_FOUND -1

/**
 * @brief Binary search algorithm. Finds the value v in the
 * array a of length len.
 *
 * @param v value to look for.
 * @param len length of the array
 * @param a array to search in.
 *
 * @pre a must be an array sorted in ascending order.
 *
 * @return idx of v in a if found else,
 * @return NOT_FOUND
 *
 * @see NOT_FOUND
 */
int binary_search(int v, int len, int a[]);

// test defines and code

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
 * @brief Length of the test driver array for binary search.
 *
 */
#define LEN 10

/**
 * @brief Tests binary search by comparing binary_search(val, len, a) against
 * an expected outcome expected. Prints error diagnostics if the test fails.
 *
 * @param val value to look for.
 * @param len length of the array
 * @param a array to search in.
 * @param expected expected result of binary_search(val, len, a)
 * @return TRUE if test passes else,
 * @return FALSE
 */
enum truth test_binary_search(int val, int len, int a[], int expected);

/**
 * @brief Test driver for binary search
 *
 * @return EXIT_SUCCESS if all tests passed else,
 * @return EXIT_FAILURE
 */
int main(void) {
    int a[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    int passed = TRUE;
    for (int i = 0; i < LEN && (passed = test_binary_search(i + 1, LEN, a, i));
         i++);

    if (passed && test_binary_search(100, LEN, a, NOT_FOUND)) {
        printf("All tests passed successfully\n");
        return EXIT_SUCCESS;
    } else {
        return EXIT_FAILURE;
    }
}

int binary_search(int v, int len, int a[]) {
    int low = 0;
    int high = len - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (v < a[mid]) {
            high = mid - 1;
        } else if (v > a[mid]) {
            low = mid + 1;
        } else {
            return mid;
        }
    }
    return NOT_FOUND;
}

enum truth test_binary_search(int v, int len, int a[], int expected) {
    int res = binary_search(v, len, a);
    if (res != expected) {
        printf("Error: test failed: value: %d, idx: %d, expected: %d\n", v, res,
               expected);
        return FALSE;
    }
    return TRUE;
}