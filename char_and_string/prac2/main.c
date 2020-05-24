#include<stdio.h>
#include <string.h> 
#define LEN 256

int main(void){
  char str[LEN] ;
  int diff = 'A' - 'a';
  int i = 0;
  fputs("문자열 입력 : ", stdout);
  
  fgets(str, LEN, stdin);
  for (i = 0; i < strlen(str); i++){
    if ( 'a' <= str[i] && str[i] <= 'z' ){
      str[i] += diff;
    }else if ('A' <= str[i] && str[i] <= 'Z'){
      str[i] -= diff;
    }
  }
  puts(str);
  return 0;
}