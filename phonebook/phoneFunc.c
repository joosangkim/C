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
  char name[NAME_LEN];
  char phone[PHONE_LEN];
  if(numOfData >= LIST_NUM){
    puts("Not enouhg memory");
    return;
  }
  fputs("Enter name: ", stdout);
  gets(name);
  fputs("Enter phone: ", stdout);
  gets(phone);

  if(_InsertPhoneData(name, phone)){
    puts("Already exists");
    return;
  }
  fflush(stdin);
  StoreDataToFileInStruct();
  puts("Input complete"); 
}

int _InsertPhoneData(char* name, char* phoneNum){
  phoneData* pd = (phoneData*)malloc(sizeof(phoneData));
  strcpy(pd->name, name);
  strcpy(pd->phoneNum, phoneNum);
  if(CheckDupInfo(pd)){
    return 1;
  }
  phoneList[numOfData++] = pd;
  return 0; 
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
      searchList = GetIdxListByName(cnt, i);
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
      detList = GetIdxListByName(delCnt, i);
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
    StoreDataToFileInStruct();
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

/* Func:   void StoreDataToFile(void)
 * Return: void
 */
void StoreDataToFile(void){
  FILE* fp = fopen("phone.csv", "w");
  int i; 

  fwrite(&numOfData, sizeof(int), 1, fp);
  for(i = 0; i< numOfData; i++){
    fprintf(fp, "%s,%s\n",phoneList[i]->name,phoneList[i]->phoneNum);
    free(phoneList[i]);
  }
  fclose(fp);
  return;
}

/* Func:   void LoadDataFromFile(void)
 * Return: void
 */
void LoadDataFromFile(void){
  FILE* fp;
  char* csv = NULL;
  char* name;
  char* phone;

  fp = fopen("phone.csv", "r");

  csv = (char*)malloc(CSV_LEN * sizeof(char));
  while(NULL != fgets(csv, CSV_LEN, fp)){
    name = strtok(csv, ",");
    phone = strtok(NULL, ",");
    phone = strtok(phone, "\n");
    if(_InsertPhoneData(name, phone)){
      puts("Failed to load file");
    };
  }
  
  free(csv);
  fclose(fp);
}

/* Func:   void StoreDataToFileInStruct(void)
 * Return: void
 */
void StoreDataToFileInStruct(void){
  FILE* fp = fopen("phone_bin", "wb");

  fwrite(phoneList, sizeof(phoneData), sizeof(phoneList), fp);
  fclose(fp);
  return;
}

/* Func:   void LoadDataFromFileInStruct(void)
 * Return: void
 */
void LoadDataFromFileInStruct(void){
  FILE* fp = fopen("phone_bin", "rb");
  int i;

  // fread(&numOfData)
  // char* csv = NULL;
  // char* name;
  // char* phone;

  // csv = (char*)malloc(CSV_LEN * sizeof(char));
  // while(NULL != fgets(csv, CSV_LEN, fp)){
  //   name = strtok(csv, ",");
  //   phone = strtok(NULL, ",");
  //   phone = strtok(phone, "\n");
  //   if(_InsertPhoneData(name, phone)){
  //     puts("Failed to load file");
  //   };
  // }
  
  // free(csv);
  // fclose(fp);
}

void ChangePhoneData(void){
  char name[NAME_LEN];
  int* chgList;
  int chgCnt = 0;
  int chg;
  int i,chg_i;
  char* phone = (char*)malloc(sizeof(char)*PHONE_LEN);

  fputs("Enter name: ", stdout);
  gets(name);
  for ( i = 0; i < numOfData; i++){
    if (!strcmp(phoneList[i]->name, name) ){
      chgCnt+=1;
      chgList = GetIdxListByName(chgCnt, i);
    }
  }

  if (!chgCnt){
    puts("No data found");
    return;
  }else{
    for(chg_i = 0; chg_i<chgCnt; chg_i++){
        printf("NUM. %d\n", (chg_i+1));
        ShowPhoneInfoByPtr(phoneList[chgList[chg_i]]);
    }
    fputs("Choose change number: ", stdout);
    scanf("%d%*c", &chg);
    fflush(stdin);
    }

    fputs("To be phone number: ", stdout );
    gets(phone);
    strcpy(phoneList[chgList[chg-1]]->phoneNum, phone);

    free(chgList);
    free(phone);
    puts("Change complete");
    fflush(stdin);
    StoreDataToFileInStruct();
    return;
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


/* Func:   int* GetIdxListByName(int cnt, int idx)
 * Return: int*
 */
int* GetIdxListByName(int cnt, int idx){
  int* idxList = NULL;
  if ( cnt > 1 )  idxList = (int*)realloc(idxList, cnt*sizeof(int));
  else            idxList = (int*)malloc(cnt*sizeof(int));
  
  *(idxList+(cnt-1)) = idx;
  return idxList;
}
/* EOF */
