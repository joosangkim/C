#include<stdio.h>

int main(void){
  char scanStr[100];
  char getsStr[100];

  fputs("###### SCANF ######\n",stdout);
  scanf("%[^\n]%*c", scanStr);
  printf("%s\n", scanStr);
  printf("###### GETS ######\n");
  gets(getsStr);
  puts(getsStr);


  return 0;
}
