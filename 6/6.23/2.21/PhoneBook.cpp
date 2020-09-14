// PhoneBook.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

int _tmain(int argc, _TCHAR* argv[])
{
	InitialPhoneBook(argv[0]);

	DisplayDefaultFile(GetOrSetDefaultFileFullPath());

	EnterCommandLoop();

	UninitialPhoneBook();

	return 0;
}