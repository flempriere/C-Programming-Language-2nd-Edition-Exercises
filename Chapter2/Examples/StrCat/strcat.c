/**
 * @file strcat.c
 * @author Felix Lempriere
 * @brief Example program demonstrating concatenation of one string to another.
 * @version 0.1
 * @date 2025-04-26
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#include <stdio.h>
#include <stdlib.h>

/**
 * @brief size to allocate the string buffers
 * 
 */
#define STR_BUF 100
/**
 * @brief Concatenate t to the end of s.
 * S must be large enough to add t.
 * 
 * @param s first string
 * @param t string to append to s.
 */
void my_strcat(char s[], char t[]);

/**
 * @brief Compare two strings for equality
 * 
 * @param s 
 * @param t 
 * @return int 
 */
int my_streq(char s[], char t[]);

int main(void) {
    char s[STR_BUF] = "";
    char s1[STR_BUF] = "First";
    char s1_app_s[STR_BUF] = "First";
    char s_app_s1[STR_BUF] = "First";
    char s2[STR_BUF] = "Second";
    char s3_expected[STR_BUF] = "FirstSecond";

    my_strcat(s1, s);
    if (!my_streq(s1, s1_app_s)) {
        printf("Error: string: %s, expected: %s", s1, s1_app_s);
        return EXIT_FAILURE;
    }
    my_strcat(s, s1);
    if (!my_streq(s, s_app_s1)) {
        printf("Error: string: %s, expected %s\n", s, s_app_s1);
        return EXIT_FAILURE;
    }
    my_strcat(s1, s2);
    if (!my_streq(s1, s3_expected)) {
        printf("Error: string: %s, expected: %s", s1, s3_expected);
        return EXIT_FAILURE;
    }
    printf("All tests passed successfully\n");
    return EXIT_SUCCESS;
}

void my_strcat(char s[], char t[]) {
    int i = 0;
    int j = 0;
    while (s[i] != '\0') { //find the end of s
        i++; 
    }
    while ((s[i++] = t[j++]) != '\0'); /* copy t */
}

int my_streq(char s[], char t[]) {
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] != t[i]) { return 0; }
    }
    return 1;
}