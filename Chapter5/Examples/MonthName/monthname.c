/**
 * @file monthname.c
 * @author Felix Lempriere
 * @brief Demonstrates the use of an array of pointers to convert numerical
 * representations of months to their string representation.
 * @version 0.1
 * @date 2025-05-11
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Enumeration for the months.
 *
 */
enum month {
    NONE,
    JAN,
    FEB,
    MAR,
    APR,
    MAY,
    JUN,
    JUL,
    AUG,
    SEP,
    OCT,
    NOV,
    DEC
};

/**
 * @brief Returns a string representation of the given month m.
 * 
 * @param m month of the year
 * @return char* string representation of the month m.
 */
char* month_name(enum month m);

/**
 * @brief Demonstration driver of the month_name function.
 * 
 * @return EXIT_SUCCESS
 */
int main(void) {
    for (enum month i = NONE; i <= DEC + 1; i++) {
        printf("m: %d\t%s\n", i, month_name(i));
    }
    return EXIT_SUCCESS;
}

char* month_name(enum month m) {
    static char* name[] = {
        "Illegal Month", "January", "February", "March",
        "April", "May", "June", "July", "August",
        "September", "October", "November", "December"
    };
    return (m < JAN || m  > DEC) ? name[0] : name[m];
}