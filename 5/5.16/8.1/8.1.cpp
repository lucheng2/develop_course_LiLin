// 8.1.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>

using namespace std;

class A
{
public:
	A()
	{
		i = 4;
	}

	A(const A& a)
	{
		i = a.i;
	}

public:
	int i;
};

A f()
{
	A a;
	return a;
}

int _tmain(int argc, _TCHAR* argv[])
{
	A a = f();
	return 0;
}

