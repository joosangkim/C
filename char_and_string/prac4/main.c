#include<stdio.h>
#include<string.h>
#define NUM_WORD 5
#define STR_LEN 20

int main(void){
  char words[NUM_WORD][STR_LEN];
  char buf[STR_LEN];
  int i = 0;
  int j;
  
  while(i < NUM_WORD){
    printf("문자열 입력 %d: ", i + 1);
    fgets(words[i], STR_LEN, stdin);
    i++;
  }

  for(i = NUM_WORD ; i > 0; i--){
    for( j = 0; j < i-1 ; j++){
      if(strlen(words[j]) > strlen(words[j+1])){
        strcpy(buf , words[j+1] );
        strcpy(words[j+1], words[j]);
        strcpy(words[j], buf);
      }
    }
  }

  for( i =0 ; i < NUM_WORD; i++){
    fputs(words[i], stdout);
  }

  return 0;
}