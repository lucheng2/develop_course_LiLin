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

private:
	int i;
};

int _tmain(int argc, _TCHAR* argv[])
{
	A *p = new A();
	return 0;
}

