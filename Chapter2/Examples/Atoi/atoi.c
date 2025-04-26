/**
 * @file atoi.c
 * @author Felix Lempriere
 * @brief Simple implementation of atoi, converting a string to an integer.
 * @version 0.1
 * @date 2025-04-26
 *
 * @copyright Copyright (c) 2025
 *
 */

#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Converts the string s to an integer
 *
 * @param s string to convert.
 * @return int
 */
int my_atoi(char s[]);

int get_line(char s[]);

/**
 * @brief Test driver, calls it will single digit and multidigit numbers.
 *
 * @return EXIT_SUCCESS
 */
int main(void) {
    char s[] = "0";
    int v = my_atoi(s);
    if (v != 0) {
        printf("Error: failed test on converting \"0\"\n");
        return EXIT_FAILURE;
    }

    char s1[] = "5";
    if ((v = my_atoi(s1)) != 5) {
        printf("Error: failed test on converting \"5\"\n");
        return EXIT_FAILURE;
    }

    char s2[] = "9";
    if ((v = my_atoi(s2)) != 9) {
        printf("Error: failed test on converting \"9\"\n");
        return EXIT_FAILURE;
    }

    char s3[] = "12345";
    if ((v = my_atoi(s3)) != 12345) {
        printf("Error: failed test on converting \"12345\"\n");
        return EXIT_FAILURE;
    }
    printf("All tests passed successfully\n");
    return EXIT_SUCCESS;
}

int my_atoi(char s[]) {
    int n = 0;
    for (int i = 0; s[i] >= '0' && s[i] <= '9'; i++) {
        n = 10 * n + (s[i] - '0');
    }
    return n;
}