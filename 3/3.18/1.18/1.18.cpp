// 1.18.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

struct myrd
{
	int i1;
	int i2;
	int i3;
};

myrd myfunction()
{
	myrd r1;
	r1.i1 = 1;
	r1.i2 = 2;
	r1.i3 = 3;
	return r1;
}

int _tmain(int argc, _TCHAR* argv[])
{
	myrd r;
	r = myfunction();

	return 0;
}

