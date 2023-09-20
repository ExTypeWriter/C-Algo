import java.util.Scanner;
class LinearSearch {
    public static void main(String[] args) {
        int []arr = { 42, 18, 17, 29, 55, 63, 91, 14, 37, 68 };
        Scanner sc = new Scanner(System.in);
        System.out.print("Input mode ( 1: modify input 2: search): ");
        int mode = SelectMode();
        if(mode == 1){
          System.out.print("Enter input size: ");
          int size = sc.nextInt();
          int []array = new int[size];
          for(int i = 0 ; i<size; i++)
          {
            System.out.print("Enter element "+(i+1)+" : ");
            array[i] = sc.nextInt();
          }
          arr = array;
          PrintArray(arr);
        }
          System.out.print("Input target: ");
          int search_target = sc.nextInt();
          int out = linearSearch(arr, search_target);
          System.out.println(out);
          PrintArray(arr);
          if(UniqueElement(arr)){
             System.out.println("Current input array is unique array.");
          }
          else{
              System.out.println("Current input array is not unique array.");
          }
    }

    private static int linearSearch(int[] arr, int n) {
        int location = 0;
        int i = 0;
        boolean found = false;
        while (i < arr.length) {
            if (arr[i] == n  ) {
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
    public static void PrintArray(int[]arr){
      System.out.print("Current input array : ");
      for(int i = 0; i < arr.length; i++)
      {
        System.out.print(arr[i]+" ");
      }
      System.out.println("");
    }
    public static int SelectMode() 
    {
        Scanner sc = new Scanner(System.in);
        int mode = sc.nextInt();
        int selected_mode = (mode == 1) ? 1 : 0;
        return selected_mode;
    }  
}
