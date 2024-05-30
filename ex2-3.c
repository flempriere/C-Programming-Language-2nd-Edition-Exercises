/*
Chapter 2, Exercise 3,

htoi: Converts hexadecimal digit string repr
to decimal value

hextoint assumes ASCII representation
*/

#include <stdio.h>
#include <ctype.h>

#define HEX_BASE 16
#define A_IN_HEX 10
#define MAXLINE 1000

int htoi(char s[]);
int hextoint(char c);
int has_prefix(char s[]);
int getLine(char s[]);

int main(void)
{
    char line[MAXLINE];
    while (getLine(line)) {
        printf("%d\n", htoi(line));
    }

}

int htoi(char s[]) {
    int i, n, offset;
    n = offset =  0;
    offset = has_prefix(s);
    for (i = 0; isxdigit(s[i + offset]); ++i)
    {
        n = HEX_BASE * n + hextoint(s[i + offset]);
    }
    return n;
}

int hextoint(char c) {
    if isdigit(c) return (c - '0');
    else return (tolower(c) - 'a' + A_IN_HEX); 
}

int has_prefix(char s[])
{
    if (s[0] == '0') {
        if (tolower(s[1]) == 'x') return 2; 
    }
    return 0;
}

int getLine(char s[])
{
    int i = 0;
    char c;
    for (i = 0; i < MAXLINE - 1 &&  (c = getchar()) != EOF && c != '\n'; ++i)
    {
        s[i] = c;        
    }
    if (c == '\n') {s[i] = '\n'; ++i;}
    s[i] = '\0';
    return i;
}
