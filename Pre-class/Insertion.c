#include <stdio.h>

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void displayArray(int *array, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}

void insertionSort(int *array, int size) // 28-29ms
{
    for (int i = 1; i < size; i++)
    {
        int key = array[i];
        for (int j = i - 1; j >= 0 && array[j] > key; j--)
        {
            swap(&array[j], &array[j + 1]);
        }
    }
}

void insertionSort_BinSearch(int *array, int size) // 8-31ms
{
    for (int i = 1; i < size; i++)
    {
        int key = array[i];
        int left = 0;
        int right = i - 1;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (array[mid] > key)
            {
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }
        for (int j = i; j > left; j--)
        {
            array[j] = array[j - 1];
        }
        array[left] = key;
    }
}

int main()
{
    int array[] = {3, 2, 1, 7, 4, 9, 5, 6, 8, 10};
    int size = sizeof(array) / sizeof(array[0]);
    printf("Before sort: ");
    displayArray(array, size);
    // insertionSort(array, size);
    insertionSort_BinSearch(array, size);
    printf("After sort: ");
    displayArray(array, size);
}