/* Name:    phoneFunc.h
 * Version: v1.0
 */
#ifndef __PHONEFUNC_H__
#define __PHONEFUNC_H__
#include "phoneData.h"
void InputPhoneData(void);
int _InsertPhoneData(char* name, char* phoneNum);
void SearchPhoneData(void);
void DeletePhoneData(void);
void ShowAllData(void);
int  CheckDupInfo(phoneData*);
int* GetIdxListByName(int cnt, int idx);
void StoreDataToFile(void);
void LoadDataFromFile(void);
void ChangePhoneData(void);

void StoreDataToFileInStruct(void);
void LoadDataFromFileInStruct(void);
#endif

