/* Name:    gameContinue.c
 * Version: v1.0
 * Content: game save and continue functions
 */
#include "common.h"
#include "gameContinue.h"

struct GameStatus status;

void setStatus(struct Money* ms, struct Times* ts){
  status.moneyStat = *ms;
  status.timeStat = *ts;
}
int saveGame(){
  FILE *fp = fopen("data.bin", "wb");
  fwrite(&status, sizeof(status), 1, fp);
  fclose(fp);

  return 0;
}

struct GameStatus* loadGame(){
  struct GameStatus s ;
  FILE *fp = fopen("data.bin", "rb");
  fread(&status, sizeof(s), 1, fp);
  fclose(fp);

  status = s;
  return &status;
}
