#include "stdafx.h"
#include "CLPhoneItemAdder.h"
#include "CLPhoneBook.h"
#include "ILPhoneBookCache.h"
#include "CLUtility.h"

CLPhoneItemAdder::CLPhoneItemAdder(ILPhoneBookCache *pCache)
{
	m_pCache = pCache;
	m_pPhoneBook = NULL;
}

CLPhoneItemAdder::~CLPhoneItemAdder()
{
}

bool CLPhoneItemAdder::Initial(CLPhoneBook * pPhoneBook)
{
	m_pPhoneBook = pPhoneBook;
	m_pPhoneBook->Register(this);

	return true;
}

bool CLPhoneItemAdder::Uninitial()
{
	return true;
}

bool CLPhoneItemAdder::IsYours(const char * pstrCmd)
{
	if(strcmp(pstrCmd, "-ad") == 0)
		return true;
	else
		return false;
}

bool CLPhoneItemAdder::Notify(const char *pstrCmdParameter)
{
	printf("will add item(name phone)\n");

	SLPhoneItem item;
	CLUtility::GetUserInput(item.name, NAME_LENGTH, "Please input name : ");
	CLUtility::GetUserInput(item.phone, PHONE_LENGTH, "Please input phone : ");

	m_pCache->PutPhoneItem(&item);

	return true;
}