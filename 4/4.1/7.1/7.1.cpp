// 7.1.cpp : �������̨Ӧ�ó������ڵ㡣
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

