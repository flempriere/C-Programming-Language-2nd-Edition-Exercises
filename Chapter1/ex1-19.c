#include <stdio.h>

#define MAXLINE 1000


int get_line(char line[], int maxline);
int reverse(char line[], int length);

int main() {
    int len;
    char line[MAXLINE];

    while ((len = get_line(line, MAXLINE)) > 0) {
        if ((len  = reverse(line, len)) > 0) printf("%s\n", line);
    }
    return 0;
}


int get_line(char line[], int maxline) {
    int c = 0;
    int i = 0;
    for (i = 0; i < maxline && (c = getchar()) != EOF && c != '\n'; ++i) {
        line[i] = c;
    }

    if (c == '\n') {line[i] = c; ++i;}

    line[i] = '\0';
    return i;
}

int reverse(char line[], int length) {
    int tmp;
    int i;
    for (i = 0; i < length/2; i++) {
        tmp = line[i];
        line[i] = line[length - i - 1];
        line[length - i - 1] = tmp;
    }
    return i*2+1;
}