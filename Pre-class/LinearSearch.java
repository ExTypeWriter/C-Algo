import java.util.Scanner;
class LinearSearch {
    public static void main(String[] args) {
<<<<<<< HEAD
        int[] arr = { 42, 18, 17, 29, 55, 63, 91, 14, 37, 68 };
        Scanner sc = new Scanner(System.in);
        System.out.print("Input target: ");
        int search_target = sc.nextInt();
        int out = linearSearch(arr, search_target);
=======
        int[] arr = { 42, 18, 17, 55, 55, 63, 91, 14, 37, 68 };
        int out = linearSearch(arr, 22);
>>>>>>> fccf8785b855cfd4c51dc85b93b91ed4f0db3e6f
        System.out.println(out);
        if(UniqueElement(arr)){
            System.out.println("Unique Array.");
        }
        else{
            System.out.println("Not Unique Array.");
        }
    }

    private static int linearSearch(int[] arr, int n) {
        int location = 0;
        int i = 0;
        boolean found = false;
        while (i < arr.length) {
<<<<<<< HEAD
            if (arr[i] - n == 0) {
=======
            if (arr[i] == n  ) {
                System.out.println("Target found!");
>>>>>>> fccf8785b855cfd4c51dc85b93b91ed4f0db3e6f
                location = i;
                found = true;
                break;
            }
            if(arr[i] != n && i == arr.length - 1){
                System.out.println("Target not found! return first element.");
            }
            i++;
        }
        if(found == true)
        {
          System.out.println("Target found!");
          return arr[location];
        }
        else{
            System.out.println("Not found");
            return -999999;
        }
    }
    private static boolean UniqueElement(int[] arr){
        for(int i=0;i<arr.length;i++){
            for(int j=i+1;j<arr.length;j++){
                if(arr[i]==arr[j]){
                    System.out.println(String.valueOf(arr[i]) + " are duplicated!");
                    return false;
                }
            }
        }
        return true;
    }
}
