#include<stdio.h>

int main(void){
  char c;
  int ret;
  while(1){
    /* c = getchar(); */
    /* getchar bug..?*/
    ret = scanf("%c%*c", &c);
    fflush(stdin);
    if (ret == EOF){
      puts("프로그램을 종료합니다.");
      break;
    }
    if ('a' <= c && c <= 'z')
      puts("소문자");
    else if( 'A' <= c && c <= 'Z')
      puts("대문자");
    else if ('0' <= c && c <= '9')
      puts("숫자");
    else
      puts("숫자");


  }
  return 0;
}