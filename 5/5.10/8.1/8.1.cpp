// 8.1.cpp : 定义控制台应用程序的入口点。
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

A f()
{
	A b;
	b.i = 10;
	b.j = 9;

	return b;
}

int _tmain(int argc, _TCHAR* argv[])
{
	A a = f();
	return 0;
}

