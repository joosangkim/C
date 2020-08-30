/* Name:    manager.h
 * Version: v1.0
 * Content: manager file
 */
#ifndef __MANAGER_H__
#define __MANAGER_H__

#include "cusInfo.h"
#include "dvdInfo.h"
#include "rentInfo.h"
#include "cusInfoAccess.h"
#include "dvdInfoAccess.h"
#include "rentInfoAccess.h"
#include "screenOut.h"

void RegisterCustomer(void);
void SearchCusInfo(void);

void RegisterDVD(void);
void SearchDVDInfo(void);
void RentDVD(void);
void ReturnDVD(void);
void RentHistoryByISBN(void);
void RentHistoryByCusAndDate(void);

void InitData(void);
#endif
