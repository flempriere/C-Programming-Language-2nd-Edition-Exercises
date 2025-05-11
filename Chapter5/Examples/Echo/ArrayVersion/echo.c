/**
 * @file echo.c
 * @author Felix Lempriere
 * @brief Repeats the command-line arguments on stdout.
 *
 * A simple program demonstrating the use of command-line arguments.
 * @version 0.1
 * @date 2025-05-11
 *
 * @copyright Copyright (c) 2025
 *
 */

#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Echo, repeats the command line arguments on stdout
 *
 * @param argc Number of command line arguments
 * @param argv Command line arguments.
 * @return EXIT_SUCCESS
 */
int main(int argc, char* argv[]) {
    for (int i = 1; i < argc; i++) {
        printf("%s%s", argv[i], (i < argc - 1) ? " " : "");
    }
    printf("\n");
    return EXIT_SUCCESS;
}