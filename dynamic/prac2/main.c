#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define NUM_OF_STR 5

void readStr(char* str);
int main(void){
  char *strArr[NUM_OF_STR];
  int i, j;

  puts("Enter 5 strings.");
  for (i = 0; i < NUM_OF_STR; i++){
    printf("string #%d: ", i);
    strArr[i] = malloc(sizeof(char));
    readStr(strArr[i]);
  }
  puts("Complete");
  for( i = 0; i < NUM_OF_STR  ; i++){
    for(j = 0; j < (NUM_OF_STR-1) - i ; j++){
      if (strlen(strArr[j]) > strlen(strArr[j+1])){
        char *temp = strArr[j];
        strArr[j] = strArr[j+1];
        strArr[j+1] = temp;
        temp = NULL;
      }
    }
  }

  for (i = 0; i < NUM_OF_STR; i++){
    printf("string #%d: %s\n", i, strArr[i]);
    free(strArr[i]);
  }
  
  return 0;
}

void readStr(char* str){
  char c;
  int i = 0;
  while(1){
    c = fgetc(stdin);
    if ( c == EOF || c == '\n'){
      break;
    }else {
      str = (char*)realloc(str, sizeof(char));
      *(str + i) = c;
      i++;
    } 
  }
}
