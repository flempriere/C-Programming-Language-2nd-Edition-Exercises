#include "ex5-9.h"
#include <stddef.h>
#include <stdio.h>

int main(void)
{
    printf("Testing day_of_year\n");
    
    printf("Test 1: valid input: 1st of Jan, 1900, expected output: 1\n");
    printf("Output: %d\n", day_of_year(1900, 1, 1));

    printf("Test 2: invalid input: 1st of Jan, -1, expected output: -1\n");
    printf("Output: %d\n", day_of_year(-1, 1, 1));
    
    printf("Test 3: valid input: 1st of March, 2001, expected output: 60\n");
    printf("Output: %d\n", day_of_year(2001, 3, 1));

    printf("Test 4: valid input: 1st of March, 2004, expected output: 61\n");
    printf("Output: %d\n", day_of_year(2004, 3, 1));

    printf("Test 5: valid input: 1st of March, 1900, expected output: 60\n");
    printf("Output: %d\n", day_of_year(1900, 3, 1));

    printf("Test 6: valid input: 1st of March, 2000, expected output: 61\n");
    printf("Output: %d\n", day_of_year(2000, 3, 1));

    printf("Test 7: valid input: 29th of February, 2000, expected output: 60\n");
    printf("Output: %d\n", day_of_year(2000, 2, 29));

    printf("Test 8: invalid input: 29th of February, 1999, expected output: -1\n");
    printf("Output: %d\n", day_of_year(1999, 2, 29));

    printf("Test 9: invalid input: 31 of month 0, 1999, expected output: -1\n");
    printf("Output: %d\n", day_of_year(1999, 0, 31));

    printf("Test 10: invalid input: 30 of month 13, 1999, expected output: -1\n");
    printf("Output: %d\n", day_of_year(1999, 13, 30));


    printf("Testing month_day\n");
    int month, day;


    printf("Test 1: valid input: 1999, 60, expected output: m: 3, d: 1\n");
    month_day(1999, 60, &month, &day);
    printf("m: %d, d: %d\n", month, day);

    printf("Test 2: valid input: 2000, 60, expected output: m : 2, d: 29\n");
    month_day(2000, 60, &month, &day);
    printf("m: %d, d: %d\n", month, day);

    printf("Test 3: invalid input: -1, 60\n");
    month_day(-1, 60, &month, &day);
    printf("m: %d, d: %d\n", month, day);

    printf("Test 4: invalid input: 1, 366\n");
    month_day(1, 366, &month, &day);
    printf("m: %d, d: %d\n", month, day);

    printf("Test 5: valid input: 1, 365\n");
    month_day(1, 365, &month, &day);
    printf("m: %d, d: %d\n", month, day);

    printf("Test 6: valid input: 0, 366\n");
    month_day(0, 366, &month, &day);
    printf("m: %d, d: %d\n", month, day);

    printf("Tests completed\n");
    return 0;
}