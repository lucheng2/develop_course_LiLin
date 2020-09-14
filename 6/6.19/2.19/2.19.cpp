// 2.19.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <windows.h>
#include <string.h>

const unsigned int MAX_LENGTH_OF_CMD = 300;
const unsigned int MAX_LENGTH_OF_CMD_HEAD = 10;

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

bool ImportFile(const char *strImportFile)
{
	if(strImportFile == NULL)
	{
		printf("False command.\n");
		Usage();
		return false;
	}

	if(strlen(strImportFile) == 0)
	{
		printf("False command.\n");
		Usage();
		return false;
	}

	FILE *fpDefaultFile = fopen(GetOrSetDefaultFileFullPath(), "a");
	if(fpDefaultFile == NULL)
	{
		printf("Default file open error.\n");
		return false;
	}

	FILE *fpImportFile = fopen(strImportFile, "r");
	if(fpImportFile == NULL)
	{
		printf("Import file open error.\n");
		fclose(fpDefaultFile);
		return false;
	}

	while(1)
	{
		char buf[MAX_PATH];
		if(fgets(buf, MAX_PATH, fpImportFile) == NULL)
			break;

		fputs(buf, fpDefaultFile);
	}

	fclose(fpImportFile);
	fclose(fpDefaultFile);
	return true;
}

bool ExportFile(const char *strExportFile)
{
	if(strExportFile == NULL)
	{
		printf("False command.\n");
		Usage();
		return false;
	}

	if(strlen(strExportFile) == 0)
	{
		printf("False command.\n");
		Usage();
		return false;
	}

	FILE *fpDefaultFile = fopen(GetOrSetDefaultFileFullPath(), "r");
	if(fpDefaultFile == NULL)
	{
		printf("Default file open error.\n");
		return false;
	}

	FILE *fpExportFile = fopen(strExportFile, "w");
	if(fpExportFile == NULL)
	{
		printf("Export file open error.\n");
		fclose(fpDefaultFile);
		return false;
	}

	while(1)
	{
		char buf[MAX_PATH];
		if(fgets(buf, MAX_PATH, fpDefaultFile) == NULL)
			break;

		fputs(buf, fpExportFile);
	}

	fclose(fpExportFile);
	fclose(fpDefaultFile);
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
		ImportFile(strCommandParameter);
		return true;
	}

	if(strcmp(strCommandHead, "-sa") == 0)
	{
		printf("will export phone book to %s\n", strCommandParameter);
		ExportFile(strCommandParameter);
		return true;
	}

	if(strcmp(strCommandHead, "-se") == 0)
	{
		printf("will save phone book\n");
		return true;
	}

	if(strcmp(strCommandHead, "-ad") == 0)
	{
		printf("will add item(name phone): %s\n", strCommandParameter);
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

	EnterCommandLoop();

	return 0;
}