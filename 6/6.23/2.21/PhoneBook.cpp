// PhoneBook.cpp : �������̨Ӧ�ó������ڵ㡣
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