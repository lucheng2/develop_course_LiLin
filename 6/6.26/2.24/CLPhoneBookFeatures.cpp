#include "stdafx.h"
#include "CLPhoneBookFeatures.h"
#include "CLPhoneBook.h"
#include "CLUtility.h"
#include "ILPhoneBookCache.h"

CLPhoneBookFeatures::CLPhoneBookFeatures(CLPhoneBook *pPhoneBook, ILPhoneBookCache *pCache)
{
	if(pPhoneBook == NULL)
		throw "CLPhoneBookFeatures::CLPhoneBookFeatures, pPhoneBook is null";

	if(pCache == NULL)
		throw "CLPhoneBookFeatures::CLPhoneBookFeatures, pCache is null";

	m_pPhoneBook = pPhoneBook;
	m_pPhoneBookCache = pCache;
}

CLPhoneBookFeatures::~CLPhoneBookFeatures()
{
}

bool CLPhoneBookFeatures::ImportPhoneBookFile(const char *strFilePath)
{
	return TransferBetweenTwoPhoneBookFiles(strFilePath, m_pPhoneBook->GetDefaultFileFullPath());
}

bool CLPhoneBookFeatures::ExportPhoneBookFile(const char *strFilePath)
{
	return TransferBetweenTwoPhoneBookFiles(m_pPhoneBook->GetDefaultFileFullPath(), strFilePath);
}

bool CLPhoneBookFeatures::TransferBetweenTwoPhoneBookFiles(const char *strSrcFile, const char *strDstFile)
{
	if((strSrcFile == NULL) || (strDstFile == NULL))
	{
		printf("False command.\n");
		Usage();
		return false;
	}

	if((strlen(strSrcFile) == 0) || (strlen(strDstFile) == 0))
	{
		printf("False command.\n");
		Usage();
		return false;
	}

	FILE *fpSrcFile = fopen(strSrcFile, "rb");
	if(fpSrcFile == NULL)
	{
		printf("File open error.\n");
		return false;
	}

	FILE *fpDstFile = fopen(strDstFile, "ab");
	if(fpDstFile == NULL)
	{
		printf("file open error.\n");
		fclose(fpSrcFile);
		return false;
	}

	while(1)
	{
		SLPhoneItem item;
		if(fread(&item, sizeof(SLPhoneItem), 1, fpSrcFile) == 0)
			break;

		fwrite(&item, sizeof(SLPhoneItem), 1, fpDstFile);
	}

	fclose(fpDstFile);
	fclose(fpSrcFile);

	return true;
}

bool CLPhoneBookFeatures::AddPhoneInfo()
{
	SLPhoneItem item;
	CLUtility::GetUserInput(item.name, NAME_LENGTH, "Please input name : ");
	CLUtility::GetUserInput(item.phone, PHONE_LENGTH, "Please input phone : ");

	m_pPhoneBookCache->PutPhoneItem(&item);

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
	m_pPhoneBookCache->FlushCache();

	return true;
}