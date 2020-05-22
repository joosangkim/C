#include<stdio.h>

int main(void){
  int num, i;
  int sum = 0;

  while(1){
    fputs("2이상 자연수입력: ", stdout);
    scanf("%d", &num);
    if (num < 2){
      fputs("2 이상의 자연수를 입력하시오\n",stdout);
    }else {
      break;
    }
  }

  for(i =1; i<num; i++){
    if (num < (sum +i)){
      printf("%d 을 더할 때 처음 %d를 넘기 시작\n",i,num);
      printf("%d를 넘기 이전의 합: %d\n",num, sum);
      printf("%d를 넘기 이후의 합: %d\n",num, sum+i);
      break;
    }
    sum += i;
  }

  return 0;
}