#ifndef FUNCTION_H
#define FUNCTION_H

#include "Defines.h"

struct SLPhoneItem
{
	char name[NAME_LENGTH];
	char phone[PHONE_LENGTH];
};

bool AddPhoneInfo();

void DisplayDefaultFile(const char *strDefaultFileFullPath);

void Usage();

bool SavePhoneInfo();

#endif