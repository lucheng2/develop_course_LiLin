// 7.1.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

int _tmain(int argc, _TCHAR* argv[])
{
	_asm
	{
		mov [ebp], edx
	}

	return 0;
}

