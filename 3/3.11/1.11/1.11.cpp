// 1.11.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"

int _fastcall Add(int x, int y, int z)
{
	int sum;
	sum = x + y + z;
	return sum;
}

int _tmain(int argc, _TCHAR* argv[])
{
	int z;
	z = Add(1, 2, 3);
	return 0;
}

