// 8.1.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>

using namespace std;

int p = 3;

class A
{
public:
	void f(int j)
	{
		static int q = 2;
		p = 5;
		q = 8;
		k = 3;
		i = 9;
	}

private:
	int i;

	static int k;
};

int A::k = 2;

int _tmain(int argc, _TCHAR* argv[])
{
	A a;
	a.f(3);
	return 0;
}

