// 7.1.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

int _tmain(int argc, _TCHAR* argv[])
{
	char i[7] = {0x66, 0x89, 0xAB, 0X78, 0X56, 0X34, 0X12};
	//char i[7] = {0x8b, 0x1d, 0X78, 0X56, 0X34, 0X12};


	char *code = i;
	_asm
	{
		jmp dword ptr [code]
	}

	return 0;
}

