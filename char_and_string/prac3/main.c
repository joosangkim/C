#include<stdio.h>

#define LEN 256

int main(void){
  char ch;
  int diff = 'A' - 'a';
  fputs("문자열 입력 : ", stdout);
  
  while(1){
    ch = getchar();
    if (ch == '\n'){
      break;
    }

    if ('A' <= ch && ch <= 'Z') ch -= diff;
    else if ('a' <= ch && ch <= 'z') ch += diff;
    
    putchar(ch);
    
  }

  return 0;
}