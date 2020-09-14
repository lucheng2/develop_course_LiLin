// PhoneBook.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

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