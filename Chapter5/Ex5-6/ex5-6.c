#include "ex5-6.h"
#include <stdio.h>
#include <ctype.h>
/*
Ex 5-6: Rewrite previous exercises using pointers where appropriate. We give
the examples of
- int getLine(char s[], int lim) -> int getLine(char *s, int lim)
- int atoi(char s[]) -> int atoi(char *s)
- void itoa(int n, char s[]) -> char 
*/
#define SHIFT(_b, x, y) do {\
    x = _b * x + (y - '0'); \
} while(0)\

#define INT_SHIFT(x, y) SHIFT(10, x, y)

#define FLOAT_SHIFT(x, y) SHIFT(10.0, x, y)

#define SWAP(x, y) do { \
    int _tmp = x;       \
    x = y;              \
    y = _tmp;           \
} while(0)              \


/*
Pointer implementation of getLine.
Strips newlines.
*/
#define EX5_6_ABS(x) ((x) < 0) ? -(x) : (x)
#define BASE 10
#define BLANK 'b' /* Using b for visibility */

int getLine(char *s, unsigned int lim)
{
    if (!lim) {
        s = NULL;
        return 0;
    }
    int c = 0, i;
    for(i = 0; --lim > 0 && (c = getchar()) != EOF && c != '\n'; s++, i++) {
        *s = c;
    } 
    *s = '\0';
    return i;
}

int atoi(char *s)
{
    int n, sign;
    while(isspace(*s)) s++;
    sign = (*s == '-' ? -1 : 1);
    if (*s == '+' || *s == '-') s++;
    for(n = 0; isdigit(*s); s++) INT_SHIFT(n, *s);
    return sign * n;
}

void itoa(int n, char *s)
{
    int sign;
    char *start = s;
    if ((sign = n) < 0) n = -n;
    do {
        *s++ = n % BASE + '0';
    } while((n /= BASE) > 0);
    if (sign < 0) *s++ = '-';
    *s = '\0';
    reverse(start);
}

void itob(int n, char *s, unsigned int b)
{
    int v, sign;
    char *start = s;
    if ((sign = n) < 0) n = -n;
    do {
        v = n % b;
        *s++ = v + ((v < 10) ? '0' : 'A' - 10);
    } while((n /= b) != 0);
    if (sign < 0) *s++ = '-';
    *s = '\0';
    reverse(start);
}

void itoa2(int n, char *s, unsigned int w)
{
    char *start = s;
    int sign;
    if ((sign = n) < 0) n = -n;
    do {
        *s++ = n % BASE + '0';
        w--;
    } while((n /= BASE) != 0);

    if (sign < 0) {*s++ = '-'; w--;}

    while(w > 0) {*s++ = BLANK; w--;}
    *s = '\0';

    reverse(start);
}

double atof(char *s)
{
    double val = 0.0, power;
    int sign, exp;
    while(isspace(*s)) s++;
    sign = (*s == '-' ? -1 : 1);
    if (*s == '+' || *s == '-') s++;
    for (; isdigit(*s); s++) {
        FLOAT_SHIFT(val, *s);
    }
    if (*s == '.') s++;
    for (power = 1.0; isdigit(*s); s++) {
        FLOAT_SHIFT(val, *s);
        power *= 10;
    }
    val = sign*val / power;
    if (*s == 'e' || *s == 'E')
    {
        sign = (*(++s) == '-' ? -1 : 1);
        if (*s == '+' || *s == '-') s++;
        for (exp = 0; isdigit(*s); s++) {
            INT_SHIFT(exp, *s);
        }
        if (sign == 1) {
            for (; exp > 0; exp--) val *= 10;
        }
        else {
            for (; exp > 0; exp--) val /= 10;
        }
    }
    return val;
}

void reverse(char *s)
{
    char *t = s;
    while(*t++);
    t -= 2; /* move *t back to '\0', then back to last character */
    for(; s < t; s++, t--) {
        SWAP(*s, *t);
    }
}

int strindex(char *s, char *t)
{
    char *a = s;
    char *b, *c;
    for (; *s != '\0'; s++)
    {
        for (b = s, c = t; *c != '\0' && *b == *c; b++, c++);
        if (c > t && *c == '\0') return s - a;
    }
    return -1;
}

int strrindex(char *s, char *t)
{
    char *a = s;
    char *b, *c;
    int found = -1;
    for (; *s != '\0'; s++)
    {
        for (b = s, c = t; *c != '\0' && *b == *c; b++, c++);
        if (c > t && *c == '\0') found = s - a;
    }
    return found;
}
