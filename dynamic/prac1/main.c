#include<stdio.h>
#include<stdlib.h>
void ReadAndSortPrint(int number);

int main(void){

  int num;
  fputs("입력할 정수의 갯수: ", stdout);
  scanf("%d", &num);

  ReadAndSortPrint(num);
  return 0;
}

void ReadAndSortPrint(int number){

  /*
  int arr[number];
  int i ;
  */
  int* arr;
  int i ;
  arr = (int*)malloc(sizeof(int)*number);
  
  for(i = 0; i < number; i++){
    printf("%d 번째 입력 : ", i+1);
    scanf("%d", &arr[i]);
  }
  for(i = 0; i<number; i++){
    printf("%d ",arr[i]);
  }
  printf("\n");
  free(arr);
}
