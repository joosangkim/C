#include<stdio.h>
#define MAX_LANG 100

int main(void){
  int a;
  int ret[MAX_LANG];
  int i = 0;
  fputs("10진수 정수 입력: ", stdout);
  scanf("%d", &a);

  while( a > 0){
    ret[i] = a % 2;
    a /= 2;
    i++;
  }
  while(i > 0){
    printf("%d",ret[--i]);
  }
  puts("");
  return 0;
}