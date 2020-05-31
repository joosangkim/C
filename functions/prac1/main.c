#include<stdio.h>
#define FACTORIAL_FUCNTION_ERROR -101

int factorial(int a);
int main(void){
  int a;
  int ans;

  fputs("숫자 입력 : ",stdout);
  scanf("%d%*c",&a);

  ans = factorial(a);
  
  if (ans == FACTORIAL_FUCNTION_ERROR){
    fputs("입력이 잘못되어 프로그램 종료\n", stdout);
  }else {
    printf("%d! : %d\n", a, ans);
  }
  
  
  return 0;
}

int factorial(int a){
  int fac = 1; 
  if ( a <= 1){
    return FACTORIAL_FUCNTION_ERROR;
  }else {
    while(a > 0){
      fac *= a;
      a--;
    } 
  }
  return fac;
}
