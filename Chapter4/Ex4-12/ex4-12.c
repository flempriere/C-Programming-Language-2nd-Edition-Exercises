
#include "itoa.h"

int itoaInnerRecursion(char s[], int v, int i, int lim);

int itoa(char s[], int v, int lim)
/*
itoa: converts integer to string

Checks the sign, then calls a recursive loop

returns the length of the string
*/
{
    int i = 0;
    if (v < 0) {s[i++] = '-'; v = -v;} 

    return itoaInnerRecursion(s, v, i, lim);

}

int itoaInnerRecursion(char s[], int v, int i, int lim)
/*
Recursive loop -> goes until all digits computed, on the
return check if still room in the string, if so, we put
the digit in the string, and null-terminate.

return i: next free index in the string
*/
{
    if (v / 10) {
        i = itoaInnerRecursion(s, v / 10, i, lim);
    }
    if (i < lim - 1) {
        s[i++] = v % 10 + '0';
        s[i] = '\0';
    }
    return i;
}