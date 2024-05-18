# The C Programming Language
## Chapter 2: Types, Operators and Expressions

### Summary of Exercises

### Introduction

- *Variables and Constants*: basic data objects, names, types and optionally initial values listed by *Declarations*
- *Operators* specify actions taken on data objects
- *Expressions* combine variables and constants to create new values

### Variable Names

- Names are made of letters and digits
    - first character must be a letter
    - _ may be used as a letter
        - avoid starting names with _ since this may conflict with library routines
    - Upper and lower case letters are distinct, e.g. `X` != `x`
    - Practice: use lower case for *variables* and upper case for *symbolic constants*
- At least first 31 characters of an internal name are significant.
    - may be less for function names and external variables
        - (Since these may be used by assemblers and loaders - language can't control them.)
        - For external names, uniqueness only guaranteed for 6 characters and a single case
- Keywords (e.g. `if, else, int, float`) are reserved
- Use variable names that are related and unlikely to get mixed up
    - short for local variables, longer for external variables

### Data Types and Sizes

There are limited C data types
- `char`: single byte (can hold one character in the local character set)
- `int`: integer, reflecting natural size of integer on the host machine
- `float`: single-precision floating point
- `double`: double-precision floating point

Qualifiers can be used to modify types
- e.g. `short` and `long` which may be applied to integers
    - `short` and `long` should provide different size ints
        - `short` is often 16 bits (2 bytes)
        - `long` is often 32 bits (4 bytes)
        - `int` is either 16 or 32 bits
    - Compiler choses the size but `shorts` and `ints` are at least 16 bits and `longs` at least 32 bits
    with a `short` to be no longer than an `int`, with `int` to be no longer than a `long`.
- e.g. `signed` and `unsigned` which may apply to `char` and `int`
    - unsigned types are non-negative and subject to modulo arithmetic of $2^n$ where $n$ is the number of bits.
    - signed ints typically use two's complement therefore a 16 bit `char` has a range from $-128$ to $127$.
    - plain `char` may be `signed` or `unsigned`, but all printable characters are positive.
- `long double` specifies extended floating point precision
    - implementation is machine dependent, `float`, `double`, `long double` may be one, two or three distinct types.

- the standard headers `<limits.h>` and `<float.h>` contain symbolic constants for these sizes and other
machine and compiler.

