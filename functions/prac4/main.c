#include<stdio.h>
#include<string.h>
#define MAX_STR_LEN 100

int numOfChar(const char *str, const char target);

int main(void){
  char str[MAX_STR_LEN];
  char t;
  int num=0;
  fputs("대상 문자열 입력: ", stdout);
  gets(str);

  fputs("새어볼 문자열: ", stdout);
  t = getchar();

  num = numOfChar(str, t);
  printf("%c의 갯수: %d\n", t, num);
  return 0;
}

int numOfChar(const char *str, const char target){
  int len = strlen(str);
  int i;
  int sum = 0;

  for(i = 0; i < len ; ++i){
    if(str[i] == target) sum++;
  }
  
  return sum;
}
