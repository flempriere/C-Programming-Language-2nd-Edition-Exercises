/*
Chapter 2, Exercise 1

Calculates the limits of char, int, floats and doubles by
reference to <limits.h> and <float.h> and integer types by hand.

There is almost definitely an easier way to do this without so much
repeated code, but limiting to book techniques shown.
*/

#include <stdio.h>
#include <limits.h>
#include <float.h>

void calculate_from_limits();
void calculate_by_hand_integers();
void calculate_By_hand_float();

int main() 
{
    calculate_from_limits();
    calculate_by_hand_integers();

}

void calculate_from_limits()
{
    printf("CHAR range: \n");
    printf("char: %d - %d \n", CHAR_MIN, CHAR_MAX);
    printf("signed char: %d - %d \n", SCHAR_MIN, SCHAR_MAX);
    printf("unsigned char: %u - %u\n", 0, UCHAR_MAX);

    printf("\n SHORT range: \n");
    printf("short: %d - %d \n", SHRT_MIN, SHRT_MAX);
    printf("unsigned short: %u - %u\n", 0, USHRT_MAX);

    printf("\n INT range: \n");
    printf("int: %d - %d\n", INT_MIN, INT_MAX);
    printf("unsigned int: %u - %u\n", 0, UINT_MAX);

    printf("\n LONG range: \n");
    printf("long: %ld - %ld\n", LONG_MIN, LONG_MAX);
    printf("unsigned long: %u - %lu\n", 0, ULONG_MAX);

    printf("\n LONG LONG range: \n");
    printf("long long: %lld - %lld\n", LLONG_MIN, LLONG_MAX);
    printf("unsigned long long: %u - %llu\n", 0, ULLONG_MAX);

    printf("\n FLOAT and DOUBLE range: \n");
    printf("smallest float: %e\n", FLT_MIN);
    printf("largest float: %e\n", FLT_MAX);
    printf("smallest double: %e\n", DBL_MIN);
    printf("largest double: %e\n", DBL_MAX);

    return;
}

void calculate_by_hand_integers() {
    printf("Calculating by hand...\n ");

    unsigned char uc, uc_max;
    uc_max = uc = 0;
    --uc_max;

    signed char c, c_max;
    c_max = uc_max / 2;
    c = c_max * (-1) - 1;

    char c_min = 0;
    if (c_min - 1 == -1) {
        printf("char range: %d - %d\n", c, c_max);
    }
    else {
        printf("char range: %d - %d\n", uc, uc_max);
    }
    printf("signed char range: %d - %d\n", c, c_max);
    printf("unsigned char range: %d - %d\n", uc, uc_max);

    unsigned short us, us_max;
    us_max = us = 0;
    --us_max;

    int s, s_max;
    s_max = us_max / 2;
    s = s_max * (-1) - 1;

    printf("short range: %d - %d\n", s, s_max);
    printf("unsigned short range: %u - %u\n", us, us_max);

    unsigned int ui, ui_max;
    ui_max = ui = 0;
    --ui_max;

    int i, i_max;
    i_max = ui_max / 2;
    i = i_max * (-1) - 1;

    printf("int range: %d - %d\n", i, i_max);
    printf("unsigned int range: %u - %u\n", ui, ui_max);

    unsigned long ul, ul_max;
    ul_max = ul = 0;
    --ul_max;

    long l, l_max;
    l_max = ul_max / 2;
    l = l_max * (-1) - 1;

    printf("long range: %ld - %ld\n", l, l_max);
    printf("unsigned long range: %lu - %lu\n", ul, ul_max);

    unsigned long long ull, ull_max;
    ull_max = ull = 0;
    --ull_max;

    long long ll, ll_max;
    ll_max = ull_max / 2;
    ll = ll_max * (-1) - 1;

    printf("long long range: %lld - %lld\n", ll, ll_max);
    printf("unsigned long long range: %llu - %llu\n", ull, ull_max);

    return;
}
