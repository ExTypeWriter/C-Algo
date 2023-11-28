#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>


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

void writeRandNum(FILE *file, int lower, int upper, int number_of_element, char *mode)
{
    fprintf(file, "%d\n", number_of_element);
    if (strcmp(mode, "A") == 0)
    {
        int start_num = (rand() % (upper - lower + 1)) + lower;
        for (int i = 0; i < number_of_element; i++)
        {
            fprintf(file, "%d\n", start_num + i);
        }
    }
    else if (strcmp(mode, "B") == 0)
    {
        int start_num = (rand() % (upper - lower + 1)) + lower;
        for (int i = number_of_element; i > 0; i--)
        {
            fprintf(file, "%d\n", start_num + i);
        }
    }
    else if (strcmp(mode, "C") == 0)
    {
        // Mode C: Random without duplicates
        if (number_of_element > (upper - lower + 1))
        {
            return;
        }

        bool *used = malloc((upper - lower + 1) * sizeof(bool));
        if (used == NULL)
        {
            return;
        }

        // Initialize the used array to false
        for (int i = 0; i <= upper - lower; i++)
        {
            used[i] = false;
        }

        // Generate unique random numbers
        for (int j = 0; j < number_of_element; j++)
        {
            int num;
            do
            {
                num = (rand() % (upper - lower + 1)) + lower;
            } while (used[num - lower]);

            fprintf(file, "%d\n", num);
            used[num - lower] = true;
        }
    }
    else if (strcmp(mode, "D") == 0)
    {
        // Mode D: Random with duplicates
        for (int j = 0; j < number_of_element; j++)
        {
            int num = (rand() % (upper - lower + 1)) + lower;
            fprintf(file, "%d\n", num);
        }
    }
    else if (strcmp(mode, "E") == 0)
    {
        // Mode E: All duplicates
        int num = (rand() % (upper - lower + 1)) + lower;
        for (int j = 0; j < number_of_element; j++)
        {
            fprintf(file, "%d\n", num);
        }
    }
    else if (strcmp(mode, "F") == 0)
    {
        // Mode F: Sorted Ascending Order
        int arr[number_of_element];
        for (int j = 0; j < number_of_element; j++)
        {
            int num = (rand() % (upper - lower + 1)) + lower;
            arr[j] = num;
        }
        quickSort(arr,0 , number_of_element-1);
        for (int k = 0; k < number_of_element; k++)
        {
            fprintf(file,"%d\n", arr[k]);
            k++;
        }
    }
    else if (strcmp(mode, "G") == 0)
    {
        // Mode F: Sorted Descending Order
        int arr[number_of_element];
        for (int j = 0; j < number_of_element; j++)
        {
            int num = (rand() % (upper - lower + 1)) + lower;
            arr[j] = num;
        }
        quickSort(arr,0 , number_of_element-1);
        int l = number_of_element;
        for (int k = 0; k < number_of_element; k++)
        {
            fprintf(file,"%d\n", arr[l]);
            l--;
            k++;
        }
    }
}

int main()
{
    srand(time(0));
    FILE* test_a = fopen("test_int_a.txt", "w");
    FILE* test_b = fopen("test_int_b.txt", "w");
    FILE* test_c = fopen("test_int_c.txt", "w");
    FILE* test_d = fopen("test_int_d.txt", "w");
    FILE* test_e = fopen("test_int_e.txt", "w");
    FILE* test_f = fopen("test_int_f.txt", "w");
    FILE* test_g = fopen("test_int_g.txt", "w");
    int number_of_elements = 1000;
    int lower_bound_int = -100;
    int upper_bound_int = 1000;
    // Example usage of functions
    writeRandNum(test_a, lower_bound_int, upper_bound_int, number_of_elements, "A");
    writeRandNum(test_b, lower_bound_int, upper_bound_int, number_of_elements, "B");
    writeRandNum(test_c, lower_bound_int, upper_bound_int, number_of_elements, "C");
    writeRandNum(test_d, lower_bound_int, upper_bound_int, number_of_elements, "D");
    writeRandNum(test_e, lower_bound_int, upper_bound_int, number_of_elements, "E");
    writeRandNum(test_f, lower_bound_int, upper_bound_int, number_of_elements, "F");
    writeRandNum(test_g, lower_bound_int, upper_bound_int, number_of_elements, "G");
    fclose(test_a);
    fclose(test_b);
    fclose(test_c);
    fclose(test_d);
    fclose(test_e);
    fclose(test_g);

    return 0;
}
