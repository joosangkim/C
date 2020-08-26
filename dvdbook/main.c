#include "common.h"
#include "manager.h"
#include "screenOut.h"

enum{
  CUS_REGIST = 1,
  CUS_SEARCH,
  DVD_REGIST,
  DVD_SEARCH,
  RENT_DVD,
  RETURN_DVD,
  RENT_HIST,
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
      case DVD_REGIST:
        RegisterDVD();
        getchar();
        break;
      case DVD_SEARCH:
        SearchDVDInfo();
        getchar();
        break;
      case RENT_DVD:
        RentDVD();
        getchar();
        break;
      case RETURN_DVD:
        ReturnDVD();
        getchar();
        break;
      case RENT_HIST:
        RentHistory();
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
