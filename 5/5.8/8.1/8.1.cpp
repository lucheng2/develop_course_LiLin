// 8.1.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>

using namespace std;

class A
{
public:
	int i;
	int j;
};

void f(A b)
{
	b.i = 10;
	b.j = 9;
}

int _tmain(int argc, _TCHAR* argv[])
{
	A a;
	a.i = 4;
	a.j = 5;
	f(a);
	return 0;
}

