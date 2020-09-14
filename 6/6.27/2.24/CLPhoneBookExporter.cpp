#include "stdafx.h"
#include "CLPhoneBookExporter.h"
#include "CLPhoneBook.h"
#include "CLPhoneBookFeatures.h"

CLPhoneBookExporter::CLPhoneBookExporter(CLPhoneBookFeatures *pFeatures)
{
	m_pFeatures = pFeatures;
	m_pPhoneBook = NULL;
}

CLPhoneBookExporter::~CLPhoneBookExporter()
{
}

bool CLPhoneBookExporter::Initial(CLPhoneBook * pPhoneBook)
{
	pPhoneBook->Register(this);

	m_pPhoneBook = pPhoneBook;

	return true;
}

bool CLPhoneBookExporter::Uninitial()
{
	return true;
}

bool CLPhoneBookExporter::IsYours(const char * pstrCmd)
{
	if(strcmp(pstrCmd, "-sa") == 0)
		return true;
	else
		return false;
}

bool CLPhoneBookExporter::Notify(const char *pstrCmdParameter)
{
	printf("will export phone book to %s\n", pstrCmdParameter);

	return m_pFeatures->TransferBetweenTwoPhoneBookFiles(m_pPhoneBook->GetDefaultFileFullPath(), pstrCmdParameter);
}