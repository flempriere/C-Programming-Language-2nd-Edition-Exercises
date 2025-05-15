/**
 * @file ex2-1.c
 * @author Felix Lempriere
 * @brief Solution to Exercise 2.1 from The C Programming Language, 2nd Edition.
 *
 * Write a program to determine the ranges of char, short, int, and long
 * variables, both signed and unsigned, by printing appropriate values from
 * standard headers and by direct computation. Harder if you compute them:
 * determine the ranges of the various floating-point types.
 *
 *
 * @note: As of C23 Signed Integer Representation is defined to be Two's
 * complement representaiton. We use this fact to calculate the result. Older
 * standards allowed for One's complement and sign and magnitude in which case
 * the minimum is one greater, (since 0 has two representations.)
 *
 * @note: Most floating point representations are IEE754
 * @version 0.1
 * @date 2025-04-24
 *
 * @copyright Copyright (c) 2025
 *
 */

#include <float.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Calculates the ranges of the integer and floating point types
 * by reference to limits.h and float.h.
 *
 */
void calculate_from_limits(void);

/**
 * @brief Calculates the ranges of the integer types by hand.
 *
 * @remark Assumes the signed type representation is two's complement.
 *
 */
void calculate_by_hand_integers(void);

/**
 * @brief Calculates the ranges of the floating point types by hand.
 *
 */
void calculate_by_hand_floats(void);

/**
 * @brief Determines the limits of the C numerical types by reference to the
 * supplied headers and through direct calculation.
 *
 * @return EXIT_SUCCESS
 */
int main(void) {
    calculate_from_limits();
    calculate_by_hand_integers();
    calculate_by_hand_floats();

    return EXIT_SUCCESS;
}

void calculate_from_limits(void) {
    printf("CHAR range: \n");
    printf("char: %d - %d \n", CHAR_MIN, CHAR_MAX);
    printf("signed char: %d - %d \n", SCHAR_MIN, SCHAR_MAX);
    printf("unsigned char: %u - %u\n", 0, UCHAR_MAX);

    printf("\nSHORT range: \n");
    printf("short: %d - %d \n", SHRT_MIN, SHRT_MAX);
    printf("unsigned short: %u - %u\n", 0, USHRT_MAX);

    printf("\nINT range: \n");
    printf("int: %d - %d\n", INT_MIN, INT_MAX);
    printf("unsigned int: %u - %u\n", 0, UINT_MAX);

    printf("\nLONG range: \n");
    printf("long: %ld - %ld\n", LONG_MIN, LONG_MAX);
    printf("unsigned long: %u - %lu\n", 0, ULONG_MAX);

    printf("\nLONG LONG range: \n");
    printf("long long: %lld - %lld\n", LLONG_MIN, LLONG_MAX);
    printf("unsigned long long: %u - %llu\n", 0, ULLONG_MAX);

    printf("\nFloating point limits: \n");
    printf("smallest float: %e\n", FLT_MIN);
    printf("largest float: %e\n", FLT_MAX);
    printf("smallest double: %e\n", DBL_MIN);
    printf("largest double: %e\n", DBL_MAX);
    printf("smallest long double: %Le\n", LDBL_MIN);
    printf("largest long double: %Le\n", LDBL_MAX);

    return;
}

void calculate_by_hand_integers(void) {
    printf("\nCalculating integer ranges by hand...\n");

    unsigned char uc_max = -1;    // modulo of unsigned arithmetic
    signed char sc_max = uc_max / 2;
    signed char sc_min = -sc_max - 1;

    printf("\nCHAR ranges:\n");
    char c = -1;    // wraps around if char unsigned.
    if (c == -1) {
        printf("char range: %d - %d\n", sc_min, sc_max);
    } else {
        printf("char range: %d - %d\n", 0, uc_max);
    }
    printf("signed char range: %d - %d\n", sc_min, sc_max);
    printf("unsigned char range: 0 - %u\n", uc_max);

    unsigned short us_max = -1;
    short s_max = us_max / 2;
    short s_min = -s_max - 1;

    printf("\nSHORT ranges:\n");
    printf("short range: %d - %d\n", s_min, s_max);
    printf("unsigned short range: 0 - %d\n", s_max);

    unsigned int ui_max = -1;
    int i_max = ui_max / 2;
    int i_min = -i_max - 1;

    printf("\nINT ranges:\n");
    printf("int range: %d - %d\n", i_min, i_max);
    printf("unsigned int range: 0 - %u\n", ui_max);

    unsigned long ul_max = -1;
    long l_max = ul_max / 2;
    long l_min = -l_max - 1;

    printf("\nLONG ranges:\n");
    printf("long range: %ld - %ld\n", l_min, l_max);
    printf("unsinged long range: 0 - %lu\n", ul_max);

    unsigned long long ull_max = -1;
    long long ll_max = ull_max / 2;
    long long ll_min = -ll_max - 1;

    printf("\nLONG LONG ranges: \n");
    printf("long long range: %lld - %lld\n", ll_min, ll_max);
    printf("unsigned long long: 0 to %llu\n", ull_max);

    return;
}

void calculate_by_hand_floats(void) {
    printf("\nCalculating by hand for floats...\n");

    float flt_a = 2.0;
    float flt_b = 1.0;

    float flt_m = flt_b;
    // calculate size of the signficand
    while (flt_a != flt_b) {
        flt_m = flt_b;
        flt_b = flt_b * 2.0;
        flt_a = flt_b + 1.0;
    }
    flt_m = flt_m + (flt_m - 1.0);

    // determine the maixmum we can raise this too.
    flt_a = flt_m;
    flt_b = flt_m;
    while (flt_b == flt_m) {
        flt_m = flt_a;
        flt_a = flt_a * 2.0;
        flt_b = flt_a / 2.0;
    }
    printf("largest float: %e\n", flt_m);
    // determine the minimum
    flt_a = 1.0;
    flt_b = flt_a;
    flt_m = flt_a;
    while (flt_b == flt_m) {
        flt_m = flt_a;
        flt_a = flt_a / 2.0;
        flt_b = flt_a * 2.0;
    }
    printf("smallest float: %e\n", flt_m);

    double dbl_a = 2.0;
    double dbl_b = 1.0;

    double dbl_m = dbl_b;
    // calculate size of the signficand
    while (dbl_a != dbl_b) {
        dbl_m = dbl_b;
        dbl_b = dbl_b * 2.0;
        dbl_a = dbl_b + 1.0;
    }
    dbl_m = dbl_m + (dbl_m - 1.0);

    // determine the maixmum we can raise this too.
    dbl_a = dbl_m;
    dbl_b = dbl_m;
    while (dbl_b == dbl_m) {
        dbl_m = dbl_a;
        dbl_a = dbl_a * 2.0;
        dbl_b = dbl_a / 2.0;
    }
    printf("largest long double: %e\n", dbl_m);
    // determine the minimum
    dbl_a = 1.0;
    dbl_b = dbl_a;
    dbl_m = dbl_a;
    while (dbl_b == dbl_m) {
        dbl_m = dbl_a;
        dbl_a = dbl_a / 2.0;
        dbl_b = dbl_a * 2.0;
    }
    printf("smallest long double: %e\n", dbl_m);

    long double ldbl_a = 2.0;
    long double ldbl_b = 1.0;

    long double ldbl_m = ldbl_b;
    // calculate size of the signficand
    while (ldbl_a != ldbl_b) {
        ldbl_m = ldbl_b;
        ldbl_b = ldbl_b * 2.0;
        ldbl_a = ldbl_b + 1.0;
    }
    ldbl_m = ldbl_m + (ldbl_m - 1.0);

    // determine the maixmum we can raise this too.
    ldbl_a = ldbl_m;
    ldbl_b = ldbl_m;
    while (ldbl_b == ldbl_m) {
        ldbl_m = ldbl_a;
        ldbl_a = ldbl_a * 2.0;
        ldbl_b = ldbl_a / 2.0;
    }
    printf("largest double: %Le\n", ldbl_m);
    // determine the minimum
    ldbl_a = 1.0;
    ldbl_b = ldbl_a;
    ldbl_m = ldbl_a;
    while (ldbl_b == ldbl_m) {
        ldbl_m = ldbl_a;
        ldbl_a = ldbl_a / 2.0;
        ldbl_b = ldbl_a * 2.0;
    }
    printf("smallest double: %Le\n", ldbl_m);
}