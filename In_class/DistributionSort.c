#include <malloc.h>
#include <limits.h>
#include <stdio.h>
#include <string.h>

void distributionSort(int arr[], int length, int l, int u, int out[]) {
    int d_arr[u - l + 1];
    int v;

    // Initialize the count array to all zeros
    for (int j = 0; j <= u - l; j++) {
        d_arr[j] = 0;
    }

    // Count the occurrences of each element
    for (int i = 0; i < length; i++) {
        v = arr[i] - l;
        d_arr[v]++;
    }

    // Calculate cumulative counts
    for (int j = 1; j <= u - l; j++) {
        d_arr[j] += d_arr[j - 1];
    }

    // Build the output array
    for (int i = length - 1; i >= 0; i--) {
        int j = arr[i] - l;
        out[d_arr[j] - 1] = arr[i];
        d_arr[j]--;
    }
}

int findMin(int *numbers, int numCount) {
    if (numCount <= 0 || numbers == NULL) {
        printf("Invalid input for findMin.\n");
        return 0; // Return a default value or handle the error appropriately
    }

    int min = numbers[0];
    for (int i = 1; i < numCount; i++) {
        if (numbers[i] < min) {
            min = numbers[i];
        }
    }
    return min;
}

int findMax(int *numbers, int numCount) {
    if (numCount <= 0 || numbers == NULL) {
        printf("Invalid input for findMax.\n");
        return 0; // Return a default value or handle the error appropriately
    }
    int max = numbers[0];
    for (int i = 1; i < numCount; i++) {
        if (numbers[i] > max) {
            max = numbers[i];
        }
    }
    return max;
}

int main() {
    int bufferSize = 10;
    char buffer[bufferSize];
    char *token;
    int *numbers = malloc(bufferSize * sizeof(int));

    printf("Input Number (leave a space between each of them, press enter when finished): ");
    fgets(buffer, bufferSize, stdin);

    if (buffer[strlen(buffer) - 1] == '\n') {
        buffer[strlen(buffer) - 1] = '\0';
    }

    token = strtok(buffer, " "); // Use space as the delimiter
    int numCount = 0;

    // Tokenizing loop
    while (token != NULL) {
        // Skip consecutive spaces
        while (*token == ' ') {
            token++;
        }

        if (*token == '\0') {
            break; // Exit if the token is empty
        }

        int num = atoi(token);
        if (numCount >= bufferSize) {
            bufferSize += 10; // Increase buffer size by 10 (for example)
            numbers = realloc(numbers, bufferSize * sizeof(int));

            if (numbers == NULL) {
                printf("Memory allocation failed.\n");
                return 1; // Exit with an error code
            }
        }
        numbers[numCount] = num;
        token = strtok(NULL, " ");
        numCount++;
        if (numCount >= 100) {
            printf("Too many numbers. Array is full.\n");
            break;
        }
    }

    int size = numCount; // Use the actual number of elements

    // Calculate the lower and upper bounds
    int lower_bound = INT_MAX;
    int upper_bound = INT_MIN;

    for (int i = 0; i < size; i++) {
        if (numbers[i] < lower_bound) {
            lower_bound = numbers[i];
        }
        if (numbers[i] > upper_bound) {
            upper_bound = numbers[i];
        }
    }

    int *out = malloc(size * sizeof(int)); // Allocate memory for the output array

    distributionSort(numbers, size, lower_bound, upper_bound, out);

    printf("Sorted array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", out[i]);
    }
    printf("\n");

    // Free dynamically allocated memory
    free(numbers);
    free(out);

    return 0;
}

