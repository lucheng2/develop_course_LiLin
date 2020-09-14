#include "stdafx.h"
#include <windows.h>
#include "CLPhoneBook.h"
#include "CLUtility.h"
#include "CLDynamicArray.h"
#include "CLPhoneBookFeatures.h"

const char* DEFAULT_FILE_NAME = "temp.txt";

const unsigned int MAX_LENGTH_OF_CMD = 300;
const unsigned int MAX_LENGTH_OF_CMD_HEAD = 10;

CLPhoneBook::CLPhoneBook()
{
	m_strDefaultFileFullPath = new char [MAX_PATH];
	memset(m_strDefaultFileFullPath, 0, MAX_PATH);

	m_pDynamicArray = new CLDynamicArray();

	m_pFeatures = new CLPhoneBookFeatures(this);
}

CLPhoneBook::~CLPhoneBook()
{
	delete m_pFeatures;

	delete m_pDynamicArray;

	delete [] m_strDefaultFileFullPath;
}

CLDynamicArray *CLPhoneBook::GetPhoneBookCache()
{
	return m_pDynamicArray;
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

	FILE *fp = fopen(m_strDefaultFileFullPath, "rb");
	if(fp != NULL)
	{
		fseek(fp, 0, SEEK_END);
		int file_length = ftell(fp);

		fclose(fp);

		if(file_length != 0)
		{
			m_pDynamicArray->Initial(file_length * 2/sizeof(SLPhoneItem), sizeof(SLPhoneItem));
			return true;
		}
	}

	m_pDynamicArray->Initial(1, sizeof(SLPhoneItem));

	return true;
}

bool CLPhoneBook::Uninitial()
{
	m_pDynamicArray->Destroy();

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
	if(strcmp(strCommandHead, "-ld") == 0)
	{
		printf("Needed load file is %s\n", strCommandParameter);
		CLUtility::TransferBetweenTwoFiles(strCommandParameter, m_strDefaultFileFullPath);
		return true;
	}

	if(strcmp(strCommandHead, "-sa") == 0)
	{
		printf("will export phone book to %s\n", strCommandParameter);
		CLUtility::TransferBetweenTwoFiles(m_strDefaultFileFullPath, strCommandParameter);
		return true;
	}

	if(strcmp(strCommandHead, "-se") == 0)
	{
		printf("will save phone book\n");
		m_pFeatures->SavePhoneInfo();
		return true;
	}

	if(strcmp(strCommandHead, "-ad") == 0)
	{
		printf("will add item(name phone)\n");
		m_pFeatures->AddPhoneInfo();
		return true;
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