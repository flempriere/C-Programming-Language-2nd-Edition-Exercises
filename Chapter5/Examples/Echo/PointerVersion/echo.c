/**
 * @file echo.c
 * @author Felix Lempriere
 * @brief Reimplementation of echo utilising pointer notation.
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
    while (--argc > 0) { printf("%s%s", *++argv, (argc > 1) ? " " : ""); }
    printf("\n");
    return EXIT_SUCCESS;
}