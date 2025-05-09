/**
 * @file ex3-1.c
 * @author Felix Lempriere
 * @brief Solution to Exercise 3.1 from The C Programming Language, 2nd Edition
 *
 * Our binary search makes two tests inside the loop, when only one would
 * suffice (at the price of more tests outside). Write a version with only one
 * test inside the loop and measure the difference in runtime.
 *
 * @remark  Unfortunately we observe that performing this benchmarking requires
 * the use of the `<time.h>` header which we have not formally been
 * introduced to yet.
 * @version 0.1
 * @date 2025-04-27
 *
 * @copyright Copyright (c) 2025
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * @brief Size of the test array
 *
 */
#define TEST_SIZE 10000000

/**
 * @brief initialises a test array of length len. The arrays
 * have the value a[i] = i;
 *
 * @param len length of the array
 * @param a array to fill.
 */
void init_test_array(int len, int a[]);

/**
 * @brief Calculates the average run time
 *
 * @param start clock_t clocks at start of the stest
 * @param stop clock_t clocks at the end of the test
 * @param N_TESTS total number of tests run
 * @return double average time spent on each test.
 */
double calculate_avg_time(clock_t start, clock_t stop, int N_TESTS);

/**
 * @brief Error code for if binary search can't find a match.
 *
 */
#define NOT_FOUND -1

/**
 * @brief Original K&R Binary search algorithm. Finds the value v in the
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
int KandRbin_search(int v, int len, int a[]);

/**
 * @brief New Binary search algorithm. Finds the value v in the
 * array a of length len.
 *
 * @note This version is modified to only use one test inside the main while
 * loop.
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

/**
 * @brief Test array to sort
 * 
 */
int a[TEST_SIZE];

/**
 * @brief Stores the time differences between the two techniques
 * 
 */
int results[TEST_SIZE + 1];

/**
 * @brief Performs a performance comparison of the two binary search
 * implementations.
 *
 * @return EXIT_SUCCESS if no discrepency found between the two methods, else
 * @return EXIT_FAILURE
 */
int main(void) {
    init_test_array(TEST_SIZE, a);

    // time our first implementation.
    clock_t tic = clock();
    for (int i = 0; i <= TEST_SIZE; i++) {
        results[i] = binary_search(i, TEST_SIZE, a);
    }
    clock_t toc = clock();
    double new_avg_time = calculate_avg_time(tic, toc, TEST_SIZE + 1);

    tic = clock();
    for (int i = 0; i <= TEST_SIZE; i++) {
        results[i] -= KandRbin_search(i, TEST_SIZE, a);
    }
    toc = clock();
    double kandr_avg_time = calculate_avg_time(tic, toc, TEST_SIZE + 1);

    printf("====Average Search times for N = %d ====\n", TEST_SIZE);
    printf("K&R version: %e\n", kandr_avg_time);
    printf("New version: %e\n", new_avg_time);

    for (int i = 0; i <= TEST_SIZE; i++) {
        if (results[i]) {
            printf("Error: new and old techniques disagreed on idx for %d\n",
                   i);
            return EXIT_FAILURE;
        }
    }
    printf("Confirmed both approaches answers match\n");
    return EXIT_SUCCESS;
}

void init_test_array(int len, int a[]) {
    for (int i = 0; i < len; i++) { a[i] = i; }
}

double calculate_avg_time(clock_t start, clock_t stop, int n_tests) {
    return (((double) stop - start) / CLOCKS_PER_SEC) / n_tests;
}

int KandRbin_search(int v, int len, int a[]) {
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

int binary_search(int v, int len, int a[]) {
    int low = 0;
    int high = len - 1;
    int mid = (low + high) / 2;
    while ((low <= high) && (a[mid] != v)) {
        if (v < a[mid]) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
        mid = (low + high) / 2;
    }
    return (a[mid] == v) ? mid : NOT_FOUND;
}