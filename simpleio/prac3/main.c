#include<stdio.h>

int main(void){
  int a, b, sum;

  fputs("두 수를 16진수로 입력 : ",stdout);
  scanf("%x %x%*c", &a, &b);
  sum = a + b;
  printf("연산결과 8진수: %o\n", sum);
  printf("연산결과 10진수: %d\n", sum);
  printf("연산결과 16진수: %x\n", sum);

  return 0;
}
