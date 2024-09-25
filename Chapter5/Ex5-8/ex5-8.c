#include "ex5-8.h"
#include "stddef.h"

#define IS_LEAP(x) (((x) % 4 == 0 && (x) % 100 != 0) || (x) % 400 == 0)

#define SET_MONTH_DAY_ERROR(x,y) do {\
    *x = -1;                         \
    *y = -1;                         \
    return;                          \
} while(0)

char daytab[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

/* day_of_year : set day of year from month & day
returns -1 on invalid month and day or year < 0 */
int day_of_year(int year, int month, int day)
{
    int leap;
    if (year < 0) return -1;
    if (month < 1 || month > 12) return -1;
    leap = IS_LEAP(year);
    if (day > daytab[leap][month] || day < 1) return -1;
    while(month) day += daytab[leap][--month];
    return day;    
}

/* converts the (yearday)-th day of the (year) to a (*pmonth), (*pday) repr
*pmonth, and *pday set to -1 on invalid input
*/
void month_day(int year, int yearday, int *pmonth, int *pday)
{
    int i, leap;
    if (yearday < 1 || year < 0) SET_MONTH_DAY_ERROR(pmonth, pday);
    leap = IS_LEAP(year);
    if (yearday > DAYS_IN_YEAR + leap) SET_MONTH_DAY_ERROR(pmonth, pday);
    for (i = 1; yearday > daytab[leap][i]; i++) yearday -= daytab[leap][i];
    *pmonth = i;
    *pday = yearday;
}


