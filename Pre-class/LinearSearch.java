class LinearSearch {
    public static void main(String[] args) {
        int[] arr = { 42, 18, 17, 29, 55, 63, 91, 14, 37, 68 };
        int out = linearSearch(arr, 1);
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
        while (i < arr.length) {
            if (arr[i] - n == 0) {
                System.out.println("Target found!");
                location = i;
                break;
            }
            i++;
        }
        return arr[location];
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