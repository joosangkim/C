#include<stdio.h>
#define STR_MAX 100

int strLen(char* str);
int strCpy(char* dest, char* source);
int strCat(char* dest, char* source);
int strCmp(char* str1, char* str2);

int main(void){
  char str1[STR_MAX]="Good morning!";
  char str2[STR_MAX]="HaHaHa!";
  char buff[STR_MAX];

  printf("len of \"%s\": %d\n", str1, strLen(str1));
  printf("len of \"%s\": %d\n", str2, strLen(str2));
  
  strCpy(buff, str1);
  printf("copy string :  \"%s\"\n", buff);
  
  strCat(buff, str2);
  printf("concat : \"%s\"\n", buff);

  printf("cmp1: %d\n", strCmp(str1, str1));
  printf("cmp2: %d\n", strCmp(str2, str2));
  printf("cmp3: %d\n", strCmp(str1, str2));
  printf("cmp4: %d\n", strCmp(str2, str1));
  return 0;
}

int strLen(char* str){
  int l = 0;
  int i = 0;
  while(str[i++] != '\0'){
    l++;
  }
  return l;
}

int strCpy(char* dest, char* source){
  int i = 0;
  while(source[i++] != '\0' ){
    dest[i-1] = source[i-1];
  }
  return i;
}

int strCat(char* dest, char* source){
  int i = 0;
  int destLen = strLen(dest);

  while(source[i++] != '\0' ){
    dest[destLen+(i-1)] = source[i-1];    
  }
  return destLen+(i-1);
}

int strCmp(char* str1, char* str2){
  int i = 0;
  while(str1[i] != '\0' && str2[i] != '\0'){
    if (str1[i] > str2[i]){
      return 1;
    }else if (str2[i] > str1[i]){
      return -1;
    }
    i++;
  }
  if (str1[i] == '\0' && str2[i] == '\0'){
    return 0;
  }
  return str1[i] == '\0' ? -1 : 1;
}
