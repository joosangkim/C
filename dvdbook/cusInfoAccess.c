/* Name:    cusInfoAccess.c
 * Version: v1.0
 * Content: customer information
 */
#include "common.h"
#include "cusInfoAccess.h"

#define MAX_CUSTOMER 100
#define CUS_BACKUP_FILE "cusInfo.dat"

static cusInfo* cusList[MAX_CUSTOMER];
static int numOfCustomer=0;

int AddCusInfo(char* ID, char* name, char* num){
  cusInfo* ci = (cusInfo*)malloc(sizeof(cusInfo));
  if (numOfCustomer < MAX_CUSTOMER){
    strcpy(ci->ID,ID);
    strcpy(ci->name,name);
    strcpy(ci->phoneNum,num);
    cusList[numOfCustomer++] = ci;
    StoreCusListToFile();
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

void StoreCusListToFile(void){
  int i;
  FILE* fp = fopen(CUS_BACKUP_FILE, "wb");
  if(NULL == fp) return;

  fwrite(&numOfCustomer, sizeof(int), 1, fp);
  for(i = 0; i<numOfCustomer; i++){
    fwrite(cusList[i], sizeof(cusInfo), 1, fp);
  }
  fclose(fp);

}
void LoadCusListToFile(void){
  int i;
  FILE* fp = fopen(CUS_BACKUP_FILE, "rb");
  if(NULL == fp) return;

  fread(&numOfCustomer, sizeof(int), 1, fp);
  for(i = 0; i<numOfCustomer; i++){
    cusList[i] = (cusInfo*)malloc(sizeof(cusInfo));
    fread(cusList[i],sizeof(cusInfo),1 ,fp);
  }
  fclose(fp);
}
