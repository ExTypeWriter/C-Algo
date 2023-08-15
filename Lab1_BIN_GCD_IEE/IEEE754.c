#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

typedef struct t_stack
{
    char string;
    struct t_stack *next;
}t_stack;

float StringToFloat(char* String);
double abs_double(double num);
double mod_double(double divided,double divisor);
void push(t_stack **top, char stream);
void pop(t_stack **top);
char peek(t_stack **top);
bool SignBitIsNegative(char signBit);
void pause ( void );

int main()
{
    t_stack *stackForward = NULL, *stackBackward = NULL;
    char buffer[10000] = {'\0'};
    char *token;
    printf("Input float: ");
    fgets(buffer, sizeof(buffer), stdin);
    if (buffer[strlen(buffer) - 1] == '\n')
    {
        buffer[strlen(buffer) - 1] = '\0';
    }

    float number = StringToFloat(buffer);

    // Append Sign Bit
    char signBit = SignBitIsNegative(number) ? '1' : '0';
    push(&stackBackward, signBit);

    // Constructing Mantissa Part
    int exponent = 0;
    float fractionalPart = abs_double(fmod(number, 1.0));
    while (fractionalPart > 0.0 && exponent >= -127)
    {
        fractionalPart *= 2.0;
        push(&stackBackward, '0' + (int)fractionalPart);
        fractionalPart -= (int)fractionalPart;
        exponent--;
    }

    // Adjusting the exponent bias and converting to IEEE 754 representation
    int adjustedExponent = exponent + 127;
    char exponentBits[8];
    for (int i = 0; i < 8; i++)
    {
        exponentBits[i] = '0' + ((adjustedExponent >> (7 - i)) & 1);
    }

    // Constructing the IEEE 754 representation
    for (int i = 0; i < 8; i++)
    {
        push(&stackBackward, exponentBits[i]);
    }

    // Reverse stack
    while (stackBackward != NULL)
    {
        push(&stackForward, peek(&stackBackward));
        pop(&stackBackward);
    }

    // Print the IEEE 754 representation from the forward stack
    printf("Binary Representation: ");
    while (stackForward != NULL)
    {
        printf("%c", peek(&stackForward));
        pop(&stackForward);
    }
    
    // Print the hexadecimal representation
    unsigned int hexValue;
    memcpy(&hexValue, &number, sizeof(hexValue));
    printf("\nHexadecimal Representation: %#08X\n", hexValue);
    pause();
    return 0;
     // Thai version
//     // Print the IEEE 754 representation from the forward stack
//     wchar_t binA[] = L"เลขฐานสอง: ";
//     wprintf(L"%ls",binA);
//     while (stackForward != NULL)
//     {
//         printf("%c", peek(&stackForward));
//         pop(&stackForward);
//     }
//     printf("\n");
//     // Print the hexadecimal representation
//     wchar_t hexA[] = L"เลขฐานสิบหก: ";
//     unsigned int hexValue;
//     memcpy(&hexValue, &number, sizeof(hexValue));
//     wprintf(L"%ls");
//     printf("%#08x\n",hexValue);
//     return 0;
}

void push(t_stack **top, char stream)
{
    t_stack *newNode = (t_stack *)calloc(1, sizeof(t_stack));
    newNode->string = stream;
    
    if (*top == NULL)
    {
        newNode->next = NULL;
        *top = newNode;
    }
    else
    {
        newNode->next = *top;
        *top = newNode;
    }
}

void pop(t_stack **top)
{
    if (*top == NULL)
    {
        printf("STACK UNDERFLOW\n");
        return;
    }
    
    t_stack *node_to_free = *top;
    *top = (*top)->next;
    free(node_to_free);
}

char peek(t_stack **top)
{
    if (*top != NULL)
    {
        return (*top)->string;
    }
    return '\0';
}

bool SignBitIsNegative(char signBit)
{
    return signBit == '-';
}

double abs_double(double num){
     return fabs(num);
}

double mod_double(double dividend,double divisor){
     return fmod(dividend,divisor);
}

float StringToFloat(char* String){
     return atof(String);
}

void pause ( void )
{
  printf ( "Press enter to continue..." );
  fflush ( stdout );
  getchar();
}