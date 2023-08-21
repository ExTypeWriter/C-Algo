# IEEE 754 Floating-Point Binary Representation Program
This program converts a given decimal number into its IEEE 754 floating-point representation. It supports both positive and negative numbers, Including special case.

## Table of Contents
* [Introduction](#introduction)
* [Code Explanation](#code-explanation)
* [Function Details](#function-details)
## Introduction
The IEEE 754 standard defines the representation of floating-point numbers in computers. This program takes a decimal number as input and converts it into its binary representation following the IEEE 754 standard.

## Code Explanation
The code is written in C and performs the following steps to process IEEE754 double precisions floating-point numbers:

1. **Input**: The user is prompted to input a decimal number.
2. **Sign Bit**: The program determines the sign bit (0 for positive, 1 for negative) and pushes it onto the stack.
3. **Special Cases** (NaN, Infinity, Zero): The program handles special cases like NaN (Not a Number) and infinity.
4. **Exponent**: The exponent part of the IEEE 754 representation is calculated, converted to binary, and pushed onto the stack.
Mantissa: The integer and fractional parts of the binary representation are pushed onto the stack.
Printing the Result: The binary representation is reversed and printed to the console.
## Function Details
The program uses a stack data structure to store the bits of the binary representation in reverse order. The following functions are defined to manage the stack and perform the conversion:

* void push(t_stack **top, char *stream): Pushes a character onto the stack.
void pop(t_stack **top): Pops the top element from the stack.
char peek(t_stack **top): Returns the top element of the stack.
* double abs_double(double num): Returns the absolute value of a double.
* double round(double num): Rounds a double value to the nearest integer.
* void push_binary(double Num, t_stack **stack, int *zero_count, int *index_first): Converts the integer part of the number to binary and pushes it onto the stack.
* void push_frac(double Num, t_stack **stack, int *zero_count, int *index_first): Converts the fractional part of the number to binary and pushes it onto the stack.
* bool SignBitIsNegative(char number): Checks if the sign bit should be negative.
* void pause(void): Pauses the program to display results. After complete execution.
