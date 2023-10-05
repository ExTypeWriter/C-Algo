#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <unistd.h>

#define OUT_OF_BOUND -1
#define LOMUTO_MODE -2
#define HOARE_MODE -3

void swap(int *p_a, int *p_b);
void printArray(int arr[], int size);
void saveArrayToFile(int arr[], int size, const char *filename);
bool isInteger(char *str);
// Lomuto's partitioning
int lomuto_partition(int arr[], int left, int right) {
    int pivot = arr[left];
    int i = left;

    for (int j = left + 1; j <= right; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[left], &arr[i]);
    return i;
}
// Hoare's partitioning
int hoare_partition(int arr[], int left, int right);
// FInd Kth smallest
int quickselect(int arr[], int left, int right, int k_ind, int part_mode) {
    if (k_ind < 1 || k_ind > right + 1) {
        return OUT_OF_BOUND;
    }

    if (left < right) {
        int pivotIndex;

        if (part_mode == LOMUTO_MODE) {
            pivotIndex = lomuto_partition(arr, left, right);
        } else if (part_mode == HOARE_MODE) {
            pivotIndex = hoare_partition(arr, left, right);
        }

        if (pivotIndex == k_ind - 1) {
            return arr[pivotIndex];
        }

        if (pivotIndex < k_ind - 1) {
            return quickselect(arr, pivotIndex + 1, right, k_ind, part_mode);
        }

        if (k_ind == 1) {
            return arr[left];
        }

        if (k_ind == (right + 1)) {
            return arr[right];
        }

        return quickselect(arr, left, pivotIndex - 1, k_ind, part_mode);
    }

    // Handle the case when left == right
    return arr[left];
}
void flushInputBuffer(); 
int checkValidInput(char *label, char *string);
void clearScreen();
void enterToContinue();
void delay(int seconds);
int main()
{
    int edit_array = 1;
    int show_kth_smallest = 2;
    int exit = 3;
    int arr[100];
    int original_arr[100];
    int userChoice;
    char userInput[20];
    char modeInput[20];
    char selection[20];

    FILE *file = fopen("array.txt", "r");
    int n = 0;

    if (file == NULL)
    {
        int array[] = {1, 4, 3, 5, 2, 6};
        saveArrayToFile(array, sizeof(array) / sizeof(array[0]), "array.txt");
        printf("Default array loaded\n");
        file = fopen("array.txt", "r");
    }

    // Read the array from the file
    while (fscanf(file, "%d", &arr[n]) == 1)
    {
        n++;
    }
    fclose(file);

    do
    {
        printf("----------------------------------------------------------------\n");
        printf("Current array: ");
        printArray(arr, n);
        printf("Menu:\n");
        printf("1. Edit array\n");
        printf("2. Show Kth Smallest\n");
        printf("3. Exit\n");
        printf("----------------------------------------------------------------\n");
        userChoice = checkValidInput("Enter your choice: ", selection);

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
            clearScreen();
        }
        else if (userChoice == show_kth_smallest)
        {
            int mode;
            printf("Enter partition mode (Lomuto -> -2 or Hoare -> -3): ");
            scanf("%s", modeInput);
            while (atoi(modeInput) != LOMUTO_MODE && atoi(modeInput) != HOARE_MODE)
            {
                flushInputBuffer();
                printf("-2 for Lomuto partition , -3 for Hoare partition please try again. : ");
                scanf("%s", modeInput);
            }

            mode = atoi(modeInput);
            printf("Current array: ");
            printArray(arr, n);

            int k = checkValidInput("Enter Kth value: ", userInput);

            for (int i = 0; i < n; i++)
            {
                original_arr[i] = arr[i];
            }
            saveArrayToFile(original_arr, n, "array.txt");
            // Start timer
            struct timespec start_time, end_time;
            clock_gettime(CLOCK_MONOTONIC, &start_time);
            int result = quickselect(original_arr, 0, n - 1, k, mode);
            // Stop timer
            clock_gettime(CLOCK_MONOTONIC, &end_time);
            double elapsed_time = (end_time.tv_sec - start_time.tv_sec) * 1000.0 + (end_time.tv_nsec - start_time.tv_nsec) / 1e6;
            if (result != OUT_OF_BOUND)
            {
                printf("The %dth smallest is %d.\n", k, result);
            }
            else
            {
                printf("The k input is out of bound no element returned.\n");
            }
            printf("Finished in %lf s\n", elapsed_time);
            enterToContinue();
        }
    } while (userChoice != exit);
    clearScreen();
    printf("Exit now...\n");
    delay(1);
    clearScreen();
    return 0;
}
// Swap two pointer.
void swap(int *p_a, int *p_b)
{
    int p_temp = *p_a;
    *p_a = *p_b;
    *p_b = p_temp;
}
// Print out array elements
void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
// Save array elements to file.
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
// Check if str is integer or not.
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
// Clear terminal screen
void clearScreen()
{
#ifdef _WIN32
    system("cls"); // For Windows
#else
    system("clear"); // For Linux / MacOS
#endif
}
// Function to flush "\n" out of buffer.
void flushInputBuffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
}
// Check if input is integer then return the int form of the string.
int checkValidInput(char *label, char *string)
{
    printf("%s", label);
    scanf("%s", string);
    while (!isInteger(string))
    {
        flushInputBuffer();
        printf("Invalid input. Please enter integer : ");
        scanf("%s", string);
    }
    return atoi(string);
}
// Enter to continue process.
void enterToContinue()
{
    printf("Press Enter to continue...");
    flushInputBuffer();
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
    clearScreen();
}

void delay(int seconds)
{
    clock_t start_time = clock();
    while ((clock() - start_time) / CLOCKS_PER_SEC < seconds)
        ;
}

int hoare_partition(int arr[], int left, int right)
{
    int pivot = arr[left];
    int i = left - 1;
    int j = right + 1;

    while (1) {
        do {
            i++;
        } while (arr[i] < pivot);

        do {
            j--;
        } while (arr[j] > pivot);

        if (i >= j) {
            return j;
        }

        swap(&arr[i], &arr[j]);
    }
}
