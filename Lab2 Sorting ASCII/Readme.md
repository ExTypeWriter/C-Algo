# Sorting by ASCII with different algorithms

C-Program that demonstrates sorting algorithms to sort characters in given string in ascending order with different sorting algorithms including quick sorting, distribution sorting, and merge sorting. 

## Sorting Algorithms

### Quick Sort ( `quickSort` )

The quicksort with the divide-and-conquer approach.

### Distribution Sort ( `distributionSort` )

The distribution sort algorithm counts the occurrences of each character and rearranges the characters in ascending order based on their ASCII values.

### Merge Sort ( `mergeSort` )

The merge sort algorithm divides the array into smaller subarrays, sorts them, and then merges them back together to form a sorted array.

## Main Function ( `main` )

1. A character array `KMUTT_STRING` is defined, containing the characters to be sorted.

2. The `inputMode` function is called to allow the user to choose a sorting mode (quicksort, distribution sort, or merge sort).

3. Depending on the chosen mode:
   - If quicksort mode is selected (`1`):
     - The `quickSort` function is called to sort the `KMUTT_STRING` array using the quicksort algorithm.
   - If distribution sort mode is selected (`2`):
     - The `distributionSort` function is called to sort the `KMUTT_STRING` array using the distribution sort algorithm.
   - If merge sort mode is selected (`3`):
     - The `mergeSort` function is called to sort the `KMUTT_STRING` array using the merge sort algorithm.

4. After sorting, the original and sorted arrays are printed to the console.

## Additional Functions

- `swap`: Swaps two characters in the array.
- `partition`: Part of the quicksort algorithm. Returns the partition index.
- `inputMode`: Takes user input to choose the sorting mode.
- `merge`: component for `mergeSort` to performs the merging of two subarrays to create a sorted array. The function compares elements from both subarrays and merges them into a single sorted array.
- `printArray`: function for printing arrays.

## Program manual

1. Compile and run the C program using a C compiler ( `gcc` , `clang` etc ).
2. Choose a sorting mode by number (quicksort, distribution sort, or merge sort).
3. The program will output the original and sorted arrays based on the chosen mode.