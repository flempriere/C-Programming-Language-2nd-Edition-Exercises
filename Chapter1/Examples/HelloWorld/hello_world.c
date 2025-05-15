/**
 * @file hello_world.c
 * @author Felix Lempriere
 * @brief The first C Program.
 *
 * @remark The version as provided in the book uses the signature
 * main() which is deprecated. It used to mean a function implicitly
 * returning an int and taking an unknown number of arguments.
 *
 * @remark Additionally the program omits a return 0, which until C99
 * was required, since then stdlib.h provides EXIT_SUCCESS to give a portable
 * return value.
 *
 * @version 0.1
 * @date 2025-04-20
 *
 * @copyright Copyright (c) 2025
 *
 */

#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Prints "hello, world" on stdout.
 *
 * @return EXIT_SUCCESS.
 */
int main(void) {
    printf("hello, world\n");
    return EXIT_SUCCESS;
}