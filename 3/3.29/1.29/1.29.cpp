// 1.29.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <string.h>

int _tmain(int argc, _TCHAR* argv[])
{
	char *str1 = "hello world.";
	int i;

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

	printf("%d\n", i);

	i = strlen(str1);
	
	return 0;
}

