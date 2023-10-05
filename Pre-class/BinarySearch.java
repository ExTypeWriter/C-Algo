import java.util.Scanner;
import java.lang.Math;
class BinarySearch
{
  public static void main(String agrs[])
  {
    System.out.println("This is Binary Search in java ( not support duplicate target)");
    Scanner scan = new Scanner(System.in);
    int []array = {1,3,4,2,9,10};
    System.out.print("Currnet Array : ");
    printArray(array);
    System.out.print("Input target : ");
    int target = scan.nextInt();
    int found = 0;
    System.out.print("Select mode ( 1 for BinarySearch and 2 for QuickSelectSmallest) : ");
    int mode = scan.nextInt();
    if(mode == 1)
    {
      found = BinarySearch(array,target);
      if(found!= -1){
        System.out.println("Target found at index of "+(found+1)+" of the array!");
      }
      else
      {
        System.out.println("Target not found");
      }
    }
    else if(mode == 2)
    {
      found = QuickSelectSmallest(array,0,array.length-1,target);
      System.out.println("The Kth smallest of array is : "+array[found]);
    }
    //System.out.println("Found is "+found);
    scan.close();
  }
  public static int BinarySearch(int []Array,int Key)
  {
    int left = 0;
    int right = Array.length - 1;
    while(left<=right)
    {
      int middle = (int)Math.floor((left+right)/2);
      if(Key == Array[middle])
      {
          return middle;
      }
      else if(Key < Array[middle])
      {
        right = middle-1;
      }
      else
      {
        left = middle+1;
      }
    }
    return -1;
  }
  public static int Lomu_part(int []A , int left , int right)
  {
    int pivot = A[left];
    int s = left;
    for(int i = left + 1; i < right;  i++ )
    {
      if(A[i] < pivot)
      {
        s++;
      }
    }
    swap(A,left,s);
    return s;
  }
  public static int QuickSelectSmallest(int[] A, int left, int right, int K) 
  { 
    int pivotIndex = Lomu_part(A, left, right);
    
    if (pivotIndex == K -1) {
        return A[pivotIndex];
    } else if (pivotIndex > left+K-1) {
        return QuickSelectSmallest(A, left, pivotIndex-1, K); // Adjust pivotIndex here
    } else {
        return QuickSelectSmallest(A, pivotIndex + 1, right, K-1-pivotIndex);
    }
  }

  public static void swap(int []A,int a , int b)
  {
    int temp = A[a];
    A[a] = A[b];
    A[b] = temp;
  }

  public static void printArray(int []A)
  {
      for(int i = 0 ; i < A.length ; i ++)
      {
        System.out.print(A[i] + " ");
      }
      System.out.println("");
  }
}
