import java.util.Scanner;
class LinearSearch {
    public static void main(String[] args) {
        int[] arr = { 42, 18, 17, 29, 55, 63, 91, 14, 37, 68 };
        Scanner sc = new Scanner(System.in);
        System.out.print("Input target: ");
        int search_target = sc.nextInt();
        int out = linearSearch(arr, search_target);
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
            if (arr[i] - n == 0) {
                location = i;
                found = true;
                break;
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
                    return false;
                }
            }
        }
        return true;
    }
}
