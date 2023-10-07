# Quickselect Program

This C program implements the Quickselect algorithm to find the kth smallest element in an array. The user can choose a partitioning algorithm between Lomuto partitioning and Hoare partitioning. It also shows the time used in each execution for the user to compare the execute-time difference between these two partitioning methods.

## Program Structure

The program consists of several functions:

1. `swap`: Swaps two integers using pointers.
2. `printArray`: Prints the elements of an array.
3. `saveArrayToFile`: Saves the array elements to a file.
4. `isInteger`: Checks if a string represents an integer.
5. `clearScreen`: Clears the terminal screen.
6. `flushInputBuffer`: Flushes newline characters from the input buffer.
7. `checkValidInput`: Prompts the user for valid integer input.
8. `enterToContinue`: Waits for the user to press Enter to continue.
9. `delay`: Introduces a delay for a specified number of seconds.
10. `lomuto_partition`: Implements Lomuto's partitioning scheme.
11. `hoare_partition`: Implements Hoare's partitioning scheme.
12. `quickselect`: Finds the kth smallest element using Quickselect.

The main function (`main`) is where the program's functionality is implemented. It allows the user to edit the array, choose a partitioning mode (Lomuto or Hoare), and find the k<sup>th</sup> smallest element. The program also measures the time taken for the selection process and displays the result.

## Usage

1. The program loads the array from a file called "array.txt" at startup. If the file does not exist or is empty, it initializes the array with a default set of values.

2. The user can choose from the following options:
   - Edit array: Allows the user to input a new array with specified size of an array.
   - Show Kth Smallest: Prompts the user to select a partitioning mode (Lomuto or Hoare) and input the value of k to find the k<sup>th</sup> smallest element.
   - Exit: Exits the program.

3. When the "Show Kth Smallest" option is chosen, the program:
   - Displays the current array.
   - Prompts the user for the partitioning mode.
   - Prompts the user for the value of k.
   - Measures the time taken to find the k<sup>th</sup> smallest element using `quickselect`.
   - Displays the result or informs the user if the input is out of bounds.

4. After each option, the program waits for the user to press `Enter` to continue.

5. The program can be exited by choosing the "Exit" option in the menu.
