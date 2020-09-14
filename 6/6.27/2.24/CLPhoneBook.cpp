#include "stdafx.h"
#include <windows.h>
#include "CLPhoneBook.h"
#include "CLUtility.h"
#include "CLPhoneBookFeatures.h"
#include "CLFullCacheForPhoneBook.h"
#include "ILPhoneBookCmdObserver.h"
#include "CLPhoneBookExporter.h"
#include "CLPhoneBookImporter.h"
#include "CLPhoneBookSaver.h"
#include "CLPhoneItemAdder.h"

const char* DEFAULT_FILE_NAME = "temp.txt";

const unsigned int MAX_LENGTH_OF_CMD = 300;
const unsigned int MAX_LENGTH_OF_CMD_HEAD = 10;

CLPhoneBook::CLPhoneBook()
{
	m_strDefaultFileFullPath = new char [MAX_PATH];
	memset(m_strDefaultFileFullPath, 0, MAX_PATH);

	m_pPhoneBookCache = NULL;

	m_pFeatures = NULL;
}

CLPhoneBook::~CLPhoneBook()
{
	if(m_pFeatures != NULL)
		delete m_pFeatures;

	if(m_pPhoneBookCache != NULL)
		delete m_pPhoneBookCache;

	delete [] m_strDefaultFileFullPath;
}

bool CLPhoneBook::Register(ILPhoneBookCmdObserver *pCmdObserver)
{
	m_pvCmdObservers.push_back(pCmdObserver);
	return true;
}

const char *CLPhoneBook::GetDefaultFileFullPath()
{
	return m_strDefaultFileFullPath;
}

bool CLPhoneBook::Run(const char *strArgv0)
{
	if(!Initial(strArgv0))
		return false;

	m_pFeatures->DisplayDefaultFile();

	EnterCommandLoop();

	if(!Uninitial())
		return false;

	return true;
}

bool CLPhoneBook::Initial(const char *strArgv0)
{
	CLUtility::GetDefaultFileFullPath(m_strDefaultFileFullPath, DEFAULT_FILE_NAME, strArgv0);

	printf("Default file path: %s\n", m_strDefaultFileFullPath);

	m_pPhoneBookCache = new CLFullCacheForPhoneBook(m_strDefaultFileFullPath);

	if(m_pPhoneBookCache->Initial() == false)
		return false;

	m_pFeatures = new CLPhoneBookFeatures(this);

	CLPhoneBookExporter *pExporter = new CLPhoneBookExporter(m_pFeatures);
	pExporter->Initial(this);

	CLPhoneBookImporter *pImporter = new CLPhoneBookImporter(m_pFeatures);
	pImporter->Initial(this);

	CLPhoneBookSaver *pSaver = new CLPhoneBookSaver(m_pPhoneBookCache);
	pSaver->Initial(this);

	CLPhoneItemAdder *pAdder = new CLPhoneItemAdder(m_pPhoneBookCache);
	pAdder->Initial(this);

	return true;
}

bool CLPhoneBook::Uninitial()
{
	for(int i = 0; i < m_pvCmdObservers.size(); i++)
	{
		m_pvCmdObservers[i]->Uninitial();
		delete m_pvCmdObservers[i];
	}

	delete m_pFeatures;
	m_pFeatures = NULL;

	if(m_pPhoneBookCache->Unitial() == false)
		return false;

	delete m_pPhoneBookCache;
	m_pPhoneBookCache = NULL;

	return true;
}

bool CLPhoneBook::InterpretCommand(const char* strCommand, char *strCommandHead, char *strParameter)
{
	if(strlen(strCommand) < 3)
		return false;

	char cmd[MAX_LENGTH_OF_CMD];
	memset(cmd, 0, MAX_LENGTH_OF_CMD);
	strcpy(cmd, strCommand);

	cmd[3] = 0;

	strcpy(strCommandHead, cmd);

	if(strlen(strCommand) > 3)
		strcpy(strParameter, cmd + 4);

	return true;
}

bool CLPhoneBook::DispatchCommand(const char *strCommandHead, const char *strCommandParameter)
{
	for(int i = 0; i < m_pvCmdObservers.size(); i++)
	{
		if(m_pvCmdObservers[i]->IsYours(strCommandHead))
		{
			m_pvCmdObservers[i]->Notify(strCommandParameter);
			return true;
		}
	}

	if(strcmp(strCommandHead, "-qt") == 0)
	{
		printf("quit now ....\n");
		return false;
	}

	printf("False command\n");
	m_pFeatures->Usage();

	return true;
}

void CLPhoneBook::EnterCommandLoop()
{
	char cmd[MAX_LENGTH_OF_CMD];

	while(1)
	{
		CLUtility::GetUserInput(cmd, MAX_LENGTH_OF_CMD, "Please input your command : ");

		printf("Your command is : %s\n", cmd);

		char cmd_head[MAX_LENGTH_OF_CMD_HEAD];
		char cmd_parameter[MAX_LENGTH_OF_CMD];
		memset(cmd_head, 0, MAX_LENGTH_OF_CMD_HEAD);
		memset(cmd_parameter, 0, MAX_LENGTH_OF_CMD);
		if(!InterpretCommand(cmd, cmd_head, cmd_parameter))
		{
			printf("False command.\n");
			m_pFeatures->Usage();
			continue;
		}

		if(!DispatchCommand(cmd_head, cmd_parameter))
			break;
	}
}