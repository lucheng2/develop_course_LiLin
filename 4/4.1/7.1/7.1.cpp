// 7.1.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

int _tmain(int argc, _TCHAR* argv[])
{
	int i = 0xc389;

	int *code = &i;
	_asm
	{
		jmp dword ptr [code]
	}

	return 0;
}

