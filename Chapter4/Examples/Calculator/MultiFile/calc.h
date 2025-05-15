/**
 * @file calc.h
 * @author Felix Lempriere
 * @brief Header file providing definitions for the various calculator modules.
 * @version 0.1
 * @date 2025-05-06
 *
 * @copyright Copyright (c) 2025
 *
 */

/**
 * @brief Signal that a number was found.
 *
 */
#define NUMBER '0'

/**
 * @brief Push a value onto the stack.
 *
 * @param v
 */
void push(double);

/**
 * @brief Pop a value from the stack
 *
 * @return value on top of the stack. The item is removed
 * from the stack.
 */
double pop(void);

/**
 * @brief Gets the next operator or operand
 *
 * @param s buffer to store the next operator or operand.
 * @return int value denoting the operator, or the that the buffer
 * contains an operand.
 */
int getop(char s[]);

/**
 * @brief Fetches a character from input.
 *
 * @return next input character
 */
int getch(void);

/**
 * @brief Push a character back onto the input buffer
 *
 * @param c character to push back
 */
void ungetch(int c);