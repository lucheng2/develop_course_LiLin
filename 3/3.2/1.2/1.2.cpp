// 1.2.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>

using namespace std;

int gi = 0;
unsigned char *code = 0;

unsigned char* BuildCode()
{
	unsigned char *pCode = new unsigned char[10];
	unsigned char *pMov = pCode;

	pMov[0] = 0xC7;
	pMov[1] = 0x05;

	unsigned char *pAddress = pMov + 2;
	*((int *)pAddress) = (int)(&gi);

	unsigned char *pImm = pAddress + 4;
	*((int *)pImm) = 18;

	return pCode;
}

int _tmain(int argc, _TCHAR* argv[])
{
	gi = 12;
	code = BuildCode();
	_asm jmp dword ptr [code]
	return 0;
}
