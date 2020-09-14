// 8.1.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>

using namespace std;

class A
{
public:
	void __stdcall f(int j)
	{
		i = j;
	}

private:
	int i;
};

int _tmain(int argc, _TCHAR* argv[])
{
	A a;
	a.f(3);
	return 0;
}

