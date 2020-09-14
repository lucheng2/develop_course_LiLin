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

	~A()
	{
		i = 0;
	}

	virtual void f()
	{
		i = 5;
	}

	virtual void g()
	{
		i = 6;
	}

private:
	int i;
};

int _tmain(int argc, _TCHAR* argv[])
{
	A *p = new A();
	p->f();
	p->g();
	
	return 0;
}

