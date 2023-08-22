class LinearSearch {
    public static void main(String[] args) {
        int[] arr = { 42, 18, 76, 29, 55, 63, 91, 14, 37, 68 };
        int out = linearSearch(arr, 1);
        System.out.println(out);
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
        if(arr[i] - n != 0) {
            System.out.println("Target not found! return the first index element.");
        }

        return arr[location];
    }
}