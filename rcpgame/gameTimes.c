/* Name:    gameTimes.c
 * Version: v1.0
 */
#include "common.h"
#include "gameTimes.h"

extern double winRate ;
struct Times times;

struct Times *initTimes(void){
  times.total = 0;
  times.win = 0;

  return &times;
}

void countGames(void){
  times.total++;
}
// void countWinCom(){
//   winCom++;
// }
void countWinUser(void){
  times.win++;
}
double calcWinRate(void){
  return (winRate = times.win / (double)times.total * 100);
}

