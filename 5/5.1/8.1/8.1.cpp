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
		i = 2;
		j = 3;
	}

private:
	char i;
	short j;
};

int _tmain(int argc, _TCHAR* argv[])
{
	A a;
	cout << sizeof(a) << endl;
	return 0;
}

