import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

class LinearSearch {
    public static void main(String[] args) {
        int[] arr = { 42, 18, 17, 29, 55, 63, 91, 14, 37, 68 };
        Scanner sc = new Scanner(System.in);
        System.out.print("Input mode ( 1: modify input 2: search): ");
        int mode = SelectMode(sc);
        if (mode == 1) {
            System.out.print("Enter input size: ");
            int size = sc.nextInt();
            int[] array = new int[size];
            for (int i = 0; i < size; i++) {
                System.out.print("Enter element " + (i + 1) + " : ");
                array[i] = sc.nextInt();
            }
            arr = array;
        }
        System.out.print("Input target: ");
        int search_target = sc.nextInt();
        linearSearch(arr, search_target);
        PrintArray(arr);
        if (UniqueElement(arr)) {
            System.out.println("Current input array is unique array.");
        } else {
            System.out.println("Current input array is not unique array.");
        }
        sc.close();
    }

    private static int linearSearch(int[] arr, int n) {
        int location = 0;
        int i = 0;
        boolean found = false;
        while (i < arr.length) {
            if (arr[i] == n) {
                location = i;
                found = true;
                break;
            }
            if (arr[i] != n && i == arr.length - 1) {
                System.out.println("Target not found!");
            }
            i++;
        }
        if (found == true) {
            System.out.println("Target "+ arr[location] +" founded!");
            return arr[location];
        } else {
            return -999999;
        }
    }

    private static boolean UniqueElement(int[] arr) {
        Set<Integer> uniqueElements = new HashSet<>();
        Set<Integer> duplicateElements = new HashSet<>();

        for (int num : arr) {
            if (!uniqueElements.add(num)) {
                duplicateElements.add(num);
            }
        }
        if (!duplicateElements.isEmpty()) {
            System.out.print("Duplicates: ");
            boolean isFirst = true;
            for (int num : duplicateElements) {
                if (!isFirst) {
                    System.out.print(",");
                }
                System.out.print(num);
                isFirst = false;
            }
            System.out.println(" are duplicated!");
            return false;
        }
        return true;
    }

    public static void PrintArray(int[] arr) {
        System.out.print("Current input array : ");
        for (int i = 0; i < arr.length; i++) {
            System.out.print(arr[i] + " ");
        }
        System.out.println("");
    }

    public static int SelectMode(Scanner scanner) {
        int mode = scanner.nextInt();
        int selected_mode = (mode == 1) ? 1 : 0;
        return selected_mode;
    }
}
