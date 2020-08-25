/* Name:    cusInfoAccess.c
 * Version: v1.0
 * Content: customer information
 */
#include "common.h"
#include "cusInfo.h"

#define MAX_CUSTOMER 100

static cusInfo* cusList[MAX_CUSTOMER];
static int numOfCustomer=0;

int AddCusInfo(char* ID, char* name, char* num){
  cusInfo* ci = (cusInfo*)malloc(sizeof(cusInfo));
  if (numOfCustomer < MAX_CUSTOMER){
    strcpy(ci->ID,ID);
    strcpy(ci->name,name);
    strcpy(ci->phoneNum,num);
    cusList[numOfCustomer++] = ci;
    return 0;
  }
  return 1;
}

cusInfo* GetCusPtrByID(char* ID){
  int i;
  for(i = 0; i < numOfCustomer; i++){
    if (!strcmp(ID, cusList[i]->ID)){
      return cusList[i];
    }
  }
  return NULL;
}

int IsRegistID(char* ID){
  int i;
  for(i = 0; i < numOfCustomer; i++){
    if (!strcmp(ID, cusList[i]->ID)){
      return 1;
    }
  }
  return 0;
}
