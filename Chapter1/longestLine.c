#include <stdio.h>
#define MAXLINE 10 /*maximum input line length*/

int get_line(char line[], int maxline);
void copy(char to[], char from[]);

/* print longest input line */
int main( ) {
    int len;
    int max;
    char line[MAXLINE];
    char longest[MAXLINE];

    max = 0;
    while ((len = get_line(line, MAXLINE)) > 0) {
        if (len > max) {max = len; copy(longest, line);}
    }
    if (max > 0) printf("%d: %s", max, longest);
    return 0;
}

/*get_line: read a line into s, return length*/
int get_line(char s[], int lim) {
    int c = 0;
    int i = 0;
    int j = 0;

    for (i = 0; (c = getchar()) != EOF && c != '\n'; ++i) {
        if (i < lim - 1) s[i] = c;
        ++j;
    }
    if ( c == '\n') {
        if (i < lim - 1) {
            s[i] = c; 
            ++i; 
        }
        ++j;
    }
    if (i < lim) {s[i] = '\0';}
    else {s[lim-1] = '\0';}
    return j;
} 

void copy(char to[], char from[]) {
    int i = 0;

    while ((to[i] = from[i]) != '\0') ++i;
}