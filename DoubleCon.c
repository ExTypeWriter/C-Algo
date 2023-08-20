#include <stdio.h>
#include <math.h>

int main() {
    double number = 10.75;  // Replace with your desired decimal value
    
    int integerPart = (int)number;
    double fractionalPart = number - integerPart;

    // Convert integer part to binary
    int intBinary = 0;
    int intBinaryPos = 1;
    while (integerPart > 0) {
        int remainder = integerPart % 2;
        intBinary = intBinary + remainder * intBinaryPos;
        intBinaryPos *= 10;
        integerPart /= 2;
    }

    // Convert fractional part to binary
    char fracBinary[52] = "";
    int fracBinaryPos = 0;
    while (fracBinaryPos < 52) {
        fractionalPart *= 2;
        int intPart = (int)fractionalPart;
        fractionalPart -= intPart;
        fracBinary[fracBinaryPos] = intPart + '0';
        fracBinaryPos++;
    }
    fracBinary[fracBinaryPos] = '\0';

    char intBinaryString[32]; // Adjust the buffer size as needed
    sprintf(intBinaryString, "%d", intBinary);
    intBinaryString[0] = ' ';

    // Print the binary representation in the specified format
    printf("Binary representation: %s.%s\n", intBinaryString, fracBinary);

    return 0;
}
