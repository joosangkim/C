/* Name:    gameMoney.h
 * Version: v1.0
 * Content: common functions
 */
#ifndef __GAMEMONEY_H__
#define __GAMEMONEY_H__
struct Times {
  int total;
  int win;
};

struct Times *initTimes(void);
void discCom(void);
void discUser(void);
int checkGameMoney(void);
int getComMoney(void);
int getUserMoney(void);
void setUserMoney(int);
int setDeal(int);

#endif
/* EOF */
