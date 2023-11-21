#include <stdio.h>

void display(int A[], int size)
{
    for(int i = 0; i < size; i++)
    {
        printf("%d ", A[i]);
    }
}

void merge(int A[], int l, int m, int r)
{
    int n1 = m - l + 1;
    int n2 = r - m;

    // Create temp arrays
    int Left_temp[n1], Right_temp[n2];

    // Copy data to temp arrays L[] and R[]
    for (int i = 0; i < n1; i++)
    {
        Left_temp[i] = A[l + i];
    }
    for (int j = 0; j < n2; j++)
    {
        Right_temp[j] = A[m + 1 + j];
    }

    // Merge the temp arrays back into arr[l..r]
    int i = 0;
    int j = 0;
    int k = l;
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

int main()
{
    int size;
    scanf("%d", &size);
    int array[size];
    for(int i = 0; i < size; i++)
    {
        scanf("%d", &array[i]);
    }
    mergeSort(array, 0 , size-1);
}