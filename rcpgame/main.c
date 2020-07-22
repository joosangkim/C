/* Name:    main.c
 * Version: v1.0
 * Content: common functions
 */
#include "common.h"
#include "game.h"
#include "gameTimes.h"
#include "gameMoney.h"

double winRate;
/* Func:   int main(void)
 * Return: 0
 */
int main(void){
  int com;
  int you;
  puts("Let's start the game");

  while(1){
    if (!checkGameMoney()) {
      puts("Not enough game money.");
      break;
    }
    puts("");
    puts("####### START #######");

    com = ChoiceOfCom();
    you = ChoiceOfMe();
    if (4 == you){
      break;
    }else if(you < 1 || you > 4){
      puts("Wrong choice...");
      continue;
    }

    countGames();

    puts("####### RESULT #######");
    WhoIsWinner(com, you);
    fputs(">> Com's choice is ",stdout);
    showRSP(com);
    puts("");
    fputs(">> Your choice is ",stdout);
    showRSP(you);
    puts("");
    printf("Win rate: %.3lf %% \n", calcWinRate());
    printf("User money: %d\n",getUserMoney());
    printf("Com money: %d\n",getComMoney());
  }

  puts("####### FINAL RESULT #######");
  printf("Final Win rate: %.3lf\n", winRate);
  puts("Thanks for playing game..");
  return 0;
}
/* EOF */
