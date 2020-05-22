#include<stdio.h>
int sum(int, int);
int main(void){
  int n ;
  int s;

  while(1){
    fputs("1 이상의 정수를 입력 : ", stdout);
    scanf("%d%*c", &n);

    if ( n < 1){
      fputs("1 이상의 정수를 입력해야 합니다.\n", stdout);
    }else {
      s = sum(n, 0);
      break;
    } 
  } 

  printf("%d\n", s);
  return 0;
  
}

int sum(int a, int s){
  if ( a < 1){
    return a+s;
  }
  return sum(a-1, a+s);
}