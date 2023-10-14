#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

int min(int a, int b, int c)
{
    int min = a;
    if (b < min)
        min = b;
    if (c < min)
        min = c;
    return min;
}

int levenshtein_edit_dis(char *s1, char *s2)
{
    int len1 = strlen(s1);
    int len2 = strlen(s2);

    for (int k = 0; k < len1; k++)
    {
        s1[k] = tolower(s1[k]);
    }
    for (int l = 0; l < len2; l++)
    {
        s2[l] = tolower(s2[l]);
    }
    // Allocate memory for 2d array (table)
    int **table = (int **)malloc((len1 + 1) * sizeof(int *));
    for (int i = 0; i <= len1; i++)
    {
        table[i] = (int *)malloc((len2 + 1) * sizeof(int));
    }

    for (int i = 0; i <= len1; i++)
    {
        for (int j = 0; j <= len2; j++)
        {
            if (i == 0)
                table[i][j] = j;
            else if (j == 0)
                table[i][j] = i;
            else if (s1[i - 1] == s2[j - 1])
                table[i][j] = table[i - 1][j - 1];
            else 
                table[i][j] = 1 + min(table[i - 1][j], table[i][j - 1], table[i - 1][j - 1]);
        }   
    }
    
    // for (int i = 0; i <= len1; i++)
    // {
    //     for (int j = 0; j <= len2; j++)
    //     {
    //         printf("%2d ", table[i][j]);
    //     }
    //     printf("\n");
    // }

    return table[len1][len2];
}

int main()
{
    int str1_size = 110;
    int str2_size = 110;
    char str1[str1_size];
    char str2[str2_size];

    // Get str1
    fgets(str1, str1_size, stdin);
    if (str1[str1_size - 1] == '\n')
    {
        str1[str1_size - 1] = '\0';
    }
    // Get str2
    fgets(str2, str2_size, stdin);
    if (str2[str2_size - 1] == '\n')
    {
        str2[str2_size - 1] = '\0';
    }

    int distance = levenshtein_edit_dis(str1, str2);
    printf("%d\n", distance);

    return 0;
}
