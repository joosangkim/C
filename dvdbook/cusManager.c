/* Name:    cusInfoAccess.c
 * Version: v1.0
 * Content: customer information
 */
#include "common.h"
#include "cusInfo.h"
#include "cusInfoAccess.h"
#include "screenOut.h"

void RegisterCustomer(void){
  char id[ID_LEN];
  char name[NAME_LEN];
  char phone[PHONE_LEN];

  printf("Enter ID: ");
  scanf("%s", id);
  getchar();
  if(IsRegistID(id)){
    puts("The ID is already registered..Please enter another ID...");
    return;
  }
  printf("Enter NAME: ");
  scanf("%s", name);
  fflush(stdin);
  printf("Enter PHONE: ");
  scanf("%s", phone);
  fflush(stdin);

  if(!AddCusInfo(id, name, phone)){
    puts("Complete registering");
    return;
  }
}

void SearchCusInfo(void){
  char id[ID_LEN];
  cusInfo* ci;

  printf("Enter ID for searching: ");
  scanf("%s", id);
  fflush(stdin);

  if(IsRegistID(id)){
    ci = GetCusPtrByID(id);
    showCustomerInfo(ci);
  }else {
    printf("No member with ID \'%s\'...\n",id);
  }
  return;
}
