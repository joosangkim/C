/* Name:    phoneFunc.h
 * Version: v1.0
 */
#ifndef __PHONEFUNC_H__
#define __PHONEFUNC_H__
#include "phoneData.h"
void InputPhoneData(void);
void SearchPhoneData(void);
void DeletePhoneData(void);
void ShowAllData(void);
int  CheckDupInfo(phoneData*);
int* GetIdxListByName(int cnt, int idx);
void StoreDataToFile(void);
void LoadDataFromFile(void);
#endif

