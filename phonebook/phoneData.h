/* Name:    phoneData.h
 * Version: v1.0
 */
#ifndef __PHONEDATA_H__
#define __PHONEDATA_H__

#define NAME_LEN 10 
#define PHONE_LEN 30 
#define CSV_LEN NAME_LEN+PHONE_LEN

typedef struct __phoneData {
  char name[NAME_LEN];
  char phoneNum[PHONE_LEN];
} phoneData;

#endif

