/* Name:    main.c
 * Version: v1.0
 * Content: common functions
 */
#include "common.h"
#include "game.h"
#include "gameTimes.h"
#include "gameMoney.h"
#include "gameContinue.h"

double winRate;

/* Func:   int main(void)
 * Return: 0
 */
int main(void){
  int com;
  int you;
  int userMoney;
  int deal;
  int save;
  int resume;

  puts("Do you want to resume game?...<Yes: 1, No: 0>");
  scanf("%d%*c",&resume);
  if (resume){
    loadGame();

  }else {
    puts("Let's start the game");
    struct Money* moneyStat = initMoney();
    struct Times* timeStat = initTimes();
    setStatus(moneyStat, timeStat);
    fputs("Enter your game money: ",stdout);
    scanf("%d", &userMoney);
    setUserMoney(userMoney);
    fflush(stdin);
  }

  printf("User Money: %d\n", getUserMoney());
  printf("Com Money: %d\n", getComMoney());

  while(1){
    if (!checkGameMoney()) {
      puts("Not enough game money.");
      break;
    }
    fputs("Enter your deal: ",stdout);
    scanf("%d", &deal);
    fflush(stdin);
    if (setDeal(deal)){
      puts("Not proper deal");
      continue;
    }
    puts("");
    puts("####### START #######");

    com = ChoiceOfCom();
    you = ChoiceOfMe();
    if (4 == you){
      puts("Do you want to save this game?...<Yes: 1, No: 0>");
      scanf("%d%*c", &save);
      if(save){
        saveGame();
      }
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
