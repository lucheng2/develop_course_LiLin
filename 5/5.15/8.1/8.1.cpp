// 8.1.cpp : �������̨Ӧ�ó������ڵ㡣
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
		cout << "a" << endl;
	}

	A(const A& a)
	{
		i = a.i;
		cout << "a" << endl;
	}

public:
	int i;
};

A f()
{
	//A a;
	return A();
}

int _tmain(int argc, _TCHAR* argv[])
{
	A a = f();
	return 0;
}

