// 1.8.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

int _tmain(int argc, _TCHAR* argv[])
{
	int *pi;
	short si = 12;
	pi = (int *)&si;
	printf("%d, %x\n", *pi, *pi);
	return 0;
}

