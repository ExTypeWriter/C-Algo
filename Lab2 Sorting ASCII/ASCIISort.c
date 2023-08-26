#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printArray(char arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%c ", arr[i]);
    }
    printf("\n");
}

void swap(char *pointer_a, char *pointer_b)
{
    char temp = *pointer_a;
    *pointer_a = *pointer_b;
    *pointer_b = temp;
}

int partition(char arr[], int leftmost_index, int rightmost_index)
{
    char pivot = arr[rightmost_index];
    int i_iter = (leftmost_index - 1);

    for (int j_iter = leftmost_index; j_iter <= rightmost_index - 1; j_iter++)
    {
        if (arr[j_iter] < pivot)
        {
            i_iter++;
            swap(&arr[i_iter], &arr[j_iter]);
        }
    }

    swap(&arr[i_iter + 1], &arr[rightmost_index]);
    return (i_iter + 1);
}

void quickSort(char arr[], int leftmost_index, int rightmost_index)
{
    int size = rightmost_index+1;
    if (leftmost_index < rightmost_index)
    {
        int pi = partition(arr, leftmost_index, rightmost_index);
        printArray(arr,size);
        quickSort(arr, leftmost_index, pi - 1);
        quickSort(arr, pi + 1, rightmost_index);
    }
}

void distributionSort(char arr[], int size)
{
    int count[256] = {0};
    char output[size];
    for (int i_iter = 0; i_iter < size; i_iter++)
    {
        count[arr[i_iter]]++;
    }
    for (int j_iter = 1; j_iter < 256; j_iter++)
    {
        count[j_iter] += count[j_iter - 1];
    }
    for (int k_iter = size - 1; k_iter >= 0; k_iter--)
    {
        printArray(output, size);
        output[count[arr[k_iter]] - 1] = arr[k_iter];
        count[arr[k_iter]]--;
    }
    printf("Orignal: ");
    printArray(arr, size);
    for (int l_iter = 0; l_iter < size; l_iter++)
    {
        arr[l_iter] = output[l_iter];
    }
}

void merge(char arr[], int left, int middle, int right)
{
    int i_iter, j_iter, k_iter;
    int n1 = middle - left + 1;
    int n2 = right - middle;
    char L[n1], R[n2];
    for (i_iter = 0; i_iter < n1; i_iter++)
    {
        L[i_iter] = arr[left + i_iter];
    }
    for (j_iter = 0; j_iter < n2; j_iter++)
    {
        R[j_iter] = arr[middle + 1 + j_iter];
    }
    i_iter = 0;
    j_iter = 0;
    k_iter = left;
    while (i_iter < n1 && j_iter < n2)
    {
        if (L[i_iter] <= R[j_iter])
        {
            arr[k_iter] = L[i_iter];
            i_iter++;
        }
        else
        {
            arr[k_iter] = R[j_iter];
            j_iter++;
        }
        k_iter++;
    }
    while (i_iter < n1)
    {
        arr[k_iter] = L[i_iter];
        i_iter++;
        k_iter++;
    }
    while (j_iter < n2)
    {
        arr[k_iter] = R[j_iter];
        j_iter++;
        k_iter++;
    }
}

void mergeSort(char arr[], int left, int right, int size)
{
    if (left < right)
    {
        int middle = left + (right - left) / 2;
        mergeSort(arr, left, middle, size);
        mergeSort(arr, middle + 1, right, size);
        merge(arr, left, middle, right);
        printArray(arr, size);
    }
}

int inputMode()
{
    char buffer[256];
    printf("Sorting By ASCII value!\n");
    printf("===============================================================\n");
    printf("Choosing mode:\n");
    printf("Quick sort mode (1)\n");
    printf("Distribution sort mode (2)\n");
    printf("Merge sort mode (3)\n");
    printf("Input mode: ");
    fgets(buffer, sizeof(buffer), stdin);
    int number = atoi(buffer);
    printf("===============================================================\n");
    switch (number)
    {
    case 1:
        return 1;
        break;
    case 2:
        return 2;
        break;
    case 3:
        return 3;
        break;
    default:
        return 0;
        break;
    }
}

int main()
{
    char KMUTT_STRING[] = {'K', 'I', 'N', 'G', 'M', 'O', 'N', 'G', 'K', 'U', 'T', 'U', 'N', 'I', 'V', 'E', 'R', 'S', 'I', 'T', 'Y'};
    int STRING_SIZE = strlen(KMUTT_STRING);
    int mode = inputMode();

    if (mode == 1)
    {
        printf("Quick sorting mode\n");
        quickSort(KMUTT_STRING, 0, STRING_SIZE - 1);
    }
    else if (mode == 2)
    {
        printf("Distribution sorting mode\n");
        distributionSort(KMUTT_STRING, STRING_SIZE);
    }
    else if (mode == 3)
    {
        printf("Merge sorting mode\n");
        mergeSort(KMUTT_STRING, 0, STRING_SIZE - 1, STRING_SIZE);
    }
    else if (mode == 0)
    {
        printf("Invalid mode input\n");
        return 0;
    }

    if (mode != 2)
    {
        printf("Original: ");
        printArray(KMUTT_STRING, STRING_SIZE);
    }
    printf("Sorted: ");
    printArray(KMUTT_STRING, STRING_SIZE);

    return 0;
}
