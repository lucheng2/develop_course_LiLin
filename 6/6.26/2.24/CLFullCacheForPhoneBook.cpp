#include "stdafx.h"
#include "CLFullCacheForPhoneBook.h"
#include "CLDynamicArray.h"

CLFullCacheForPhoneBook::CLFullCacheForPhoneBook(const char *strDefaultFileFullPath)
{
	m_strDefaultFileFullPath = strDefaultFileFullPath;

	m_pDynamicArray = new CLDynamicArray();
}

CLFullCacheForPhoneBook::~CLFullCacheForPhoneBook()
{
	delete m_pDynamicArray;
}

bool CLFullCacheForPhoneBook::Initial()
{
	FILE *fp = fopen(m_strDefaultFileFullPath.c_str(), "rb");
	if(fp != NULL)
	{
		fseek(fp, 0, SEEK_END);
		int file_length = ftell(fp);

		fseek(fp, 0, SEEK_SET);

		if(file_length != 0)
		{
			m_pDynamicArray->Initial(file_length * 2/sizeof(SLPhoneItem), sizeof(SLPhoneItem));

			while(1)
			{
				SLPhoneItem item;
				if(fread(&item, sizeof(SLPhoneItem), 1, fp) == 0)
					break;

				m_pDynamicArray->AppendItem((char *)&item);
			}

			fclose(fp);

			return true;
		}

		fclose(fp);
	}

	m_pDynamicArray->Initial(1, sizeof(SLPhoneItem));

	return true;
}

bool CLFullCacheForPhoneBook::Unitial()
{
	m_pDynamicArray->Destroy();

	return true;
}

SLPhoneItem* CLFullCacheForPhoneBook::GetPhoneItem(unsigned int index)
{
	return (SLPhoneItem *)m_pDynamicArray->GetItem(index);
}

bool CLFullCacheForPhoneBook::PutPhoneItem(SLPhoneItem *pPhoneItem)
{
	return m_pDynamicArray->AppendItem((char *)pPhoneItem);
}

bool CLFullCacheForPhoneBook::FlushCache()
{
	FILE *fp = fopen(m_strDefaultFileFullPath.c_str(), "wb");
	if(fp == NULL)
	{
		printf("File open error.\n");
		return false;
	}

	for(int i = 0;; i++)
	{
		char *p = m_pDynamicArray->GetItem(i);
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