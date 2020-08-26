/* Name:    cusInfoAccess.c
 * Version: v1.0
 * Content: customer information
 */
#include "common.h"
#include "dvdInfo.h"

#define MAX_DVD 100

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

void SetDVDState(dvdInfo* dvd, int state){
  dvd->rentState = state;
}
int AddRentInfo(dvdInfo* dvd, char* id, int date){
  if (dvd->numOfRentCus > RENT_LEN){
    return 1;
  }
  strcpy(dvd->rentList[dvd->numOfRentCus].cusID, id);
  dvd->rentList[dvd->numOfRentCus++].rentDay = date;
  SetDVDState(dvd, RENTED);
  return 0;
}


