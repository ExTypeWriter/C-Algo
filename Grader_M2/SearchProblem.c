#include <stdio.h>
#include <stdlib.h>
// Linear search that will return index of target in target array and return -1 when not found. ##Time out O(n)
int LinSearch(int target, int size, int *arr)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == target)
        {
            return i;
        }
    }
    return -1;
}

// Binary search return the index of the target and return -1 when not found.
int BinSearch(int target, int size, int *arr)
{
    int begin = 0;
    int end = size - 1;
    int result = -1;
    while (begin < end)
    {
        int middle = (begin + end) / 2;
        if (arr[middle] == target)
        {
            begin = middle + 1;
            result = middle;
        }
        else
        {
            end = middle - 1;
        }
    }
    return result;
}

int main()
{
    int size_of_array = 0;
    int number_of_target = 0;
    // Get array and target list size.
    scanf("%d", &size_of_array);
    scanf("%d", &number_of_target);
    // Allocate memory for array.
    int *array = malloc(sizeof(int) * size_of_array); // Get array element.
    for (int i = 0; i < size_of_array; i++)
    {
        scanf("%d", &array[i]);
    }
    // Allocate memory for target list.
    int *target_list = malloc(sizeof(int) * number_of_target);
    // Get target list.
    for (int j = 0; j < number_of_target; j++)
    {
        scanf("%d", &target_list[j]);
    }
    // Linear search through array for each target.
    for (int m = 0; m < number_of_target; m++)
    {
        printf("%d\n", BinSearch(target_list[m], size_of_array, array));
    }
    return 0;
}
