/* Name:    manager.c
 * Version: v1.0
 * Content: manager file
 */

#include "common.h"
#include "manager.h"

void InitData(void){
  LoadCusListToFile();
  LoadDVDListToFile();
  LoadRentListToFile();
}

void RegisterCustomer(void){
  char id[ID_LEN];
  char name[NAME_LEN];
  char phone[PHONE_LEN];

  printf("Enter ID: ");
  scanf("%s", id);
  fflush(stdin);
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


void RegisterDVD(void){
  char isbn[ISBN_LEN];
  char title[TITLE_LEN];
  int  genre;

  printf("Enter ISBN: ");
  scanf("%s", isbn);
  getchar();
  if(IsRegistISBN(isbn)){
    puts("The ISBN is already registered..Please enter another ISBN...");
    return;
  }
  printf("Enter TITLE: ");
  scanf("%s", title);
  fflush(stdin);

  printf("Enter genre [ACTION: 1, COMIC: 2, SF: 3, ROMANTIC: 4]: ");
  scanf("%d", &genre);
  fflush(stdin);

  if(!AddDvdInfo(isbn, title, &genre)){
    puts("Complete registering");
    return;
  }
}

void SearchDVDInfo(void){
  char isbn[ISBN_LEN];
  dvdInfo* di;

  printf("Enter ISBN for searching: ");
  scanf("%s", isbn);
  fflush(stdin);

  if(IsRegistISBN(isbn)){
    di = GetDVDPtrByISBN(isbn);
    showDVDInfo(di);
  }else {
    printf("No DVD with ISBN \'%s\'...\n",isbn);
  }
  return;
}

void RentDVD(void){
  char isbn[ISBN_LEN];
  char id[ID_LEN];
  int  rentDate;
  int  rentState;

  fputs("Enter ISBN to rent: ", stdout);
  scanf("%s", isbn);
  fflush(stdin);
  if(!IsRegistISBN(isbn)){
    printf("No DVD with ISBN \'%s\'...\n", isbn);
    return;
  }

  rentState = GetDVDState(isbn);
  if(rentState == RENTED ){
    puts("The DVD is Rented...");
    return;
  }
  puts("Start rent procedure...");

  fputs("Enter member ID: ", stdout);
  scanf("%s", id);
  fflush(stdin);
  if(!IsRegistID(id)){
    puts("Not a member...");
    return;
  }

  fputs("Enter rent date: ", stdout);
  scanf("%d", &rentDate);
  fflush(stdin);

  if(!AddRentList(isbn, id, rentDate)){
    puts("Rent Complete");
  }else {
    puts("Rent Failed");
  }
  return;
}

void ReturnDVD(void){
  char isbn[ISBN_LEN];
  int rentState;

  fputs("Enter ISBN to return: ", stdout);
  scanf("%s", isbn);
  fflush(stdin);
  if(!IsRegistISBN(isbn)){
    printf("No DVD with ISBN \'%s\'...\n", isbn);
    return;
  }

  rentState=GetDVDState(isbn);
  if(rentState == RETURNED ){
    puts("The DVD is already returned...");
    return;
  }
  puts("Start return procedure...");
  if (SetDVDState(isbn, RETURNED)){
    puts("Return Failed...");
  };
  puts("Return Complete...");
  return;
}

void RentHistoryByISBN(void){
  char isbn[ISBN_LEN];

  fputs("Enter ISBN for searching: ", stdout);
  scanf("%s", isbn);
  fflush(stdin);
  if(!IsRegistISBN(isbn)){
    printf("No DVD with ISBN \'%s\'...\n", isbn);
    return;
  }
  PrintOutRentAllCustInfo(isbn);

  return;

}

void RentHistoryByCusAndDate(void){
  char id[ID_LEN];
  int start, end;

  fputs("Enter memberID for searching: ", stdout);
  scanf("%s", id);
  fflush(stdin);
  if(!IsRegistID(id)){
    printf("No member with ID \'%s\'...\n", id);
    return;
  }

  fputs("Enter date range(YYYYMMDD YYYYMMDD): ", stdout);
  scanf("%d %d", &start, &end);
  fflush(stdin);
  PrintOutCusAllRentInfo(id, start, end);

  return;

}
