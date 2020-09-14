// 2.20.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <windows.h>
#include <string.h>

const unsigned int MAX_LENGTH_OF_CMD = 300;
const unsigned int MAX_LENGTH_OF_CMD_HEAD = 10;

const unsigned int BUFFER_LENGTH = 1000;

const char* DEFAULT_FILE_NAME = "temp.txt";

const char *GetOrSetDefaultFileFullPath(const char *strDefaultFileFullPath = NULL)
{
	static const char *DefaultFileFullPath = NULL;

	if(DefaultFileFullPath != NULL)
		return DefaultFileFullPath;

	if(strDefaultFileFullPath != NULL)
		DefaultFileFullPath = strDefaultFileFullPath;

	return DefaultFileFullPath;
}

/*
strDefaultFileFullPath要确保足够的存储空间，建议为MAX_PATH
*/
bool GetDefaultFileFullPath(char *strDefaultFileFullPath, const char *strDefaultFileName, const char *strArgv0)
{
	int i = strlen(strArgv0) - 1;
	while(i >= 0)
	{
		if(strArgv0[i] == '\\')
			break;

		i--;
	}

	if(i < 0)
	{
		strcpy(strDefaultFileFullPath, strDefaultFileName);
	}
	else
	{
		strcpy(strDefaultFileFullPath, strArgv0);
		strcpy(strDefaultFileFullPath + i + 1, strDefaultFileName);
	}

	return true;
}

void DisplayDefaultFile(const char *strDefaultFileFullPath)
{
	FILE *fp = fopen(strDefaultFileFullPath, "r+");
	if(fp != NULL)
	{
		while(1)
		{
			char buf[MAX_PATH];
			if(fgets(buf, MAX_PATH, fp) == NULL)
				break;

			printf("%s", buf);
		}

		fclose(fp);
	}
	else
	{
		printf("Default file does not exist.\n");
	}
}

/*
确保strCommandHead和strParameter有足够的空间，建议分别设为MAX_LENGTH_OF_CMD_HEAD、MAX_LENGTH_OF_CMD
*/
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

void Usage()
{
	printf("Import file: -ld path\n");
	printf("Export file: -sa path\n");
	printf("Save info  : -se\n");
	printf("Add info   : -ad name phone\n");
}

bool TransferBetweenTwoFiles(const char *strSrcFile, const char *strDstFile)
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

	FILE *fpSrcFile = fopen(strSrcFile, "r");
	if(fpSrcFile == NULL)
	{
		printf("File open error.\n");
		return false;
	}

	FILE *fpDstFile = fopen(strDstFile, "a");
	if(fpDstFile == NULL)
	{
		printf("file open error.\n");
		fclose(fpSrcFile);
		return false;
	}

	while(1)
	{
		char buf[MAX_PATH];
		if(fgets(buf, MAX_PATH, fpSrcFile) == NULL)
			break;

		fputs(buf, fpDstFile);
	}

	fclose(fpDstFile);
	fclose(fpSrcFile);

	return true;
}

struct SLPhoneInMemory
{
	int CurrentPosition;//指定buffer中何处是空闲的
	char Buffer[BUFFER_LENGTH];
};

SLPhoneInMemory *GetPhoneBuffer()
{
	static SLPhoneInMemory pm;
	return &pm;
}

void InitialPhoneBuffer()
{
	SLPhoneInMemory *pm = GetPhoneBuffer();
	pm->CurrentPosition = 0;
	memset(pm->Buffer, 0, BUFFER_LENGTH);
}

bool AddPhoneInfo(const char *strPhoneInfo)
{
	if(strPhoneInfo == NULL)
	{
		printf("False command.\n");
		Usage();
		return false;
	}

	if(strlen(strPhoneInfo) == 0)
	{
		printf("False command.\n");
		Usage();
		return false;
	}

	char *p = GetPhoneBuffer()->Buffer;

	int left_room = BUFFER_LENGTH - GetPhoneBuffer()->CurrentPosition;
	//2的含义是\n和字符串结束字符0
	if(left_room < (strlen(strPhoneInfo) + 2))
	{
		printf("Buffer is not enough.\n");
		return false;
	}

	strcpy(p + GetPhoneBuffer()->CurrentPosition, strPhoneInfo);
	GetPhoneBuffer()->CurrentPosition += strlen(strPhoneInfo);
	p[GetPhoneBuffer()->CurrentPosition] = '\n';

	GetPhoneBuffer()->CurrentPosition++;

	return true;
}

bool SavePhoneInfo()
{
	FILE *fp = fopen(GetOrSetDefaultFileFullPath(), "a");
	if(fp == NULL)
	{
		printf("File open error.\n");
		return false;
	}

	fputs(GetPhoneBuffer()->Buffer, fp);

	InitialPhoneBuffer();

	fclose(fp);
	return true;
}

/*
若返回false，则表示退出命令循环；否则继续等待接收命令
*/
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
		printf("will add item(name phone): %s\n", strCommandParameter);
		AddPhoneInfo(strCommandParameter);
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
		printf("Please input your command : ");

		memset(cmd, 0, MAX_LENGTH_OF_CMD);
		if(scanf("%[^\n]", cmd) == 0)
		{
			fflush(stdin);
			continue;
		}

		fflush(stdin);

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

int _tmain(int argc, _TCHAR* argv[])
{
	char DefaultFileFullPath[MAX_PATH];
	GetDefaultFileFullPath(DefaultFileFullPath, DEFAULT_FILE_NAME, argv[0]);

	GetOrSetDefaultFileFullPath(DefaultFileFullPath);

	printf("Default file path: %s\n", DefaultFileFullPath);

	DisplayDefaultFile(DefaultFileFullPath);

	InitialPhoneBuffer();

	EnterCommandLoop();

	return 0;
}