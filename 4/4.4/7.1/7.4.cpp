// 7.1.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

int _tmain(int argc, _TCHAR* argv[])
{
	//char i[3] = {0x89, 0x04, 0x24};
	//char i[4] = {0x89, 0x44, 0x8D, 0x08};
	//char i[7] = {0x89, 0x84, 0xCD, 0x78, 0x56, 0x34, 0x12};
	char i[7] = {0x88, 0x04, 0xCD, 0xFE, 0xAB, 0xCD, 0x34};

	char *code = i;
	_asm
	{
		jmp dword ptr [code]
	}

	return 0;
}

