// 2.13.cpp : 定义控制台应用程序的入口点。
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
		printf("Default file does not exist.");
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	char DefaultFileFullPath[MAX_PATH];
	GetDefaultFileFullPath(DefaultFileFullPath, DEFAULT_FILE_NAME, argv[0]);

	printf("Default file path: %s\n", DefaultFileFullPath);

	DisplayDefaultFile(DefaultFileFullPath);

	return 0;
}