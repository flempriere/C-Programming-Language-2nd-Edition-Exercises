/**
 * @file ex2-3.c
 * @author Felix Lempriere
 * @brief Solution to Exercise 2.3 from The C Programming Language, 2nd Edition.
 *
 * Write the function htoi(s), which converts a string of hexadecimal digits
 * including an optional (0x or 0X) into its equivalent integer value.
 * The allowable digits are 0 through 9, a through f, and A through F.
 *
 * @version 0.1
 * @date 2025-04-26
 *
 * @copyright Copyright (c) 2025
 *
 */

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Base for hexadecimal numbers.
 *
 */
#define HEX_BASE 16

/**
 * @brief Value of 'a' and 'A' in hexadecimal.
 *
 */
#define A_IN_HEX 10

/**
 * @brief Converts a string representation of a hexadecimal number to
 * the equivalent integer value. May optionally handle a 0x prefix.
 *
 * @param s string representation with optional 0x or 0X factor.
 * @return int conversion of s.
 */
int htoi(char s[]);

/**
 * @brief Converts a hex digit character to its corresponding integer value.
 *
 * @param c character to convert
 * @return int
 */
int hextoint(int c);

/**
 * @brief Checks if the string has a hexadecimal prefix and returns the number
 * of character digits needed to skip over the prefix.
 *
 * @param s
 * @return 2 if has a prefix, else
 * @return 0
 */
int has_prefix(char s[]);

/**
 * @brief Test driver for htoi function.
 *
 * @return EXIT_SUCCESS
 */
int main(void) {
    // test decimal boundary
    char s[] = "0";
    int hex = htoi(s);
    if (hex) {
        printf("Error: conversion of \"%s\" to 0 failed, result: %d\n", s, hex);
        return EXIT_FAILURE;
    }
    // test with prefix
    char s1[] = "0x0";
    if ((hex = htoi(s1))) {
        printf("Error conversion of \"%s\" to 0 failed, result: %d\n", s1, hex);
        return EXIT_FAILURE;
    }
    // test upper decimal boundary
    char s2[] = "9";
    if ((hex = htoi(s2)) != 9) {
        printf("Error: conversion of \"%s\" to 9 failed, result: %d\n", s2,
               hex);
        return EXIT_FAILURE;
    }
    char s3[] = "0x9";
    if ((hex = htoi(s3)) != 9) {
        printf("Error: conversion of \"%s\" to 9 failed, result: %d\n", s3,
               hex);
        return EXIT_FAILURE;
    }
    // test letter digit lower boundary
    char s4[] = "a";
    if ((hex = htoi(s4)) != 10) {
        printf("Error: conversion of \"%s\" to 10 failed, result: %d\n", s4,
               hex);
        return EXIT_FAILURE;
    }
    // test uppercase version
    char s5[] = "A";
    if ((hex = htoi(s5)) != 10) {
        printf("Error: conversion of \"%s\" to 10 failed, result: %d\n", s5,
               hex);
        return EXIT_FAILURE;
    }
    char s6[] = "0xa";
    if ((hex = htoi(s6)) != 10) {
        printf("Error: conversion of \"%s\" to 10 failed, result: %d\n", s6,
               hex);
        return EXIT_FAILURE;
    }
    // test upper digit boundary
    char s7[] = "f";
    if ((hex = htoi(s7)) != 15) {
        printf("Error: conversion of \"%s\" to 15 failed, result: %d\n", s7,
               hex);
        return EXIT_FAILURE;
    }
    char s8[] = "0xf";
    if ((hex = htoi(s8)) != 15) {
        printf("Error: conversion of \"%s\" to 15 failed, result: %d\n", s8,
               hex);
        return EXIT_FAILURE;
    }
    char s9[] = "0xF";
    if ((hex = htoi(s9)) != 15) {
        printf("Error: conversion of \"%s\" to 15 failed, result: %d\n", s9,
               hex);
        return EXIT_FAILURE;
    }
    // test multidigit string
    char s10[] = "0x1f";
    if ((hex = htoi(s10)) != 31) {
        printf("Error: conversion of \"%s\" to 15 failed, result: %d\n", s10,
               hex);
        return EXIT_FAILURE;
    }
    char s11[] = "0x1f";
    if ((hex = htoi(s11)) != 31) {
        printf("Error: conversion of \"%s\" to 15 failed, result: %d\n", s11,
               hex);
        return EXIT_FAILURE;
    }
    printf("All tests passed successfully\n");
    return EXIT_SUCCESS;
}

int htoi(char s[]) {
    int n = 0;
    for (int i = has_prefix(s); isxdigit(s[i]); i++) {
        n = HEX_BASE * n + hextoint(s[i]);
    }
    return n;
}

int hextoint(int c) {
    if (isdigit(c)) {
        return c - '0';
    } else {
        return (tolower(c) - 'a' + A_IN_HEX);
    }
}

int has_prefix(char s[]) {
    if (s[0] == '0') {
        if (tolower(s[1]) == 'x') { return 2; }
    }
    return 0;
}
