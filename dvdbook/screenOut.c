/* Name:    cusInfoAccess.c
 * Version: v1.0
 * Content: customer information
 */
#include "common.h"
#include "cusInfo.h"
#include "dvdInfo.h"

void ShowMenu(void){
  system("clear");

  printf("=========== MENU ===========\n");
  printf(" 1. Register Member \n");
  printf(" 2. Search Member   \n");
  printf("----------------------------\n");
  printf(" 3. Register DVD \n");
  printf(" 4. Search DVD   \n");
  printf("----------------------------\n");
  printf(" 5. Rent   DVD \n");
  printf(" 6. Return DVD   \n");
  printf("----------------------------\n");
  printf(" 7. Rent History By ISBN\n");
  printf(" 8. Rent History By Member ID\n");
  printf("----------------------------\n");
  printf(" 9. Exit \n");
  printf("============================\n");
  printf("CHOOSE >> ");


}

void showCustomerInfo(cusInfo* pCus){
  printf("----------------------------\n");
  printf("|  >> ID    : %s \n", pCus->ID);
  printf("|  >> NAME  : %s \n", pCus->name);
  printf("|  >> PHONE : %s \n", pCus->phoneNum);
  printf("----------------------------\n");

}

void showGenre(int gen){
  switch(gen){
    case ACTION:
      fputs("ACTION", stdout);
      break;
    case COMIC:
      fputs("COMIC", stdout);
      break;
    case SF:
      fputs("SF", stdout);
      break;
    case ROMANTIC:
      fputs("ROMANTIC", stdout);
      break;
  }
}
void showState(int state){
  switch(state){
    case RENTED:
      fputs("RENTED", stdout);
      break;
    case RETURNED:
      fputs("RETURNED", stdout);
      break;
    default:
      fputs("UNKNOWN", stdout);
      break;
  }
}

void showDVDInfo(dvdInfo* pDvd){

  printf("----------------------------\n");
  printf("|  >> ISBN  : %s \n", pDvd->ISBN);
  printf("|  >> TITLE : %s \n", pDvd->title);
  fputs("|  >> GENRE : ",stdout), showGenre(pDvd->genre), puts("");
  fputs("|  >> STATE : ",stdout), showState(pDvd->rentState), puts("");
  printf("----------------------------\n");
}

void ShowRentHistoryWithCusInfo(int rentDate, cusInfo* ci){
  printf("Rent Date: %d\n", rentDate);
  showCustomerInfo(ci);
}

void ShowRentHistoryWithISBN(int rendDate, char* ISBN){
  printf("----------------------------\n");
  printf("|  >> ISBN      : %s \n", ISBN);
  printf("|  >> RENT DATE : %d \n", rendDate);
  printf("----------------------------\n");
}
