// 1.13.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

int _stdcall Add(int a, int b)
{
	return a + b;
}

typedef int (*PFUNC)(int, int);

PFUNC pfunc;

int _tmain(int argc, _TCHAR* argv[])
{
	pfunc = (PFUNC)Add;

	pfunc(1, 2);

	Add(1, 2);

	return 0;
}

