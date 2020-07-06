/* Name:    main.c
 * Version: v1.0
 * Content: common functions
 */
#include "common.h"
#include "game.h"

/* Func:   int main(void)
 * Return: 0
 */
int main(void){
  int com;
  int you;
  puts("Let's start the game");
  puts("");

  puts("####### START #######");

  com = ChoiceOfCom();
  you = ChoiceOfMe();

  puts("####### RESULT #######");
  WhoIsWinner(com, you);

  printf(">> Com's choice %d \n", com);

  if(you == EVEN) puts(">> Your choice is even.");
  else            puts(">> Your choice is odd.");

  puts("");
  return 0;
}
/* EOF */
