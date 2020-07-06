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
  fputs(">> Com's choice is ",stdout);
  showRSP(com);
  puts("");
  fputs(">> Your choice is ",stdout);
  showRSP(you);
  puts("");
  return 0;
}
/* EOF */
