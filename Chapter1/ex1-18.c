 #include <stdio.h>

/*
Ex1-18: Removes trailing blanks and tabs and ignores fully blank lines*/


#define MAXLINE 1000
#define BLANK_LINE_MARKER -1
#define TRUE 1
#define FALSE 0

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

    int last_non_blank = BLANK_LINE_MARKER;
    int has_newline = FALSE;
    int j;
    int c = 0;

    for (j = 0; (j < len) && (c = line[j]) != '\n'; ++j) {
        if (line[j] != '\t' && line[j] != ' ') last_non_blank = j;
    }
    if (c == '\n') {has_newline = TRUE;} 
    else {
        if (has_newline) {++last_non_blank; line[last_non_blank] = '\n';}
        line[++last_non_blank] = '\0';
        j = last_non_blank;
    }
    return j;
}