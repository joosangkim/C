#include<stdio.h>

int main(void){
  /* 4-1 */
  char c;
  int cnt = 0;
  /* 4-2 */
  int a = 0;
  int sum = 0;
  /* 4-1 count how many chars are entered until EOF */
  while(1){
    fputs("Data input(Ctrl+D to exit): ",stdout);
    c = getchar();
    /* printf("%c\n", c); */
    if( c == EOF){
      puts("");
      break;
    }
    cnt++;
    fflush(stdin);
  }
  
  printf("입력된 문자의 수: %d\n", cnt);

  /* 4-2 Sum of entered integer until EOF */
  while(1){
    fputs("Data input(Ctrl+D to exit): ", stdout);
    if (scanf("%d", &a) == EOF){
      break;
    }
    sum += a;
  }
  printf("Sum is: %d\n", sum);
  return 0;
}
