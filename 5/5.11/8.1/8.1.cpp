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
	int k;
};

A f()
{
	A b;
	b.i = 10;
	b.j = 9;
	b.k = 11;
	return b;
}

int _tmain(int argc, _TCHAR* argv[])
{
	A a = f();
	return 0;
}

