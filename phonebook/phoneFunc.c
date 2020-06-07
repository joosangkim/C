/* Name:    phoneFunc.c
 * Version: v1.0
 */
#include "common.h"
#include "phoneData.h"
#include "screenOut.h"

#define LIST_NUM 100

int numOfData = 0;
phoneData *phoneList[LIST_NUM];

/* Func:   void InputPhoneData(void)
 * Return: void
 */
void InputPhoneData(void){
  if(numOfData >= LIST_NUM){
    puts("Not enouhg memory");
    return;
  }
  phoneData *pd = (phoneData*)malloc(sizeof(phoneData));
  fputs("Enter name: ", stdout);
  gets(pd->name);
  fputs("Enter phone: ", stdout);
  gets(pd->phoneNum);
  if(isDup(pd)){
    puts("Already exists");
  }else {
    phoneList[numOfData] = pd;
    numOfData++;
    puts("Input complete");
  } 
}

/* Func:   void SearchPhoneData(void)
 * Return: void
 */
void SearchPhoneData(void){
  char name[NAME_LEN];
  int i ;
  fputs("Enter name: ", stdout);
  gets(name);
  for ( i = 0; i < numOfData; i++){
    if (!strcmp(phoneList[i]->name, name) ){
      ShowPhoneInfoByPtr(phoneList[i]);
      return;
    }
  }
  puts("No data found");
}

/* Func:   void SearchPhoneData(void)
 * Return: void
 */
int isDup(phoneData *pd){
  int i ;
  for ( i = 0; i < numOfData; i++){
    if (!strcmp(phoneList[i]->name, pd->name) ){
      if (!strcmp(phoneList[i]->phoneNum, pd->phoneNum)){
        return 1;
      }
    }
  }
  return 0;
}

/* Func:   void DeletePhoneData(void)
 * Return: void
 */
void DeletePhoneData(void){
  char name[NAME_LEN];
  int i,j  ;

  fputs("Enter name: ", stdout);
  gets(name);
  for ( i = 0; i < numOfData; i++){
    if (!strcmp(phoneList[i]->name, name) ){
      for(j = i+1; j < numOfData; j++){
        phoneList[j-1] = phoneList[j] ;
      }
      numOfData--;
      puts("Delete complete");
      return;
    }
  }
  puts("No data found");
}

/* Func:   void ShowAllData(void)
 * Return: void
 */
void ShowAllData(void){
  int i;
  for(i = 0; i < numOfData; i++){
    ShowPhoneInfoByPtr(phoneList[i]);
  }
}
/* EOF */