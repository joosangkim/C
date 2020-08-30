#include "common.h"
#include "rentInfo.h"
#include "rentInfoAccess.h"
#include "screenOut.h"

#define RENT_LEN 100
#define RENT_BACKUP_FILE "rentList.dat"

static dvdRentInfo rentList[RENT_LEN];
static int numOfRentCus = 0;


int AddRentList(char* ISBN, char* cusID, int rentDay){
  if (numOfRentCus >= RENT_LEN){
    return 1;
  }
  strcpy(rentList[numOfRentCus].cusID, cusID);
  strcpy(rentList[numOfRentCus].ISBN, ISBN);
  rentList[numOfRentCus].rentDay = rentDay;
  if(SetDVDState(ISBN, RENTED)){
    return 1;
  }
  numOfRentCus++;
  StoreRentListToFile();
  return 0;
}

void PrintOutRentAllCustInfo(char* ISBN){
  cusInfo* ci;
  int i;

  for(i = 0; i<numOfRentCus; i++){
    if(!strcmp(ISBN, rentList[i].ISBN)){
      ci = (cusInfo*)malloc(sizeof(cusInfo));
      ci = GetCusPtrByID(rentList[i].cusID);
      ShowRentHistoryWithCusInfo(rentList[i].rentDay, ci);
      free(ci);
    }
  }
}

void PrintOutCusAllRentInfo(char* ID, unsigned int start, unsigned int end){
  int i;

  for(i = 0; i<numOfRentCus; i++){
    if(!strcmp(ID, rentList[i].cusID)){
      if(start <= rentList[i].rentDay && rentList[i].rentDay <= end){
        ShowRentHistoryWithISBN(rentList[i].rentDay, rentList[i].ISBN);
      }
    }
  }
}

void StoreRentListToFile(void){
  FILE* fp = fopen(RENT_BACKUP_FILE, "wb");
  if(NULL == fp) return;

  fwrite(&numOfRentCus, sizeof(int), 1, fp);
  fwrite(rentList, sizeof(dvdRentInfo), numOfRentCus, fp);
  fclose(fp);

}
void LoadRentListToFile(void){
  FILE* fp = fopen(RENT_BACKUP_FILE, "rb");
  if(NULL == fp) return;

  fread(&numOfRentCus, sizeof(int), 1, fp);
  fread(rentList, sizeof(dvdRentInfo),numOfRentCus ,fp);
  fclose(fp);

}
