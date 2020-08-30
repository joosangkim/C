#ifndef __RENTINFOACCESS_H__
#define __RENTINFOACCESS_H__

#include "dvdInfoAccess.h"
#include "cusInfoAccess.h"

int AddRentList(char* ISBN, char* cusID, int rentDay);
void PrintOutRentAllCustInfo(char* ISBN);
void PrintOutCusAllRentInfo(char* ID, unsigned int start, unsigned int end);
void StoreRentListToFile(void);
void LoadRentListToFile(void);

#endif
