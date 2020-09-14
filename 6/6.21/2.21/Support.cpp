#include "stdafx.h"

bool InterpretCommand(const char* strCommand, char *strCommandHead, char *strParameter)
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

bool DispatchCommand(const char *strCommandHead, const char *strCommandParameter)
{
	if(strcmp(strCommandHead, "-ld") == 0)
	{
		printf("Needed load file is %s\n", strCommandParameter);
		TransferBetweenTwoFiles(strCommandParameter, GetOrSetDefaultFileFullPath());
		return true;
	}

	if(strcmp(strCommandHead, "-sa") == 0)
	{
		printf("will export phone book to %s\n", strCommandParameter);
		TransferBetweenTwoFiles(GetOrSetDefaultFileFullPath(), strCommandParameter);
		return true;
	}

	if(strcmp(strCommandHead, "-se") == 0)
	{
		printf("will save phone book\n");
		SavePhoneInfo();
		return true;
	}

	if(strcmp(strCommandHead, "-ad") == 0)
	{
		printf("will add item(name phone)\n");
		AddPhoneInfo();
		return true;
	}

	if(strcmp(strCommandHead, "-qt") == 0)
	{
		printf("quit now ....\n");
		return false;
	}

	printf("False command\n");
	Usage();

	return true;
}

void EnterCommandLoop()
{
	char cmd[MAX_LENGTH_OF_CMD];

	while(1)
	{
		GetUserInput(cmd, MAX_LENGTH_OF_CMD, "Please input your command : ");

		printf("Your command is : %s\n", cmd);

		char cmd_head[MAX_LENGTH_OF_CMD_HEAD];
		char cmd_parameter[MAX_LENGTH_OF_CMD];
		memset(cmd_head, 0, MAX_LENGTH_OF_CMD_HEAD);
		memset(cmd_parameter, 0, MAX_LENGTH_OF_CMD);
		if(!InterpretCommand(cmd, cmd_head, cmd_parameter))
		{
			printf("False command.\n");
			Usage();
			continue;
		}

		if(!DispatchCommand(cmd_head, cmd_parameter))
			break;
	}
}

const char *GetOrSetDefaultFileFullPath(const char *strDefaultFileFullPath)
{
	static const char *DefaultFileFullPath = NULL;

	if(DefaultFileFullPath != NULL)
		return DefaultFileFullPath;

	if(strDefaultFileFullPath != NULL)
		DefaultFileFullPath = strDefaultFileFullPath;

	return DefaultFileFullPath;
}

SLPhoneInMemory *GetPhoneBuffer()
{
	static SLPhoneInMemory pm;
	return &pm;
}

void InitialPhoneBuffer()
{
	SLPhoneInMemory *pm = GetPhoneBuffer();
	pm->CurrentPosition = 0;
	memset(pm->Buffer, 0, PHONE_BUFFER_LENGTH);
}