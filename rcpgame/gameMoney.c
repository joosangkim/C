/* Name:    gameMoney.c
 * Version: v1.0
 */
#include "common.h"
#include "gameMoney.h"

struct Money money;

struct Money *initMoney(void){
  money.com = 1000;
  money.user = 1000;
  money.deal = 0;

  return &money;
}

void discCom(void){
  money.com-=200;
}

void discUser(void){
  money.user-=money.deal;
}

int checkGameMoney(void){
  if (money.com <= 0 || money.user <= 0) return 0;
  else                       return 1;
}

int getComMoney(void){
  return money.com;
}

int getUserMoney(void){
  return money.user;
}

void setUserMoney(int um){
  money.user = um;
}

int setDeal(int d){
  if (d > money.user) return 1;
  money.deal = d;
  return 0;
}
