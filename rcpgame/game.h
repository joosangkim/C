/* Name:    game.h
 * Version: v1.0
 */
#ifndef __GAME_H__
#define __GAME_H__

enum {
  ROCK=1,
  SCISSORS,
  PAPER
} RCP;

int ChoiceOfCom(void);
int ChoiceOfMe(void);
void WhoIsWinner(int com, int you);

#endif 

/* EOF */