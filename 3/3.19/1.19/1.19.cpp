// 1.19.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>

using namespace std;

struct A
{
	char i;
	short j;
};

int _tmain(int argc, _TCHAR* argv[])
{
	A a;
	a.i = 1;
	a.j = 2;

	cout << sizeof(a) << endl;
	return 0;
}

