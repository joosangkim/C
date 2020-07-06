/* Name:    game.c
 * Version: v1.0
 */
#include "common.h"
#include "game.h"

int ChoiceOfCom(void){
  /* initialize random seed: */
  return genRand();

}

int ChoiceOfMe(void){
  int s; 
  puts("Enter 1 for odd number, enter 2 for even number: ");
  scanf("%d", &s);
  return s;
}

void WhoIsWinner(int com, int you){
  int ret = !(com % 2) ? EVEN : ODD;

  if (ret == you) puts("You are winner");
  else            puts("Com are winner");
}