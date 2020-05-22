#include<stdio.h>
#include<limits.h>
#define CNT 7

int main(void){
  int buf;
  int max=INT_MIN;
  int min=INT_MAX;
  int sum = 0;
  int i;
  for ( i =0; i< CNT; i++){
    fputs("정수형 데이터 입력: ", stdout);
    scanf("%d", &buf);
    sum += buf;
    if ( max < buf ){
      max = buf;
    }
    if ( min > buf ){
      min = buf;
    }

  }
  printf("MAX: %d\n", max);
  printf("MIN: %d\n", min);
  printf("SUM: %d\n", sum);
  printf("AVG: %lf\n", (double)sum/CNT);


  return 0;
}
