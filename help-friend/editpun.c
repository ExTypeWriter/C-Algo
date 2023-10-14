#include <stdio.h>
#include <string.h>

int leveshtein(char *str1, char *str2){
  int i = strlen(str1);
  int j = strlen(str2);
  int count = 0;

  while(i >= 0 && j >= 0){
    if(strcmp(&str1[i], &str2[j]) == 0) //ตัวเหมือน -> เลื่อน pointer + ลบทิ้ง
    {
      str1[i] = '\0';
      str2[j] = '\0';
      i--;
      j--;
    } 
    else { //ตัวไม่เหมือน -> count++ / เลื่อน pointer มาด้านหน้าตามเงื่อนไข
      if(i == j)
      { //len เท่า -> ลบได้เลย
        str1[i] = '\0';
        str2[j] = '\0';
        i--;
        j--;
      } 
      else { //len ไม่เท่า -> ลบ string ที่ยาวกว่า
        if(strlen(str1) > strlen(str2)){
          str1[i] = '\0';
          i--;
        } else if(strlen(str1) < strlen(str2)){
          str2[j] = '\0';
          j--;
        }
      }
      count++;
    }
  }

  return count;
}

int main() {
  char str1[50];
  char str2[50];

  scanf("%s", str1);
  scanf("%s", str2);

  if(strlen(str1) > 50 || strlen(str2) > 50){
    return 0;
  } else if(strlen(str1) < 1 || strlen(str2) < 1){
    return 0;
  }

  if(str1[strlen(str1) - 1] == '\n'){
    str1[strlen(str1) - 1] = '\0';
  } else if(str2[strlen(str2) - 1] == '\n'){
    str2[strlen(str2) - 1] = '\0';
  }
  //printf("%s %s", str1, str2);

  int distance = leveshtein(str1, str2);
  printf("%d", distance);
  
  return 0;
}