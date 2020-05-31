#include<stdio.h>


int arrSum(int *arr, const int len);

int main(void){
  int arr1[3] = {5, 10 ,15};
  int arr2[5] = {1, 2, 3, 4, 5};
  int sum = 0;
  sum = arrSum(arr1, (int)sizeof(arr1)/sizeof(int)) + arrSum(arr2, (int)sizeof(arr2)/sizeof(int));
  printf("Sum: %d\n", sum);

  return 0;
}

int arrSum(int *arr, const int len){
  int i = 0;
  int sum = 0;

  for(i = 0; i < len ; ++i){
    sum += arr[i];
  }
  
  return sum;
}
