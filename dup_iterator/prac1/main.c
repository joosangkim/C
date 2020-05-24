#include<stdio.h>
#define ARR_LEN 5

int main(void){
  int arr[ARR_LEN];
  int i, j, t;

  for (i = 0; i < ARR_LEN; i++){
    printf("숫자 %d 입력 :", i + 1);
    scanf("%d%*c", &arr[i]);
  }

  /* BUBBLE START */
  for(i = ARR_LEN-1  ; i >= 0; i--){
    for ( j = 0; j < i ; j++){
      if(arr[j] > arr[j+1]){
        t = arr[j+1];
        arr[j+1] = arr[j];
        arr[j]=t;
      }
    }
  }


  for (i = 0; i < ARR_LEN; i++){
    printf("%d\n", arr[i]);
  }

  return 0;
  
}
