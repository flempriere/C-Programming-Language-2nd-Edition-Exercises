/*
Exercise 3-3: Write a function expand(s1, s2) that expands
shorthand notations like a-z in the string s1 into the
equivalent complete list abc...xyz in s2. 

Allow for letters of either digit or case, and handle a-b-c,
a-z0-9 and -a-z. A leading or trailing - is taken literally
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_LENGTH 100


void expand(char s1[], char s2[]);
int handle_notation(char s[], int start, int stop, int i);
int getLine(char s[], int lim);

int main()
{
    char input_s[MAX_LENGTH], output_s[MAX_LENGTH];
    getLine(input_s, MAX_LENGTH);

    expand(input_s, output_s);

    printf("initial string: %s\n", input_s);
    printf("expanded string: %s\n", output_s);

    return 0;
}

void expand(char s1[], char s2[])
{
    char c;
    int i, j;
    for (i = j = 0; (c = s1[i++]) != '\0';) {
        if (isalnum(c) && (s1[i] == '-' && isalnum(s1[i + 1])))
        {
            j = handle_notation(s2, c, s1[i+1], j);
            i++; //skips the -
        }
        else
        {
            s2[j++] = c;
        }
    }
    s2[j] = '\0';
}

int handle_notation(char s[], int start, int stop, int i)
{
    for (; start < stop; start++) //relies on ASCII rep
    s[i++] = start;
    return i;
}

int getLine(char s[], int lim)
{
    int i, c = 0;
    for (i = 0; i < lim - 1 &&
        (c = getchar()) != EOF && c != '\n';) s[i++] = c;
    if (c == '\n') {
        s[i++] = c;
    }
    s[i] = '\0';
    return i;
}
