#include "stdafx.h"
#include "CLPhoneBookImporter.h"
#include "CLPhoneBook.h"
#include "CLPhoneBookFeatures.h"

CLPhoneBookImporter::CLPhoneBookImporter(CLPhoneBookFeatures *pFeatures)
{
	m_pFeatures = pFeatures;
	m_pPhoneBook = NULL;
}

CLPhoneBookImporter::~CLPhoneBookImporter()
{
}

bool CLPhoneBookImporter::Initial(CLPhoneBook * pPhoneBook)
{
	pPhoneBook->Register(this);

	m_pPhoneBook = pPhoneBook;

	return true;
}

bool CLPhoneBookImporter::Uninitial()
{
	return true;
}

bool CLPhoneBookImporter::IsYours(const char * pstrCmd)
{
	if(strcmp(pstrCmd, "-ld") == 0)
		return true;
	else
		return false;
}

bool CLPhoneBookImporter::Notify(const char *pstrCmdParameter)
{
	printf("Needed load file is %s\n", pstrCmdParameter);

	return m_pFeatures->TransferBetweenTwoPhoneBookFiles(pstrCmdParameter, m_pPhoneBook->GetDefaultFileFullPath());
}