#include<stdio.h>


int arrSum(int *arr, const int rows, const int cols);

int main(void){
  int arr1[2][2] = {{1, 3}, {5, 7}};
  int arr2[2][3] = {{1, 2, 3}, {4, 5, 6}};
  int sum = 0;
  int r, c;

  r = (int)sizeof(arr1)/sizeof(int);
  c = (int)sizeof(*arr1)/sizeof(int);
  printf("Sum: %d\n", sum);
  sum += arrSum(*arr1, r, c);

  r = (int)sizeof(arr1)/sizeof(int);
  c = (int)sizeof(*arr1)/sizeof(int);
  sum += arrSum(*arr2, r, c);
  
  printf("Sum: %d\n", sum);

  return 0;
}

int arrSum(int *arr, const int rows, const int cols){
  int i, j;
  int sum = 0;

  for(i = 0; i < rows ; ++i){
    for(j = 0; j < cols ; ++j){
      sum += arr[i][j];
    } 
  }
  
  return sum;
}
