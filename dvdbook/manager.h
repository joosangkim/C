/* Name:    manager.h
 * Version: v1.0
 * Content: manager file
 */
#ifndef __MANAGER_H__
#define __MANAGER_H__

#include "cusInfo.h"
#include "dvdInfo.h"
#include "cusInfoAccess.h"
#include "dvdInfoAccess.h"
#include "screenOut.h"

void RegisterCustomer(void);
void SearchCusInfo(void);

void RegisterDVD(void);
void SearchDVDInfo(void);
void RentDVD(void);
void ReturnDVD(void);
void RentHistory(void);

#endif
