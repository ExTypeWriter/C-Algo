#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define OUT_OF_BOUND -1

void swap(int *p_a, int *p_b)
{
    int p_temp = *p_a;
    *p_a = *p_b;
    *p_b = p_temp;
}

int lomuto_partition(int arr[], int left, int right)
{
    int pivot = arr[right];
    int i = left;

    for (int j = left; j < right; j++)
    {
        if (arr[j] <= pivot)
        {
            swap(&arr[i], &arr[j]);
            i++;
        }
    }
    swap(&arr[i], &arr[right]);
    return i;
}

int quickselect(int arr[], int left, int right, int k_ind)
{
    if (left < right)
    {
        int pivotIndex = lomuto_partition(arr, left, right);

        if (pivotIndex == k_ind - 1)
            return arr[pivotIndex];

        if (pivotIndex < k_ind - 1)
            return quickselect(arr, pivotIndex + 1, right, k_ind);

        return quickselect(arr, left, pivotIndex - 1, k_ind);
    }
    return OUT_OF_BOUND;
}

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void saveArrayToFile(int arr[], int size, const char *filename)
{
    FILE *file = fopen(filename, "w");
    if (file == NULL)
    {
        printf("Error opening file.\n");
        return;
    }

    for (int i = 0; i < size; i++)
    {
        fprintf(file, "%d ", arr[i]);
    }

    fclose(file);
}

bool isInteger(char *str)
{
    if (str == NULL || str[0] == '\0')
        return false;

    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] < '0' || str[i] > '9')
            return false;
    }

    return true;
}

int main()
{
    int edit_array = 1;
    int show_kth_smallest = 2;
    int exit = 3;
    int arr[100];
    int n = 0;
    int userChoice;
    char userInput[20];

    FILE *file = fopen("array.txt", "r");
    if (file != NULL)
    {
        // Read the array from the file
        while (fscanf(file, "%d", &arr[n]) == 1)
        {
            n++;
        }
        fclose(file);
    }

    do
    {
        printf("----------------------------------------------------------------\n");
        printf("Menu:\n");
        printf("1. Edit array\n");
        printf("2. Show Kth Smallest\n");
        printf("3. Exit\n");
        printf("----------------------------------------------------------------\n");
        printf("Enter your choice: ");
        scanf("%d", &userChoice);

        if (userChoice == edit_array)
        {
            int new_n = 0;
            printf("Enter number of elements in the new array: ");
            if (scanf("%d", &new_n) == 1 && new_n >= 0 && new_n <= 100)
            {
                n = new_n;
                printf("Enter new values for the array:\n");
                for (int i = 0; i < n; i++)
                {
                    printf("Enter value for element %d: ", i + 1);
                    scanf("%s", userInput);
                    while (!isInteger(userInput) || atoi(userInput) <= 0)
                    {
                        printf("Invalid input. Please enter a positive integer: ");
                        scanf("%s", userInput);
                    }

                    arr[i] = atoi(userInput);
                }
                saveArrayToFile(arr, n, "array.txt");
            }
            else
            {
                printf("Invalid number of elements. Please enter a non-negative integer between 0 and 100.\n");
            }
        }
        else if (userChoice == show_kth_smallest)
        {
            printf("Current array: ");
            printArray(arr, n);

            int k;
            printf("Enter kth value: ");
            scanf("%s", userInput);
            while (!isInteger(userInput) || atoi(userInput) <= 0 || atoi(userInput) > n)
            {
                printf("Invalid input. Please enter a positive integer between 1 and %d: ", n);
                scanf("%s", userInput);
            }

            k = atoi(userInput);
            int result = quickselect(arr, 0, n - 1, k);

            if (result != OUT_OF_BOUND)
            {
                printf("The %dth smallest is %d.\n", k, result);
            }
        }
    } while (userChoice != exit);

    return 0;
}