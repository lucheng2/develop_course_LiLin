#include "stdafx.h"

const char* DEFAULT_FILE_NAME = "temp.txt";

bool AddPhoneInfo()
{
	SLPhoneItem item;
	GetUserInput(item.name, NAME_LENGTH, "Please input name : ");
	GetUserInput(item.phone, PHONE_LENGTH, "Please input phone : ");

	AppendItemForDynamicArray(GetPhoneBuffer(), (char *)&item);

	return true;
}

void DisplayDefaultFile(const char *strDefaultFileFullPath)
{
	FILE *fp = fopen(strDefaultFileFullPath, "rb");
	if(fp != NULL)
	{
		while(1)
		{
			SLPhoneItem item;
			if(fread(&item, sizeof(SLPhoneItem), 1, fp) == 0)
				break;

			AppendItemForDynamicArray(GetPhoneBuffer(), (char *)&item);

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
	FILE *fp = fopen(GetOrSetDefaultFileFullPath(), "wb");
	if(fp == NULL)
	{
		printf("File open error.\n");
		return false;
	}

	if(GetPhoneBuffer()->uiCurrentItemCount > 0)
	{
		fwrite(GetPhoneBuffer()->pBuffer, sizeof(SLPhoneItem), GetPhoneBuffer()->uiCurrentItemCount, fp);
	}

	fclose(fp);

	return true;
}