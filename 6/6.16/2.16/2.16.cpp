// 2.16.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <windows.h>
#include <string.h>

const unsigned int MAX_LENGTH_OF_CMD = 300;
const char* DEFAULT_FILE_NAME = "temp.txt";

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

void EnterCommandLoop()
{
	char cmd[MAX_LENGTH_OF_CMD];

	while(1)
	{
		printf("Please input your command : ");

		if(scanf("%[^\n]", cmd) == 0)
		{
			fflush(stdin);
			continue;
		}

		fflush(stdin);

		//所有命令头只有3个字符
		cmd[3] = 0;

		printf("Your command is : %s\n", cmd);

		if(strcmp(cmd, "-ld") == 0)
		{
			printf("will import phone book\n");

			char file[MAX_PATH];
			strcpy(file, cmd + 4);

			printf("Load file needed is: %s\n", file);
			continue;
		}

		if(strcmp(cmd, "-sa") == 0)
		{
			printf("will export phone book\n");
			continue;
		}

		if(strcmp(cmd, "-se") == 0)
		{
			printf("will save phone book\n");
			continue;
		}

		if(strcmp(cmd, "-ad") == 0)
		{
			printf("will add item(name phone)\n");
			continue;
		}

		if(strcmp(cmd, "-qt") == 0)
		{
			printf("quit now ....\n");
			break;
		}
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	char DefaultFileFullPath[MAX_PATH];
	GetDefaultFileFullPath(DefaultFileFullPath, DEFAULT_FILE_NAME, argv[0]);

	printf("Default file path: %s\n", DefaultFileFullPath);

	DisplayDefaultFile(DefaultFileFullPath);

	EnterCommandLoop();

	return 0;
}