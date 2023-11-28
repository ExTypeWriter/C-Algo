#include <stdio.h>
#include <stdlib.h>

//struct for unique character with shift value.
typedef struct
{
    char letter;
    int shift_value;
} ShiftCharacter;

// Fill Create array that contains unique characters in pattern string ( substring ).
ShiftCharacter *unique_array(char *pattern, int length, int *result_length)
{
    ShiftCharacter *array = (ShiftCharacter *)malloc(length * sizeof(ShiftCharacter));
    int uniqueIndex = 0;
    int i = 0;
    while (i < length)
    {
        int isUnique = 1;

        int j = 0;
        while (j < uniqueIndex)
        {
            if (pattern[i] == array[j++].letter)
            {
                isUnique = 0;
                break;
            }
        }
        if (isUnique)
        {
            array[uniqueIndex++] = (ShiftCharacter){.letter = pattern[i], .shift_value = length};
        }
        i++;
    }
    *result_length = uniqueIndex;
    return array;
}

// Print the shift table in 2 rows. First row for letter labels, and second row for shift values.
void print_table(int length, ShiftCharacter *array)
{
    int i = 0;
    while(i < length)
    {
        printf("%c ", array[i].letter);
        i++;
    }
    printf("\n");
    int j = 0;
    while(j < length)
    {
        printf("%d ", array[j].shift_value);
        j++;
    }
    printf("\n");
}

// Fill Table ( Array of ShiftCharacter ) with shift values calculate from : shift_value = pattern_length - index_of_character - 1.
void fill_shift_table(ShiftCharacter *unique, int unique_length, char *text, int length, int pat_length)
{
    int i = 0;
    while (i < pat_length - 1)
    {
        int j = 0;
        while (j < unique_length)
        {
            if (text[i] == unique[j].letter)
            {
                unique[j].shift_value = pat_length - i - 1;
                break;
            }
            j++;
        }
        i++;
    }
}

// Find substring with Boyer–Moore–Horspool algorithm's algorithm.
void horspool_substring(char *text, int length, char *pattern, int pat_length, ShiftCharacter *unique, int unique_length)
{
    int i = 0, q, comp_i, shift_val, j, k;
    while (i <= length - pat_length)
    {
        comp_i = i + pat_length - 1;
        shift_val = 1;
        q = 0;
        while (q < unique_length && text[comp_i] != unique[q++].letter)
            shift_val = (text[comp_i] == unique[q - 1].letter) ? unique[q - 1].shift_value : shift_val;

        if (text[comp_i] == pattern[pat_length - 1])
        {
            j = comp_i;
            k = pat_length;
            while (k > 0 && text[j--] == pattern[--k])
            {
                if (k == 0)
                {
                    printf("Pattern found at index %d\n", i);
                    return;
                }
            }
        }
        i += shift_val;
    }
    printf("Pattern not found in the text\n");
}

// Find length of string.
int find_length(char *text)
{
    int length = 0;
    while (text[length] != '\n')
    {
        length++;
    }
    text[length] = '\0';
    return length;
}

void pressEnterToContinue()
{
    printf("Press Enter to continue...");
    while (getchar() != '\n');
}

int main()
{
    char text[256];
    char pattern[256];
    printf("Text : ");
    fgets(text, sizeof(text), stdin);
    printf("Pattern : ");
    fgets(pattern, sizeof(pattern), stdin);
    int uni_length;
    int length = find_length(text);
    int pat_length = find_length(pattern);
    ShiftCharacter *unique_row = unique_array(pattern, pat_length, &uni_length);
    fill_shift_table(unique_row, uni_length, pattern, length, pat_length);
    printf("Create shift table : \n");
    print_table(uni_length, unique_row);
    horspool_substring(text, length, pattern, pat_length, unique_row, uni_length);
    pressEnterToContinue();
    free(unique_row);
    return 0;
}
