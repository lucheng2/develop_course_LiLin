// 1.12.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"

int Add(int a, int b)
{
	return a + b;
}

typedef int (*PFUNC)(int, int);

PFUNC pfunc;

int _tmain(int argc, _TCHAR* argv[])
{
	pfunc = Add;
	pfunc = &Add;

	pfunc(1, 2);

	Add(1, 2);

	return 0;
}

