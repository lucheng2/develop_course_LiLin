// 1.17.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"

struct myrd
{
	int i1;
	int i2;
};

myrd myfunction()
{
	myrd r1;
	r1.i1 = 1;
	r1.i2 = 2;
	return r1;
}

int _tmain(int argc, _TCHAR* argv[])
{
	myrd r;
	r = myfunction();

	return 0;
}
