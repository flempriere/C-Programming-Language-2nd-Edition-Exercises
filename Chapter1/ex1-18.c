 #include <stdio.h>

#define MAXLINE 1000

int get_line(char line[], int maxline);
int process_line(char line[], int len);

int main() {
    int len;
    char line[MAXLINE];

    while((len = get_line(line, MAXLINE))  > 0) {
        if ((len = process_line(line, len)) > 0) printf("%s", line);
    }
    return 0;
}

int get_line(char line[], int maxline) {
    int c = 0;
    int i = 0;

    for (i = 0; i < maxline -1 && (c = getchar()) != EOF && c != '\n';  ++i) {
        line[i] = c;
    }

    if (c == '\n') {line[i] = c; ++i;}

    line[i] = '\0';
    return i;
}

int process_line(char line[], int len) {
    int trail_flag = 1;
    if (!len) return len;
    for (int j = len; j > 0 || trail_flag; --j) {
        if(line[j-1] == ' ' || line[j-1] == '\t') {line[j-1] = '\0'; --len;}
        else trail_flag = 0;
    }
    return len;
}