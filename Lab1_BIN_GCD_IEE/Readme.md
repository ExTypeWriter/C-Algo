# IEEE 754 Double Precision Floating-Point Conversion

This program converts a decimal number into its IEEE 754 double-precision floating-point binary representatiion. it include hqndling for normal numbers, special values (NaN and infinity), and zero.
### Dependencies

- Standard C libraries: `stdio.h`, `stdlib.h`, `stdbool.h`, `string.h`, `math.h`

### Constants

- `EXPO_BIT`: Number of exponent bits (11)
- `SIG_BIT`: Number of significand bits (52)

### Data Structure

The program utilizes a custom stack data structure `t_stack` to store binary bits.

### Functions

- `push(t_stack **top, char stream)`: Pushes a character onto the stack.
- `pop(t_stack **top)`: Pops the top element from the stack.
- `peek(t_stack **top)`: Returns the top element of the stack without popping it.
- `decimalToBinary(double decimal, t_stack **stack)`: Converts a double into its 
binary representation and pushes the bits onto the stack.

### Main Function

- Parses user input for a decimal number.
- Determines the sign bit and handles various special cases (NaN, infinity, zero).
- Converts the number to binary and pushes the bits onto the stack.
- Reverses the stack to get the correct bit order.
- Prints the IEEE 754 binary representation of the input number.

### Helper Functions

- `abs_double(double num)`: Calculates the absolute value of a double.
- `round(double num)`: Rounds a double to the nearest integer.
- `push_binary(double Num, t_stack **stack, int *zero_count, int *index_first)`: Pushes binary bits of the integer part of a number onto the stack.
- `push_frac(double Num, t_stack **stack, int *zero_count, int *index_first)`: Pushes binary bits of the fractional part of a number onto the stack.
- `SignBitIsNegative(char number)`: Checks if a character represents a negative sign.
- `double userInput(t_stack **stack)` : Recieve user input with fgets then tokenize them into characters to check for input format errors.
- `pause(void)`: Pauses the program and waits for user input before program window exit.
### Usage

1. Input a decimal number.
2. The program converts the number to its IEEE 754 binary representation.
3. The binary representation is displayed.
