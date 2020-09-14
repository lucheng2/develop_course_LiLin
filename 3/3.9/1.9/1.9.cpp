// 1.9.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

int Add(int x, int y)
{
	int sum;
	sum = x + y;
	return sum;
}

int Sub(int x, int y)
{
	int result;
	result = x - y;
	return result;
}

int _tmain(int argc, _TCHAR* argv[])
{
	int z;
	z = Add(1, 2);
	z = Sub(1, 2);

	return 0;
}

