/* Name:    gameTimes.h
 * Version: v1.0
 * Content: common functions
 */
#ifndef __GAMETIMES_H__
#define __GAMETIMES_H__
struct Money {
  int com;
  int user;
  int deal;
};
struct Money* initMoney(void);
void countGames(void);
// void countWinCom();
void countWinUser(void);
int getComMoney(void);
int getUserMoney(void);
double calcWinRate(void);
#endif
/* EOF */
