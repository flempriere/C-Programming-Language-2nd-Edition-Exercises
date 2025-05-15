/**
 * @file detab.c
 * @author Felix Lempriere
 * @brief Implements the detabbing functionality in partial fulfillment of a
 * solution to Exercise 5.12 from The C Programming Language, 2nd Edition.
 *
 * Identical implementation to Exercise 5.11.
 * @version 0.1
 * @date 2025-05-15
 *
 * @copyright Copyright (c) 2025
 *
 */

 #include "detab.h"

 #include <stdio.h>
 
 void detab(void) {
     int col = START_COL;
     for (int c; (c = getchar()) != EOF;) {
         switch (c) {
         case '\t':
             for (int nxt = next_tab(col); col < nxt; col++) { putchar(' '); }
             break;
         case '\n':
             putchar(c);
             col = START_COL;
             break;
         default:
             putchar(c);
             col++;
             break;
         }
     }
 }