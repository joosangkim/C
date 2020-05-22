#include<stdio.h>

int main(void){
  int num, a;
  int s_odd = 0;
  int s_even = 0;

  fputs("자연수입력: ", stdout);
  scanf("%d", &num);
  a = num;
  while( a > 0){
    if (!(a%2)){  
      s_even += a;
    }else {
      s_odd += a;
    }
    a--;
  }
  printf("%d이하 홀수 합: %d\n", num, s_odd);
  printf("%d이하 짝수 합: %d\n", num, s_even);
  return 0;
}