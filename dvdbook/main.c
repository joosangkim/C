#include "common.h"
#include "cusManager.h"
#include "screenOut.h"

enum{
  CUS_REGIST = 1,
  CUS_SEARCH,
  QUIT
};

int main(void){
  int inputMenu = 0;

  while(1){
    ShowMenu();
    scanf("%d", &inputMenu);
    fflush(stdin);

    switch (inputMenu)
    {
      case CUS_REGIST:
        RegisterCustomer();
        getchar();
        break;
      case CUS_SEARCH:
        SearchCusInfo();
        getchar();
        break;
    }

    if (inputMenu == QUIT){
      puts("Thanks for using.. :) ");
      break;
    }
  }
  return 0;
}
