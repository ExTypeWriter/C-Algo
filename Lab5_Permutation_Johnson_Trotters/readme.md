# Permutation Algorithms Comparison

This C program compares two methods for generating permutations of a given set of characters: the brute-force method and Johnson-Trotter's algorithm. It measures the execution time for each method and provides a time difference between the two methods.

## Program Structure

The program is divided into the following sections:

1. `swap`: These functions are used for swapping characters pointers.

2. `swapBool`: This functions are used to swap boolean pointers.

3. `reverse`: This function is used to reverse the string.

4. `bruteForcePermutations`: This section generates permutations using the brute-force method. It calculates `n!` (factorial) and then generates all permutations by swapping characters.

5. `findLargestMobile`:  This function is used in Johnson-Trotter's algorithm to find the largest mobile element in a given string.

6. `johnsonTrotterPermutations`: This section uses Johnson-Trotter's algorithm to generate permutations. It maintains a direction array to determine the movement of characters and swaps elements accordingly.




## Usage

1. Run the program and input a set of characters (e.g., "ABC" ,"BGH" or any letter in ascending order according to the ASCII code).

2. The program will generate permutations using both the brute-force and Johnson-Trotter methods.

3. It will measure the execution time for each method and display the results.

4. The time difference between the two methods is calculated and displayed.