/* Name:    main.c
 * Version: v1.0
 * Content: common functions
 */
#include"common.h"
#include"screenOut.h"
#include"phoneFunc.h"

enum{ 
  INPUT = 1, 
  SHOWALL, 
  SEARCH,
  DELETE,
  CHANGE,
  QUIT
};

/* Func:   int main(void)
 * Return: 0
 */
int main(void){
  int inputMenu = 0;
  puts("Loading files...");
  /* LoadDataFromFile(); */
  LoadDataFromFileInStruct();
  while(1){  
    ShowMenu();
    fputs("Choose : ", stdout);
    scanf("%d%*c", &inputMenu);
    fflush(stdin);

    switch(inputMenu){
      case INPUT:
        InputPhoneData();
        break;
      case SHOWALL:
        ShowAllData();
        break;
      case SEARCH:
        SearchPhoneData();
        break;
      case CHANGE:
        ChangePhoneData();
        break;
      case DELETE:
        DeletePhoneData();
        break;
    }
    if(inputMenu == QUIT){
      StoreDataToFile();
      puts("Thanks for using.");
      break;
    }
  }
  return 0;
}
/* EOF */
