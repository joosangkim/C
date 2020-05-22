#include<stdio.h>

int main(void){
  char c;
  int i;
  double f;
  char str[100];

  printf("[char, int, float, string] format input: ");
  scanf("%c, %d, %lf, %s", &c, &i, &f, str);
  printf("%c, %d, %f, %s\n", c, i, f, str);

  return 0;
}
