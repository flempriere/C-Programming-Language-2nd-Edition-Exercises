/**
 * @file ex5-17.c
 * @author Felix Lempriere
 * @brief Solution to Exercise 5.17 from The C Programming Language, 2nd Edition
 *
 * Add a field handling capability, so sorting may be done on fields, within
 * lines, each field sorted according to an independent set of options.
 *
 * We adopt the POSIX/GNU Sort convention for this exercise. By default
 * fields are delimited by "the empty string between a non-blank and blank". So
 * the example, " Foo, Boo" consists of the fields " Foo" and " Boo" which are
 * 1-indexed. We Let the user modify this delimiter with the global flag "-t c"
 * where c is the delimiting character. In that case the " Foo Bar" with -t ' '
 * would have three fields "", "Foo", "Bar".
 *
 * Fields are then specified, with the format, -k pos1[,pos2] to specify a sort
 * that consists of the line between pos1 and pos2 (or the end of the line 
 * if pos2 is excluded, *inclusive*)
 *
 * Positions have the format, `f[.c][opts]`, where $`f`$ is the field number,
 * $`c`$ is the number of the first character from the beginning of the field.
 * Fields and characters are numbered starting with a $`1`$. A character
 * position of 0 indicates the fields last character. If it is omitted from pos1
 * it assumed to be one for pos2 it is assumed to be 0.
 * 
 * 
 * @version 0.1
 * @date 2025-05-17
 *
 * @copyright Copyright (c) 2025
 *
 */

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

