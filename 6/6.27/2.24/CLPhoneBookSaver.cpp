#include "stdafx.h"
#include "CLPhoneBookSaver.h"
#include "CLPhoneBook.h"
#include "ILPhoneBookCache.h"

CLPhoneBookSaver::CLPhoneBookSaver(ILPhoneBookCache *pCache)
{
	m_pCache = pCache;
}

CLPhoneBookSaver::~CLPhoneBookSaver()
{
}

bool CLPhoneBookSaver::Initial(CLPhoneBook * pPhoneBook)
{
	pPhoneBook->Register(this);

	return true;
}

bool CLPhoneBookSaver::Uninitial()
{
	return true;
}

bool CLPhoneBookSaver::IsYours(const char * pstrCmd)
{
	if(strcmp(pstrCmd, "-se") == 0)
		return true;
	else
		return false;
}

bool CLPhoneBookSaver::Notify(const char *pstrCmdParameter)
{
	printf("will save phone book\n");

	m_pCache->FlushCache();

	return true;
}