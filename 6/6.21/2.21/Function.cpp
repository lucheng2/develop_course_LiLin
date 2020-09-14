#include "stdafx.h"

const char* DEFAULT_FILE_NAME = "temp.txt";

bool AddPhoneInfo()
{
	SLPhoneItem item;
	GetUserInput(item.name, NAME_LENGTH, "Please input name : ");
	GetUserInput(item.phone, PHONE_LENGTH, "Please input phone : ");

	char *p = GetPhoneBuffer()->Buffer;

	int left_room = PHONE_BUFFER_LENGTH - GetPhoneBuffer()->CurrentPosition;
	if(left_room < sizeof(SLPhoneItem))
	{
		printf("Buffer is not enough.\n");
		return false;
	}

	memcpy(p + GetPhoneBuffer()->CurrentPosition, &item, sizeof(SLPhoneItem));

	GetPhoneBuffer()->CurrentPosition += sizeof(SLPhoneItem);

	return true;
}

void DisplayDefaultFile(const char *strDefaultFileFullPath)
{
	FILE *fp = fopen(strDefaultFileFullPath, "rb+");
	if(fp != NULL)
	{
		while(1)
		{
			SLPhoneItem item;
			if(fread(&item, sizeof(SLPhoneItem), 1, fp) == 0)
				break;

			printf("%s : %s\n", item.name, item.phone);
		}

		fclose(fp);
	}
	else
	{
		printf("Default file does not exist.\n");
	}
}

void Usage()
{
	printf("Import file: -ld path\n");
	printf("Export file: -sa path\n");
	printf("Save info  : -se\n");
	printf("Add info   : -ad name phone\n");
}

bool SavePhoneInfo()
{
	FILE *fp = fopen(GetOrSetDefaultFileFullPath(), "ab");
	if(fp == NULL)
	{
		printf("File open error.\n");
		return false;
	}

	int n = GetPhoneBuffer()->CurrentPosition;
	if((n > PHONE_BUFFER_LENGTH) || (n <= 0))
		return false;

	fwrite(GetPhoneBuffer()->Buffer, n, 1, fp);

	InitialPhoneBuffer();

	fclose(fp);
	return true;
}