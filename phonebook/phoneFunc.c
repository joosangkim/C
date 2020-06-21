/* Name:    phoneFunc.c
 * Version: v1.0
 */
#include "common.h"
#include "phoneData.h"
#include "screenOut.h"
#include "phoneFunc.h"

#define LIST_NUM 100

int numOfData = 0;
phoneData* phoneList[LIST_NUM];

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

  if(CheckDupInfo(pd)){
    puts("Already exists");
  }else {
    phoneList[numOfData] = pd;
    numOfData++;
    puts("Input complete");
  } 
  fflush(stdin);
}

/* Func:   void SearchPhoneData(void)
 * Return: void
 */
void SearchPhoneData(void){
  char name[NAME_LEN];
  int* searchList;
  int i ;
  int cnt = 0;
  fputs("Enter name: ", stdout);
  gets(name);
  for ( i = 0; i < numOfData; i++){
    if (!strcmp(phoneList[i]->name, name) ){
      cnt+=1;
      searchList = GetIdxListByName(name, cnt, i);
    }
  }
  if( !cnt) {
    puts("No data found");
  }else {
    for( i =0; i< cnt; i++){
      ShowPhoneInfoByPtr(phoneList[searchList[i]]);
      puts("");
    }
    fflush(stdin);
    free(searchList);
  }
}

/* Func:   void DeletePhoneData(void)
 * Return: void
 */
void DeletePhoneData(void){
  char name[NAME_LEN];
  int* detList;
  int delCnt = 0;
  int del;
  int i,j,del_i  ;

  fputs("Enter name: ", stdout);
  gets(name);
  for ( i = 0; i < numOfData; i++){
    if (!strcmp(phoneList[i]->name, name) ){
      delCnt+=1;
      detList = GetIdxListByName(name, delCnt, i);
    }
  }

  if (!delCnt){
    puts("No data found");
    return;
  }else{
    for(del_i = 0; del_i<delCnt; del_i++){
        printf("NUM. %d\n", (del_i+1));
        ShowPhoneInfoByPtr(phoneList[detList[del_i]]);
      }
      fputs("Choose delete number: ", stdout);
      scanf("%d", &del);
      fflush(stdin);
    }

    for(j = detList[del-1]+1; j < numOfData; j++){
      phoneList[j-1] = phoneList[j];
    }
    numOfData--;
    free(detList);
    puts("Delete complete");
    return;
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

/* Func:   int CheckDupInfo(phoneData*)
 * Return: int
 */
int CheckDupInfo(phoneData* pd){
  int i ;
  for ( i = 0; i < numOfData; i++){
    if (!strcmp(phoneList[i]->name, pd->name) && !strcmp(phoneList[i]->phoneNum, pd->phoneNum) ){
        return 1;
    }
  }
  return 0;
}


/* Func:   int* GetIdxListByName(char* name, int cnt, int idx)
 * Return: int*
 */
int* GetIdxListByName(char* name, int cnt, int idx){
  int* idxList = NULL;
  if ( cnt > 1 )  idxList = (int*)realloc(idxList, cnt*sizeof(int));
  else            idxList = (int*)malloc(cnt*sizeof(int));
  
  *(idxList+(cnt-1)) = idx;
  return idxList;
}
/* EOF */