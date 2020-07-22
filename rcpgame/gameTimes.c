/* Name:    gameTimes.c
 * Version: v1.0
 */
#include "common.h"
#include "gameTimes.h"

static int total   = 0;
static int winUser = 0;
// int winCom  = 0;
extern double winRate ;

void countGames(void){
  total++;
}
// void countWinCom(){
//   winCom++;
// }
void countWinUser(void){
  winUser++;
}
double calcWinRate(void){
  return (winRate = winUser / (double)total * 100);
}

