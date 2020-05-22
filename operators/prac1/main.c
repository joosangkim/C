#include<stdio.h>
#define PI 3.14

int main(void){
  /* Basic */
  double a, b;
  /* Calc*/
  double r;

  /* Basic */
  fputs("두 개의 실수 입력: ", stdout);
  scanf("%lf %lf", &a, &b);
  printf("Sum: %lf\n", a+b);
  printf("Minus: %lf\n", a-b);
  printf("Multiple: %lf\n", a*b);
  printf("Div: %lf\n", a/b);

  /* Calc */
  fputs("반지름 입력: ", stdout);
  scanf("%lf", &r);
  printf("원의 넓이: %lf\n", r * r * PI);

  return 0;
  
}
