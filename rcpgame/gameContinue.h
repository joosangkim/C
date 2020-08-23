/* Name:    gameContinue.h
 * Version: v1.0
 * Content: game save and continue functions
 */
#ifndef __GAMECONTINUE_H__
#define __GAMECONTINUE_H__
#include "gameMoney.h"
#include "gameTimes.h"

struct GameStatus {
  struct Money moneyStat;
  struct Times timeStat;
};
void setStatus(struct Money* ms, struct Times* ts);
int saveGame();
struct GameStatus* loadGame();

#endif
