/* Name:    gameMoney.c
 * Version: v1.0
 */
#include "common.h"
#include "gameMoney.h"

static int com  = 1000;
static int user = 1000;

void discCom(void){
  com-=200;
}

void discUser(void){
  user-=200;
}

int checkGameMoney(void){
  if (com <= 0 || user <= 0) return 0;
  else                       return 1;
}

int getComMoney(void){
  return com;
}

int getUserMoney(void){
  return user;
}
