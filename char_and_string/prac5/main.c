#include<stdio.h>
#include<string.h>
#define WORD_LEN 20
#define WORD_NUM 4
#define TOTAL ( WORD_LEN*WORD_NUM )

int main(void){
  char word1[WORD_LEN];
  char word2[WORD_LEN];
  char word3[WORD_LEN];
  char word4[WORD_LEN];
  char total[TOTAL];
  char sep = ' ';
  char* word_ptr[WORD_LEN] = { word1, word2, word3, word4 };
  char* temp = NULL;
  int i = 0;
  int j ;

  while(i < WORD_NUM){
    printf("문자열 입력 %d: ", i + 1);
    fgets(word_ptr[i], WORD_LEN, stdin);
    word_ptr[i][strlen(word_ptr[i])-1] = '\0';
    i++;
  }

  for (i = 0; i < WORD_NUM; i++){
    for (j = 0; j < (WORD_NUM - i) -1; j++){
      if (strcmp(word_ptr[j], word_ptr[j+1]) > 0){
        temp = word_ptr[j+1];
        word_ptr[j+1] = word_ptr[j];
        word_ptr[j] =  temp;
      }
    }
  }

  for( i =0 ; i < WORD_NUM; i++){
    strcat(total, word_ptr[i]);
    strcat(total, &sep);
  }
  puts(total);
  return 0;
}