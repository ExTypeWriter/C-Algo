#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void displayArr(int *arr, int size)
{
    int i = 0;
    while (i < size)
    {
        printf("%d ", arr[i]);
        i++;
    }
    printf("\n");
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(int *arr, int size)
{
    int i = 0;
    while (i < size - 1)
    {
        int j = 0;
        while (j < (size - i - 1))
        {
            if (arr[j] > arr[j + 1])
            {
                swap(&arr[j], &arr[j + 1]);
                printf("current i = %d , j = %d : ", i, j);
                displayArr(arr, size);
            }
            j++;
            printf("current i = %d , j = %d : ", i, j);
            displayArr(arr, size);
        }
        i++;
    }
}

void insertionSort(int *arr, int size)
{
    for (int i = 1; i < size; i++)
    {
        int j = i - 1;
        while (j >= 0)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(&arr[j], &arr[j + 1]);
                printf("current i = %d , j = %d : ", i, j);
                displayArr(arr, size);
            }
            j--;
        }
        printf("current i = %d , j = %d : ", i, j);
        displayArr(arr, size);
    }
}

void selectionSort(int *arr, int size)
{
    int i = 0;
    while (i < size - 1)
    {
        int min = i;
        int j = i + 1;
        while (j < size)
        {
            if (arr[j] < arr[min])
            {
                min = j;
            }
            printf("current i = %d , j = %d : ", i, j);
            displayArr(arr, size);
            j++;
        }
        swap(&arr[i], &arr[min]);
        printf("current i = %d , j = %d : ", i, j);
        displayArr(arr, size);
        i++;
    }
}


void merge(int A[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    // Create temp arrays
    int Left_temp[n1], Right_temp[n2];

    // Copy data to temp arrays L[] and R[]
    for (i = 0; i < n1; i++)
        Left_temp[i] = A[l + i];
    for (j = 0; j < n2; j++)
        Right_temp[j] = A[m + 1 + j];

    // Merge the temp arrays back into arr[l..r]
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (Left_temp[i] <= Right_temp[j])
        {
            A[k] = Left_temp[i];
            i++;
        }
        else
        {
            A[k] = Right_temp[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of L[],
    // if there are any
    while (i < n1)
    {
        A[k] = Left_temp[i];
        i++;
        k++;
    }

    // Copy the remaining elements of R[],
    // if there are any
    while (j < n2)
    {
        A[k] = Right_temp[j];
        j++;
        k++;
    }
}

// l is for left index and r is right index of the
// sub-array of arr to be sorted
void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;

        // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

int HoarePartition(int arr[], int left_most, int right_most) {
    int pivot = arr[left_most];
    int i = left_most - 1;
    int j = right_most + 1;

    do {
        do {
            i++;
        } while (arr[i] < pivot);

        do {
            j--;
        } while (arr[j] > pivot);
        swap(&arr[i], &arr[j]);
    } while(i<j);
    swap(&arr[i], &arr[j]);
    swap(&arr[left_most],&arr[j]);
    return j;
}

void quickSort(int arr[], int left_most, int right_most) {
    if (left_most < right_most) {
        int partitionIndex = HoarePartition(arr, left_most, right_most);
        quickSort(arr, left_most, partitionIndex);
        quickSort(arr, partitionIndex + 1, right_most);
    }
}

int main()
{
    int array[] = {4, 9, 5, 21, 1, 999, -20};
    int size = sizeof(array) / sizeof(array[0]);
    int *temp1 = malloc(size * sizeof(int));
    memcpy(temp1, array, size * sizeof(int));
    int *temp2 = malloc(size * sizeof(int));
    memcpy(temp2, array, size * sizeof(int));
    int *temp3 = malloc(size * sizeof(int));
    memcpy(temp3, array, size * sizeof(int));
    int *temp4 = malloc(size * sizeof(int));
    memcpy(temp4, array, size * sizeof(int));
    printf("Bubble sort before : ");
    displayArr(array, size);
    bubbleSort(array, size);
    printf("Bubble sort after : ");
    displayArr(array, size);
    printf("Insertion sort before : ");
    displayArr(temp1, size);
    insertionSort(temp1, size);
    printf("Insertion sort after : ");
    displayArr(temp1, size);
    printf("Selection sort before : ");
    displayArr(temp2, size);
    selectionSort(temp2, size);
    printf("Selection sort after : ");
    displayArr(temp2, size);
    printf("Merge sort before : ");
    displayArr(temp3, size);
    selectionSort(temp3, size);
    printf("Merge sort after : ");
    displayArr(temp3, size);
    printf("Quick sort before : ");
    displayArr(temp4, size);
    quickSort(temp4, 0,size-1);
    printf("Quick sort after : ");
    displayArr(temp4, size);
}