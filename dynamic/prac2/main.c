#include<stdio.h>
#include<stdlib.h>
#define NUM_OF_STR 5

void read_str(char** str);
int main(void){
  char strArr[5][];
  int i;

  for (int i = 0; i < NUM_OF_STR; i++){
    read_str(strArr[i]);
  }

  return 0;
}
void read_str(char* str){
  char c;
  int i = 0;
  while(1){
    c = fgetc(stdin);
    (char*)realloc(*(str+i), sizeof(char));


  }
  
  
}
