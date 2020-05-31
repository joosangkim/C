#include<stdio.h>

char* strTok(char* str, char* delim);

int main(void){
  char str[] = "111-222-3333";
  char* delim = "-";
  char* token;
  token=strTok(str, delim);
  while(token != NULL){    
    puts(token);
    token=strTok(NULL, delim);
  }
  return 0;
}

char* strTok(char* str, char* delim){
  static char* next;
  int i = 0;
  
  if (str == NULL){
    if (next == NULL){
      return NULL;
    }
    str = next;
  }
  while(1){
    if (*(str+i) == '\0'){
      next = NULL;
      break;
    }
    if (*(str+i) == *delim){
      *(str+i) = '\0';
      next = str+(i+1);
      break;
    }
    i++;
  } 
  
  return str;
}
