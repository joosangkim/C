/* Name:    game.c
 * Version: v1.0
 */
#include "common.h"
#include "game.h"

int ChoiceOfCom(void){
  /* initialize random seed: */
  return genRandForRCP();

}

int ChoiceOfMe(void){
  int s; 
  puts("Enter 1 for ROCK, enter 2 for SCISSORS, enter 3 for PAPER: ");
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
    puts("Com is Winner");
  }else {
    puts("You are Winner");
  }
}