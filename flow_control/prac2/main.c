#include<stdio.h>

int main(void){
  int a, b;
  int i ;
  int sum = 0;
  fputs("두 개의 정수를 입력: ",stdout);
  scanf("%d %d",&a, &b);

  
  for ( i = (a < b? a : b); i <= (a < b? b : a); i++){
    sum += i;
  }

  printf("%d와 %d를 포함한 정수 합 : %d\n", a, b, sum);

  return 0;
}
