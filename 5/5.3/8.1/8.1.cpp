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
		i = 2;
		j = 3;
		k = 4;
	}

private:
	char i;
	short j;

	static int k;
};

int A::k = 0;

int _tmain(int argc, _TCHAR* argv[])
{
	A a;
	cout << sizeof(a) << endl;
	return 0;
}

