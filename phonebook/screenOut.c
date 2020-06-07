/* Name:    screenOut.c
 * Version: v1.0
 */
#include "common.h"
#include "phoneData.h"

/* Func:   void ShowMenu(void)
 * Return: void
 */
void ShowMenu(void){
  puts("-------------- MENU--------------");
  puts("  1. Enter Phone Number ");
  puts("  2. Show All Information ");
  puts("  3. Search an Information ");
  puts("  4. Delete an Information ");
  puts("  5. Quit ");
}

/* Func:   void ShowPhoneInfo(phoneData phone)
 * Return: void
 */
void ShowPhoneInfoByPtr(phoneData *phone){
  printf("=================================\n");
  printf("|  >> NAME : %s \n", phone->name);
  printf("|  >> PHONE: %s \n", phone->phoneNum);
  printf("=================================\n\n");
}
/* EOF */