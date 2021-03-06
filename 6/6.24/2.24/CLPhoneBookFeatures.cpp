#include "stdafx.h"
#include "CLPhoneBookFeatures.h"
#include "CLPhoneBook.h"
#include "CLUtility.h"
#include "CLDynamicArray.h"

CLPhoneBookFeatures::CLPhoneBookFeatures(CLPhoneBook *pPhoneBook)
{
	if(pPhoneBook == NULL)
		throw "CLPhoneBookFeatures::CLPhoneBookFeatures, pPhoneBook is null";

	m_pPhoneBook = pPhoneBook;
}

CLPhoneBookFeatures::~CLPhoneBookFeatures()
{
}

bool CLPhoneBookFeatures::AddPhoneInfo()
{
	SLPhoneItem item;
	CLUtility::GetUserInput(item.name, NAME_LENGTH, "Please input name : ");
	CLUtility::GetUserInput(item.phone, PHONE_LENGTH, "Please input phone : ");

	m_pPhoneBook->GetPhoneBookCache()->AppendItem((char *)&item);

	return true;
}

void CLPhoneBookFeatures::DisplayDefaultFile()
{
	FILE *fp = fopen(m_pPhoneBook->GetDefaultFileFullPath(), "rb");
	if(fp != NULL)
	{
		while(1)
		{
			SLPhoneItem item;
			if(fread(&item, sizeof(SLPhoneItem), 1, fp) == 0)
				break;

			m_pPhoneBook->GetPhoneBookCache()->AppendItem((char *)&item);

			printf("%s : %s\n", item.name, item.phone);
		}

		fclose(fp);
	}
	else
	{
		printf("Default file does not exist.\n");
	}
}

void CLPhoneBookFeatures::Usage()
{
	printf("Import file: -ld path\n");
	printf("Export file: -sa path\n");
	printf("Save info  : -se\n");
	printf("Add info   : -ad name phone\n");
}

bool CLPhoneBookFeatures::SavePhoneInfo()
{
	FILE *fp = fopen(m_pPhoneBook->GetDefaultFileFullPath(), "wb");
	if(fp == NULL)
	{
		printf("File open error.\n");
		return false;
	}

	for(int i = 0;; i++)
	{
		char *p = m_pPhoneBook->GetPhoneBookCache()->GetItem(i);
		if(p != NULL)
		{
			fwrite(p, sizeof(SLPhoneItem), 1, fp);
		}
		else
			break;
	}

	fclose(fp);

	return true;
}