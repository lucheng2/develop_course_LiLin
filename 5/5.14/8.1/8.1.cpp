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
	}

	A(const A& a)
	{
		i = a.i;
	}

private:
	int i;
};

void f(A a)
{
}

int _tmain(int argc, _TCHAR* argv[])
{
	A a;
	f(a);
	return 0;
}

