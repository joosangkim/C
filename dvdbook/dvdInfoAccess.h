/* Name:    cusInfoAccess.c
 * Version: v1.0
 * Content: customer information
 */
#ifndef __DVDACCESS_H__
#define __DVDACCESS_H__

#include "dvdInfo.h"

int AddDvdInfo(char* isbn, char* title, int* genre);
dvdInfo* GetDVDPtrByISBN(char* isbn);
int IsRegistISBN(char* isbn);
void SetDVDState(dvdInfo* dvd, int state);
int AddRentInfo(dvdInfo* dvd, char* id, int date);
#endif
