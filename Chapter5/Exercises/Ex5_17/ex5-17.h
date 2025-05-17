/**
 * @file ex5-17.h
 * @author File containing function definitions and macros for Exercise 5.17
 * from The C Programming Language, 2nd Edition.
 * @brief 
 * @version 0.1
 * @date 2025-05-17
 * 
 * @copyright Copyright (c) 2025
 * 
 */

// LINE I/O

/**
 * @brief Maximum number of lines to be sorted.
 *
 */
#define MAXLINES 5000

/**
 * @brief Maximum length of any specific input line
 *
 */
#define MAXLEN 1000

/**
 * @brief Array storing pointers to the input lines.
 *
 */
char* lineptr[MAXLINES];

/**
 * @brief Array storting the starting indices for the fields in
 * a line.
 *
 * The convention is that linefields[i][j] is the starting index
 * of the j-th field in i. Fields are 1-indexed, and linefields[i][0] is used
 * to store the length of the i-th string. This means the idiom,
 * linefields[i][(j + 1) % N] - linefields[i][j] where N is the number of
 * strings gives the span of the field.
 *
 */
int linefields[MAXLINES][MAXLINES];

/**
 * @brief Reads up to maxlines from stdin and store them in the array of strings
 * pointed to by lineptr, field indices split by delimiter and stored in the
 * array fields.
 *
 * @param maxlines maximum number of strings to store in the array.
 * @param lineptr pointer to an array of strings.
 * @param fields 2d array to store the fields, delimited by delim of the
 * strings in.
 * @param delim Delimiter to split fields on. if delim is negative, then
 * fields are split on the transition between a blank and non-blank. The delim
 * character is not including in the fields.
 *
 * @return number of lines read, if an error occurs then
 * @return -1.
 */
int read_lines(int maxlines, char* lineptr[], int* fields[], int delim);

/**
 * @brief Writes the string stored in the array pointed to by lineptr to stdout.
 *
 * @param nlines number of lines in the array
 * @param lineptr array of strings.
 */
void write_lines(int nlines, char* lineptr[]);

/**
 * @brief Gets a line from standard input and stores it in line.
 *
 * @param line line to read into
 * @param lim maximum size of input
 * @return length of the input line read, if no line is read then,
 * @return 0.
 */
int get_line(char line[], int lim);

// Memory management

/**
 * @brief Size of the memory buffer
 *
 */
#define ALLOCSIZE (MAXLINES * MAXLEN)

/**
 * @brief Storage for alloc
 *
 */
static char allocbuf[ALLOCSIZE];

/**
 * @brief Next free position in the alloc buffer.
 *
 */
static char* allocp = allocbuf;

/**
 * @brief Allocate memory from the buffer
 *
 * @param n Number of bytes to allocate
 * @return char* pointer to allocated memory.
 */
char* alloc(int n);

// sort functionality

/**
 * @brief Enum containing options, options set to powers of two
 * to allow bit-packing.
 *
 */
enum option_flags {
    NONE = 0,
    NUMERIC = 1,
    REVERSE = (NUMERIC << 1),
    FOLD = (REVERSE << 1),
    DIR = (FOLD << 1),
    FIELD = (DIR << 1)
};

/**
 * @brief Tracks the initial indices of the lines, so that the parallel arrays
 * containing metadata can still be referenced.
 *
 */
int orig_idx[MAXLINES];

/**
 * @brief Sorts the char* points in lineptr between left and right.
 *
 * @remark This version is provided to maintain fast sorting where only a global
 * sort is specified.
 *
 * @param lineptr array of strings to sort
 * @param left left index to sort from (inclusive)
 * @param right right index to sort to (inclusive)
 * @param comp comparison function to use to determine ordering, comp must
 * satisfy:
 *      - comp(a, b) < 0 if a < b,
 *      - comp(a, b) == 0, if a = b,
 *      - comp(a, b) > 0 if a > b
 */
void my_qsort(void* lineptr[], int left, int right, int (*comp)(void*, void*));

void my_qsort_fields(void* lineptr[], int left, int right, int fields);

/**
 * @brief Swap the pointers v[i] and v[j] in the array v.
 *
 * @param v array of void pointers
 * @param i index of first pointer to swap
 * @param j index of second pointer to swap
 */
void swap(void* v[], int i, int j);

// comparison functions

/**
 * @brief Makes the cast to a comparison function a bit more readable.
 *
 * @param f comparison function to cast
 */
#define CAST_COMPARISON_FUNCTION(f) ((int (*)(void*, void*))(f))

/**
 * @brief Comparison function that compares two strings lexigraphically,
 * with upper case and lower case characters considered equal.
 *
 * @param s1 first string to compare
 * @param s2 second string to compare
 * @return int, after converting s1 and s2 to all lower case,
 * @return < 0, if s1 < s2,
 * @return 0, if s1 == s2, else,
 * @return > 0 if s1 > s2.
 */
int foldcmp(char* s1, char* s2);

/**
 * @brief Comparison function that compares two strings in directory order,
 * which is lexigraphical but only considering letters, numbers and blanks.
 *
 * @param s1 first string to compare
 * @param s2 second string to compare
 * @return int, after converting s1 and s2 to directory form,
 * @return < 0, if s1 < s2,
 * @return 0, if s1 == s2, else,
 * @return > 0 if s1 > s2.
 */
int dircmp(char* s1, char* s2);

/**
 * @brief Comparison function that compares two strings in folded directory
 * order, which is lexigraphical but only considering letters, numbers
 * and blanks with all upper case characters considered equal to their lower
 * case counterpart.
 *
 * @param s1 first string to compare
 * @param s2 second string to compare
 * @return int, after converting s1 and s2 to directory form,
 * @return < 0, if s1 < s2,
 * @return 0, if s1 == s2, else,
 * @return > 0 if s1 > s2.
 */
int folddircmp(char* s1, char* s2);

/**
 * @brief Comparison function that compares two strings numerically
 *
 * @param s1 first string to compare
 * @param s2 second string to compare
 * @return int, after converting s1 and s2 to doubles, returns < 0, if s1 < s2,
 * @return 0, if s1 == s2, else,
 * @return > 0 if s1 > s2.
 *
 * @warning Behaviour is undefined if s1 or s2 cannot be converted to floats
 */
int numcmp(char* s1, char* s2);

/**
 * @brief Takes in an options string and returns the appropriate comparison
 * function.
 *
 * @param options options flag enum containing the appropriately set flags
 *
 * @return int(*)(void*, void*) comparison flag
 */
int (*select_comparator(enum option_flags options))(void*, void*);

// comparison functions

/**
 * @brief Makes the cast to a sized comparison function a bit more readable.
 *
 * @param f comparison function to cast
 */
#define CAST_SIZED_COMPARISON_FUNCTION(f) ((int (*)(void*, void*, int))(f))

/**
 * @brief Comparison function that compares two strings lexigraphically,
 * with upper case and lower case characters considered equal, comparing at
 * most $`n`$ characters.
 *
 * @param s1 first string to compare
 * @param s2 second string to compare
 * @param n maximum length substring to compare
 * @return int, after converting s1 and s2 to all lower case,
 * @return < 0, if s1 < s2,
 * @return 0, if s1 == s2, else,
 * @return > 0 if s1 > s2.
 */
int foldncmp(char* s1, char* s2, int n);

/**
 * @brief Comparison function that compares two strings in directory order,
 * which is lexigraphical but only considering letters, numbers and blanks and
 * at most $`n`$ characters.
 *
 * @param s1 first string to compare
 * @param s2 second string to compare
 * @param n maximum length substring to compare
 * @return int, after converting s1 and s2 to directory form,
 * @return < 0, if s1 < s2,
 * @return 0, if s1 == s2, else,
 * @return > 0 if s1 > s2.
 */
int dirncmp(char* s1, char* s2, int n);

/**
 * @brief Comparison function that compares two strings in folded directory
 * order, which is lexigraphical but only considering letters, numbers
 * and blanks with all upper case characters considered equal to their lower
 * case counterpart. Compares at most $`n`$ characters.
 *
 * @param s1 first string to compare
 * @param s2 second string to compare
 * @param n maximum length substring to compare
 * @return int, after converting s1 and s2 to directory form,
 * @return < 0, if s1 < s2,
 * @return 0, if s1 == s2, else,
 * @return > 0 if s1 > s2.
 */
int folddirncmp(char* s1, char* s2, int n);

/**
 * @brief Comparison function that compares two strings numerically
 *
 * @param s1 first string to compare
 * @param s2 second string to compare
 * @return int, after converting s1 and s2 to doubles, returns < 0, if s1 < s2,
 * @return 0, if s1 == s2, else,
 * @return > 0 if s1 > s2.
 *
 * @warning Behaviour is undefined if s1 or s2 cannot be converted to floats
 */
int numncmp(char* s1, char* s2);

/**
 * @brief Takes in an options string and returns the appropriate comparison
 * function to be used on a field on known size.
 *
 * @param options options flag enum containing the appropriately set flags
 *
 * @return int(*)(void*, void*, int) sized-comparison function.
 */
int (*select_field_comparator(enum option_flags))(void*, void*, int);

// Field Handling Set up

/**
 * @brief Queue containing field to start a sort on.
 * 
 */
int fsort_srt[MAXLINES];

/**
 * @brief Queue containing starting character to start a sort on.
 * 
 */
int csort_srt[MAXLINES];

/**
 * @brief Queue containing field to stop a sort on.
 * 
 */
int fsort_stp[MAXLINES];

/**
 * @brief Queue containing the character to stop a sort on.
 * 
 */
int csort_stp[MAXLINES];

/**
 * @brief Queue containing the sort options for a given field sort.
 * 
 */
enum option_flags fsort_options[MAXLINES];

