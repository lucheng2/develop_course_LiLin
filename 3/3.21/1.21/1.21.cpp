// 1.21.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>

using namespace std;

struct A
{
	char i;
	short j;
	char k;
	int m;
};

int _tmain(int argc, _TCHAR* argv[])
{
	A a;
	a.i = 1;
	a.j = 2;
	a.k = 3;
	a.m = 4;

	cout << sizeof(a) << endl;
	return 0;
}


