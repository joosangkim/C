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
  RENT_HIST_BY_ISBN,
  RENT_HIST_BY_CUS_ID,
  QUIT
};

int main(void){
  int inputMenu = 0;
  InitData();
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
      case RENT_HIST_BY_ISBN:
        RentHistoryByISBN();
        getchar();
        break;
      case RENT_HIST_BY_CUS_ID:
        RentHistoryByCusAndDate();
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
