/**
 * @file reverse.c
 * @author Felix Lempriere
 * @brief Pointer-based implementation of reverse in partial fulfillment of
 * Exercise 5.6 from The C Programming Language, 2nd Edition.
 *
 * @version 0.1
 * @date 2025-05-10
 *
 * @copyright Copyright (c) 2025
 *
 */

 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
 
 /**
  * @brief Reverse a string s inplace.
  *
  * @param s string to reverse.
  */
 void reverse(char* s);
 
 /**
  * @brief enum storing false and true values
  *
  * FALSE = 0;
  * TRUE = 1
  */
 enum truth {
     FALSE,
     TRUE
 };
 
 /**
  * @brief Test reverse(in) and compare to the expected.
  *
  * Given a string in, runs reverse on it and compares
  * the output to expected. Prints an error diagnostic if they disagree.
  *
  * @param in input string
  * @param expected expected result of reverse(in)
  * @return TRUE if reverse(in) == expected (as string equality), else
  * @return FALSE.
  */
 enum truth test_reverse(char* in, char* expected);
 
 int main(void) {
     char s[] = "";
     if (!test_reverse(s, "")) { return EXIT_FAILURE; }
     char s1[] = "a";
     if (!test_reverse(s1, "a")) { return EXIT_FAILURE; }
     char s2[] = "ab";
     if (!test_reverse(s2, "ba")) { return EXIT_FAILURE; }
     char s3[] = "abc";
     if (!test_reverse(s3, "cba")) { return EXIT_FAILURE; }
     printf("All tests passed successfully\n");
     return EXIT_SUCCESS;
 }
 
 void reverse(char* s) {
    char* t = s + strlen(s) - 1; //s + len -> takes to the '\0', move back one.
    for (; s < t; s++, t--) {
        char c = *s;
        *s = *t;
        *t = c;
    }
 }
 
 enum truth test_reverse(char* in, char* expected) {
     reverse(in);
     if (strcmp(in, expected)) {
         printf("Error: string %s, expected: %s\n", in, expected);
         return FALSE;
     }
     return TRUE;
 }