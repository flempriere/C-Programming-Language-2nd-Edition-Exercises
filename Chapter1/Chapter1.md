# The C Programming Language
## Chapter 1: A Tutorial Introduction

### Summary of Exercises

- Ex 1-3: Print a heading above the a Fahrenheit-Celcius Table
- Ex 1-4: Print a Table converting Celcius to Fahrenheit (i.e. inverse)
- Ex 1-5: Prints the table in reverse
- Ex 1-6: Compares assignment priority of `!=` and `=`.
- Ex 1-7: Prints the value of `EOF`.
- Ex 1-8: Counts blanks, tabs and newlines
- Ex 1-9: Copies input to output, replacing strings
of blanks by a single blank
- Ex 1-10: Copies input to output, replacing tabs with `\t`, each backspace `\b` and each backslash
by `\\`
- Ex 1-12: prints input one word per line
- Ex 1-13: prints a histogram of word lengths in input (horizontally)
- Ex 1-14: prints a histogram of the frequencies of characters in its input. (horizontally)
- Ex 1-15: Temperature conversion with function (see Celsius2Fahrenheitv3.c)
- Ex 1-16: Prints length of all lines and stores up to MAXLINE characters of a line (see longestLine.c)
- Ex 1-17: Prints all input lines longer than 80 characters
- Ex 1-18: Removes trailing blanks and tabs from each input line and deletes blank lines
- Ex 1-19: Reverses a programs input one line at a time
- Ex 1-20: Replaces tabs in input with the correct number of blank spaces
- Ex 1-21: Replaces blanks with the minimum number of tabs and blanks to achieve the same result
- Ex 1-22: Folds long lines into multiple lines after the last non-blank character before the n-th column
- Ex 1-23: Removes all comments from a C file
- Ex 1-24: Basic C syntax checker



### `printf()` and formatted output

- Defined by the ANSI Standard
- `%d` denotes an integer
    - `3%d` prints integers in a right-aligned
    field at least three digits wide
- `%f` denotes a float
    - `6.1%f` denotes a float at least 6 wide, with
    one digit after the decimal place
- 

### `for` statements

- Syntax: `for(initialisation ; stop condition ; increment)`

### Symbolic Constants
- Bad practice to bury magic numbers in a code
    - i.e. numbers without context as to choice for a latter reader.
- `#define` defines a *symbolic name* or *symbolic constant* 
    - `#define name replacement_text`
    - any instance of `name` not in quotes or as part of another word is replaced by `replacement_text`.
- occur before main.
- Conventionally written in UPPER case
- No semicolon!

### Character Input and Output
- Text input/output is dealt with as a character stream
- A *text stream* is a sequence of characters divided into lines of zero or more characters then a newline (`\n`).
- A library must conform to this model.
- `getchar()` and `putchar()` are the simplest standard library I/O functions.
    - `c = getchar()` reads then returns the next input and assigns it to `c`.
    character.
    - `putchar(c)` prints the contents of the integer `c` as a character to a stream.
- `EOF` is a special symbol to denote the end of a file.

### Precedence and assignment
- assignments can be made as part of a broader expression
    - e.g. the expression `(c = getchar()) != EOF)`
    assigns the return of `getchar()` to `c`compares that to `EOF` and returns True if not equal and false if they are equal.
- One needs to be careful of precedence, e.g. `!=` has a higher precedence than `=`.
    - `c = getchar() != EOF`is equiv to `c = (getchar() != EOF)`. So `c` is set to `0` or `1`.

### Prefix increment vs Postfix and Equality test
- `++nc` increments `nc` by one
- similar exist for `--`
- can either prefix or postfix and operate slightly differ
- `==` tests for equality

### Characters
- A character between single quotes `'c'` is a `char` datatype or *character constant* , it is a
small integer
- e.g. `'A'` represents a character constant, in ASCII it is equivalen to the number `65`.

### Initialising multiple variables
- the line `nl = nw = nc = 0` sets all three variables to zero. Assignments associate right to left.
    - `nc` first assigned `0`
    - `nw` then assigned same value as `nc`
    - `nl` then assigned same value as `nw`

### Logic Operators
- `||` means OR
- `&&` means AND
- `&&` has higher precedence than `||`
- Expressions containing `||` and `&&` are evaluated left to right
    - will stop once truth or falsehood known

### Arrays
- Declared by `datatype variable[size]`. 
- C arrays are statically sized
### Functions
- typically refer to the variables in a function
declaration as *parameters*
- declaration style `return_type function_name(parameter list)`. 
- return output via `return expression`
- *function prototypes* give the function signature
but not the implementation.
- `void` keyword should be used for functions that
take in no arguments.


### Functions - call by value
- function arguments are copied by value
- values are given in temporary variables rather
than the orginal.
- Parameters can be treated as convenient local variables.

E.g. 
> `int power(int base, int n)
{
    for (int p = 1; n > 0; --n) p = p * base; return p;
}`

`n` is used as a temporary variable counted down to zero, `n` outside the function is unchanged.

### Character Arrays
- A `string` is an array of characters that is null-terminated (`\0` as the final character)
- String constants `"hello\n"`
- `%s` allows printing of a string
- `\0` is not a part of normal text

### External Variables and Scope
- variables are *private* or *local* to where they are declared
    - e.g. in `main`
- variables exist only so long as the function that
instances them is running
    - these variables are sometimes referred to as
    *automatic*.
- They must be set each time, else they contain garbage
- *external* variables may be defined in the outermost
block.
    - they must be *defined* once
    - then declared in each accessing function
        - you can use `extern`
        - extern is not needed if the declaration
        preceeds the function in the source code
        - extern is needed to connect variables across
        source files
            - typically in a `.h` file to `#include`.





