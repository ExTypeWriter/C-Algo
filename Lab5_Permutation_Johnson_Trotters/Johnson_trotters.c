#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include <math.h>
// Function to swap two characters
void swap(char *x, char *y)
{
    char temp = *x;
    *x = *y;
    *y = temp;
}

// Function to generate permutations using the brute-force method
void bruteForcePermutations(char characters[], int n)
{
    int i, j;
    int factorial = 1;

    // Calculate n!
    for (i = 1; i <= n; i++)
    {
        factorial *= i;
    }

    // Generate permutations using brute-force
    for (i = 0; i < factorial; i++)
    {
        for (int k = 0; k < n; k++)
        {
            if (k > 0)
            {
                printf(" "); // Add space between characters
            }
            printf("%c", characters[k]);
        }
        printf("\n");
        j = n - 2;
        while (j >= 0 && characters[j] >= characters[j + 1])
        {
            j--;
        }
        if (j == -1)
        {
            break; // All permutations generated
        }
        int k = n - 1;
        while (characters[j] >= characters[k])
        {
            k--;
        }
        swap(&characters[j], &characters[k]);
        int l = j + 1;
        int r = n - 1;
        while (l < r)
        {
            swap(&characters[l], &characters[r]);
            l++;
            r--;
        }
    }
}

// Function to swap two boolean values
void swapBool(bool *x, bool *y)
{
    bool temp = *x;
    *x = *y;
    *y = temp;
}

// Function to reverse a string from start to end
void reverse(char str[], int start, int end)
{
    while (start < end)
    {
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
}
// Function to find the largest mobile element in a string
int findLargestMobile(char str[], bool direction[], int n)
{
    int mobile = -1;
    for (int i = 0; i < n; i++)
    {
        if ((direction[i] && i > 0 && str[i] > str[i - 1] && str[i] > mobile) ||
            (!direction[i] && i < n - 1 && str[i] > str[i + 1] && str[i] > mobile))
        {
            mobile = str[i];
        }
    }
    return mobile;
}

// Function to generate and print all permutations using Johnson-Trotter's algorithm
void johnsonTrotterPermutations(char characters[], int n)
{
    char permutation[n + 1];
    strcpy(permutation, characters);

    bool direction[n];
    memset(direction, true, sizeof(direction)); // All elements initially point to the right

    for (int k = 0; k < n; k++)
    {
        if (k > 0)
        {
            printf(" "); // Add space between characters
        }
        printf("%c", permutation[k]);
    }
    printf("\n");

    while (true)
    {
        int mobile = -1;
        int mobileIndex = -1;

        // Find the largest mobile element
        for (int i = 0; i < n; i++)
        {
            if ((direction[i] && i > 0 && permutation[i] > permutation[i - 1] && permutation[i] > mobile) ||
                (!direction[i] && i < n - 1 && permutation[i] > permutation[i + 1] && permutation[i] > mobile))
            {
                mobile = permutation[i];
                mobileIndex = i;
            }
        }

        if (mobile == -1)
        {
            break; // All permutations generated
        }

        // Swap the mobile element
        if (direction[mobileIndex])
        {
            // Swap with the element to the left
            char temp = permutation[mobileIndex];
            permutation[mobileIndex] = permutation[mobileIndex - 1];
            permutation[mobileIndex - 1] = temp;

            bool tempDirection = direction[mobileIndex];
            direction[mobileIndex] = direction[mobileIndex - 1];
            direction[mobileIndex - 1] = tempDirection;
        }
        else
        {
            // Swap with the element to the right
            char temp = permutation[mobileIndex];
            permutation[mobileIndex] = permutation[mobileIndex + 1];
            permutation[mobileIndex + 1] = temp;

            bool tempDirection = direction[mobileIndex];
            direction[mobileIndex] = direction[mobileIndex + 1];
            direction[mobileIndex + 1] = tempDirection;
        }

        // Reverse the directions of all elements greater than the mobile element
        for (int i = 0; i < n; i++)
        {
            if (permutation[i] > mobile)
            {
                direction[i] = !direction[i];
            }
        }

        for (int k = 0; k < n; k++)
        {
            if (k > 0)
            {
                printf(" "); // Add space between characters
            }
            printf("%c", permutation[k]);
        }
        printf("\n");
    }
}

int main()
{
    char input[100];
    char input_2[100];
    struct timespec start_time, end_time;
    printf("Enter characters (e.g., ABC): ");
    scanf("%s", input);
    strcpy(input_2, input);
    int n = strlen(input);

    printf("Brute-Force Permutations:\n");
    clock_gettime(CLOCK_MONOTONIC, &start_time);
    bruteForcePermutations(input, n);
    clock_gettime(CLOCK_MONOTONIC, &end_time);
    double elapsed_time_brute = (end_time.tv_sec - start_time.tv_sec) * 1000.0 + (end_time.tv_nsec - start_time.tv_nsec) / 1e6;
    printf("Time taken by Brute-Force: %f seconds\n", elapsed_time_brute);

    printf("\nJohnson-Trotter Permutations:\n");
    clock_gettime(CLOCK_MONOTONIC, &start_time);
    johnsonTrotterPermutations(input_2, n);
    clock_gettime(CLOCK_MONOTONIC, &end_time);
    double elapsed_time_johnson = (end_time.tv_sec - start_time.tv_sec) * 1000.0 + (end_time.tv_nsec - start_time.tv_nsec) / 1e6;
    printf("Time taken by Johnson-Trotter: %f seconds\n", elapsed_time_johnson);
    double time_diff = elapsed_time_brute - elapsed_time_johnson;
    printf("\n");
    if (time_diff > 0)
    {
        printf("Brute force took more time for %f seconds\n", time_diff);
    }
    else if (time_diff < 0)
    {
        time_diff *= -1;
        printf("Brute force took less time for %f seconds\n", time_diff);
    }
    else if (time_diff == 0)
    {
        printf("Brute force took as much time as Johnson trotter's algorithm took.\n");
    }
    return 0;
}
