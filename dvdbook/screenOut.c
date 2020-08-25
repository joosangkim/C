/* Name:    cusInfoAccess.c
 * Version: v1.0
 * Content: customer information
 */
#include "common.h"
#include "cusInfo.h"

void ShowMenu(void){
  system("clear");

  printf("=========== MENU ===========\n");
  printf(" 1. Register \n");
  printf(" 2. Search   \n");
  printf(" 3. Exit \n");
  printf("============================\n");
  printf("CHOOSE >>");


}

void showCustomerInfo(cusInfo* pCus){
  system("clear");

  printf("----------------------------\n");
  printf("|  >> ID    : %s \n", pCus->ID);
  printf("|  >> NAME  : %s \n", pCus->name);
  printf("|  >> PHONE : %s \n", pCus->phoneNum);
  printf("----------------------------\n");

  getchar();
}
