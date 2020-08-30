/* Name:    cusInfoAccess.c
 * Version: v1.0
 * Content: customer information
 */
#include "common.h"
#include "dvdInfoAccess.h"

#define MAX_DVD 100
#define DVD_BACKUP_FILE "dvdInfo.dat"

static dvdInfo* dvdList[MAX_DVD];
static int numOfDvd=0;

int AddDvdInfo(char* isbn, char* title, int* genre){
  dvdInfo* di = (dvdInfo*)malloc(sizeof(dvdInfo));
  if (numOfDvd < MAX_DVD){
    strcpy(di->ISBN, isbn);
    strcpy(di->title,title);
    di->genre = *genre;
    di->rentState = RETURNED;

    dvdList[numOfDvd++] = di;
    StoreDVDListToFile();
    return 0;
  }
  return 1;
}

dvdInfo* GetDVDPtrByISBN(char* isbn){
  int i;
  for(i = 0; i < numOfDvd; i++){
    if (!strcmp(isbn, dvdList[i]->ISBN)){
      return dvdList[i];
    }
  }
  return NULL;
}

int IsRegistISBN(char* isbn){
  int i;
  for(i = 0; i < numOfDvd; i++){
    if (!strcmp(isbn, dvdList[i]->ISBN)){
      return 1;
    }
  }
  return 0;
}

int SetDVDState(char* isbn, int state){
  dvdInfo* dvd;
  dvd = GetDVDPtrByISBN(isbn);

  if (NULL == dvd)  return 1;
  dvd->rentState = state;
  StoreDVDListToFile();
  return 0;
}

int GetDVDState(char* isbn){
  dvdInfo* dvd;
  dvd = GetDVDPtrByISBN(isbn);

  if (NULL == dvd)  return -1;
  return dvd->rentState;
}

void StoreDVDListToFile(void){
  int i;
  FILE* fp = fopen(DVD_BACKUP_FILE, "wb");
  if(NULL == fp) return;

  fwrite(&numOfDvd, sizeof(int), 1, fp);
  for(i = 0; i<numOfDvd; i++){
    fwrite(dvdList[i], sizeof(dvdInfo), 1, fp);
  }
  fclose(fp);

}
void LoadDVDListToFile(void){
  int i;
  FILE* fp = fopen(DVD_BACKUP_FILE, "rb");
  if(NULL == fp) return;

  fread(&numOfDvd, sizeof(int), 1, fp);
  for(i = 0; i<numOfDvd; i++){
    dvdList[i] = (dvdInfo*)malloc(sizeof(dvdInfo));
    fread(dvdList[i],sizeof(dvdInfo),1 ,fp);
  }
  fclose(fp);

}


