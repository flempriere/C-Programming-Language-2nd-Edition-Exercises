/*
Exercise 2-10
reimplements lower(char s[]) using a conditional operator
*/
#include <stdio.h>
#include <stdlib.h>

int getLine(char s[], int lim);
void lower_s(char s[]);
int lower(int c);

#define MAX_LENGTH 10

int main()
{
    char s[MAX_LENGTH];
    printf("Enter a string of length < %d\n", MAX_LENGTH);
    getLine(s, MAX_LENGTH);
    printf("string s: %s\n", s);
    lower_s(s);
    printf("lowered string s: %s\n", s);
    return 0;
}

int getLine(char s[], int lim)
{
    /*for simplicity of example this getline will strip
    the newline, since it makes presenting the problem
    cleaner */ 
    int i, c = 0;
    for (i = 0; i < lim - 1 &&
        (c = getchar()) != EOF && c != '\n';) s[i++] = c;
    s[i] = '\0';
    return i;
}

void lower_s(char s[])
{
    int i = 0;
    int c;
    for (i = 0; (c = s[i]) != '\0'; ) {s[i++] = lower(c);}
}

int lower(int c)
{
    return (c >= 'A' && c <= 'Z') ? c + 'a' - 'A' : c;
}
