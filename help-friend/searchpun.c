#include<stdio.h>
#include<stdlib.h>

int main(){
  int n, k;

  scanf("%d", &n);
  scanf("%d", &k);

  if(n <= 1 || n > 100000 || k <= 1 || k > 20000){
    return 0;
  }

  int *arr = malloc(sizeof(int) * n);
  int *target = malloc(sizeof(int) * k);
  for(int i = 0; i < n; i++){
    scanf("%d", &arr[i]);
    //printf("%d\n", arr[i]);
  }
  for(int j = 0; j < k; j++){
    scanf("%d", &target[j]);
    //printf("%d\n", target[j]);
  }

  for(int i = 0; i < k; i++)
  {
    for(int j = 0; j < n; j++)
    {
      if(arr[j] == target[i]){ //found element
        printf("%d\n", j);
      } else if(arr[j] != target[i] && j == n){ //not found
        printf("-1\n");
      }
    }
  }
  
  return 0;
}