/* Name:    cusInfoAccess.c
 * Version: v1.0
 * Content: customer information
 */
#ifndef __SCREENOUT_H__
#define __SCREENOUT_H__

#include "cusInfo.h"
#include "dvdInfo.h"

void ShowMenu(void);
void showCustomerInfo(cusInfo* pCus);
void showDVDInfo(dvdInfo* pDvd);
void showGenre(int gen);
void ShowRentHistoryWithCusInfo(int rentDate, cusInfo* ci);
void ShowRentHistoryWithISBN(int rendDate, char* ISBN);
#endif
