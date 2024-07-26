/*
strrindex(s,t): returns the position of the
rightmost occurrence of t in s, or -1 if there is
none

for simplicity we use the same driver code as the
example for strindex(s,t)
*/

#include <stdio.h>
#define MAXLINE 1000

int getLine(char line[], int lim);
int strrindex(char source[], char searchfor[]);

char pattern[] = "ould";

int main()
{
    char line[MAXLINE];
    int found = 0;
    int idx;
    while (getLine(line, MAXLINE) > 0) {
        if ((idx = strrindex(line, pattern)) >= 0) {
            printf("%s: rightmost index: %d", line, idx);
            found++;
        }
    }
}

int getLine(char s[], int lim)
{
    int i, c='\0';
    i = 0;
    while (--lim > 0 && (c = getchar()) != EOF && c != '\n') {
        s[i++] = c;
    }
    if (c == '\n') s[i++] = c;
    s[i] = '\0';
    return i;
}

int strrindex(char s[], char t[])
{
    int i,j,k;
    int found = -1;
    for (i = 0; s[i] != '\0'; i++) {
        for (j = i, k=0; t[k] != '\0' && s[j] == t[k]; j++, k++) {
            if (k >0 && t[k] == '\0') found = i;
        }
    }
    return found;
}