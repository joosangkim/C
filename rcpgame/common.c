/* Name:    common.c
 * Version: v1.0
 * Content: common functions
 */
#include <time.h>
#include "common.h"
#include "game.h"

int genRandForRCP(void){
  srand(time(NULL));
  return (rand() % 3 + 1);
}

void showRSP(int val){
  switch (val){
    case ROCK:
      fputs("ROCK", stdout);
      break;
    case SCISSORS:
      fputs("SCISSORS", stdout);
      break;
    case PAPER:
      fputs("PAPER", stdout);
      break;
  };
}

/* EOF */
