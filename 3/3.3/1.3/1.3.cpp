// 1.3.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>

using namespace std;

int gi = 0;
unsigned char *code = 0;
unsigned char *pReturnAddress = 0;

unsigned char* BuildCode()
{
	unsigned char *pCode = new unsigned char[16];
	unsigned char *pMov = pCode;

	pMov[0] = 0xC7;
	pMov[1] = 0x05;

	unsigned char *pAddress = pMov + 2;
	*((int *)pAddress) = (int)(&gi);

	unsigned char *pImm = pAddress + 4;
	*((int *)pImm) = 18;

	unsigned char *pJmp = pImm + 4;
	pJmp[0] = 0xff;
	pJmp[1] = 0x25;
	
	unsigned char *pJmpAddress = pJmp + 2;
	*((int *)pJmpAddress) = (int)(&pReturnAddress);

	return pCode;
}

int _tmain(int argc, _TCHAR* argv[])
{
	gi = 12;

	_asm
	{
		mov pReturnAddress, offset l
	}

	code = BuildCode();
	_asm jmp dword ptr [code]
	
l:	cout << gi << endl;

	return 0;
}
