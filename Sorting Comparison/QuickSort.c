#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int HoarePartition(int arr[], int left_most, int right_most)
{
    int pivot = arr[left_most];
    int i = left_most - 1;
    int j = right_most + 1;

    do
    {
        do
        {
            i++;
        } while (arr[i] < pivot);

        do
        {
            j--;
        } while (arr[j] > pivot);
        swap(&arr[i], &arr[j]);
    } while (i < j);
    swap(&arr[i], &arr[j]);
    swap(&arr[left_most], &arr[j]);
    return j;
}

void quickSort(int arr[], int left_most, int right_most)
{
    if (left_most < right_most)
    {
        int partitionIndex = HoarePartition(arr, left_most, right_most);
        quickSort(arr, left_most, partitionIndex);
        quickSort(arr, partitionIndex + 1, right_most);
    }
}


int main()
{
    int size;
    scanf("%d", &size);
    int array[size];
    for(int i = 0; i < size; i++)
    {
        scanf("%d", &array[i]);
    }
    quickSort(array, 0 , size-1);
}
