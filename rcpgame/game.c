/* Name:    game.c
 * Version: v1.0
 */
#include "common.h"
#include "game.h"
#include "gameTimes.h"
#include "gameMoney.h"

int ChoiceOfCom(void){
  /* initialize random seed: */
  return genRandForRCP();

}

int ChoiceOfMe(void){
  int s;
  puts("ROCK<1>  SCISSORS<2>  PAPER<3>  EXIT<4>: ");
  scanf("%d", &s);
  return s;
}

void WhoIsWinner(int com, int you){
  int isWinner = 0;

  if (you  == com ){
    puts("Draw the game.");
    return;
  }
  if (com == ROCK){
    if ( you == PAPER ) isWinner = 1;
  }else if (com == SCISSORS) {
    if ( you == ROCK ) isWinner = 1;
  }else if ( com == PAPER){
    if ( you == SCISSORS ) isWinner = 1;
  }

  if(!isWinner){
    discUser();
    puts("Com is Winner");
  }else {
    countWinUser();
    discCom();
    puts("You are Winner");
  }
}
