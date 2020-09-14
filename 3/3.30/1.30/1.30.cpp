// 1.30.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <windows.h>

int _tmain(int argc, _TCHAR* argv[])
{
	char *str1 = "hello world.";
	int i;

	DWORD t1 = GetTickCount();

	for(int j =0 ; j< 10000000; j++)
	{
	_asm
	{
		push edi
		push ecx
		push eax
		
		mov edi, str1
		mov ecx, 0ffffffffh
		xor al, al
		repne scasb
		mov eax, 0fffffffeh
		sub eax, ecx

		mov i, eax
		
		pop eax
		pop ecx
		pop edi
	}
	}

	DWORD t2 = GetTickCount();

	printf("%d \n", t2 - t1);

	t1 = GetTickCount();
	for(int j = 0; j < 10000000; j++)
		i = strlen(str1);
	t2 = GetTickCount();

	printf("%d \n", t2 - t1);
	return 0;

}

