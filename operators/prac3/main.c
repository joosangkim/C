#include<stdio.h>

int main(void){
  int a, b, c;

  fputs("두 수를 입력 : ",stdout);
  scanf("%d %d%*c", &a, &b);
  printf("큰 수는 : %d\n", (a > b ? a : b));

  fputs("세 수를 입력 : ",stdout);
  scanf("%d %d %d%*c", &a, &b, &c);
  printf("큰 수는 : %d\n", (a > b ? (a > c ? a : c) : ( b > c ? b : c)));
  
  return 0;
}
