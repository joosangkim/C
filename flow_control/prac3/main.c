#include<stdio.h>

int main(void){
  int a , b ;
  int i;
  int sum = 0;
  fputs("두 개 정수 입력: ",stdout);
  scanf("%d %d", &a, &b);

  for(i = a; i <= b ; i++){
    if (!(i%3) || !(i%5)){
      printf("%d 는 합에서 제외\n", i);
      continue;
    }
    sum += i;
  }
  printf("%d 와 %d 사이의 합 : %d\n", a, b, sum);
  return 0;
}
