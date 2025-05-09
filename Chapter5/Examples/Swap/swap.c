/**
 * @file swap.c
 * @author Felix Lempriere
 * @brief Basic swap routine demonstrating the use of function arguments.
 * @version 0.1
 * @date 2025-05-09
 *
 * @copyright Copyright (c) 2025
 *
 */

#include <stdio.h>
#include <stdlib.h>

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
 * @brief Test driver for swap.
 *
 * Takes in two values to swap x and y,
 * creates pointers to them, swaps these and checks they match. Reporting a
 * error diagnostic if they don't agree.
 *
 * @param x
 * @param y
 * @return TRUE is test passes, else FALSE.
 */
enum truth test_swap(int x, int y);
/**
 * @brief Swaps the value of the integers pointed
 * to by px and py.
 *
 * @param px
 * @param py
 */
void swap(int* px, int* py);

/**
 * @brief Test driver for swap.
 *
 * @return EXIT_SUCCESS if all tests passed, else
 * @return EXIT_FAILURE.
 */
int main(void) {
    if (!test_swap(0, 0)) { return EXIT_FAILURE; }
    if (!test_swap(1, 0)) { return EXIT_FAILURE; }
    if (!test_swap(0, 1)) { return EXIT_FAILURE; }
    printf("All tests passed successfully\n");
    return EXIT_SUCCESS;
}

void swap(int* px, int* py) {
    int t = *px;
    *px = *py;
    *py = t;
}

enum truth test_swap(int x, int y) {
    int xt = x;
    int yt = y;
    int* pxt = &xt;
    int* pyt = &yt;
    swap(pxt, pyt);
    if ((yt != x) || (xt != y)) {
        printf("Error while performing swap\n");
        printf("Expected: x = %d, y = %d\n", y, x);
        printf("Result: x = %d, y = %d\n", xt, yt);
        return FALSE;
    }
    return TRUE;
}