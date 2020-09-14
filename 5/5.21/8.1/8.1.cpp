// 8.1.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>

using namespace std;

class B
{
public:
	B()
	{
		i = 4;
	}

	virtual ~B()
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

class D : public B
{
public:
	D()
	{
		j = 14;
	}

	virtual ~D()
	{
		j = 0;
	}

	virtual void f()
	{
		j = 15;
	}

	virtual void g()
	{
		j = 16;
	}

private:
	char j;
};

int _tmain(int argc, _TCHAR* argv[])
{
	B *p = new D();
	p->f();
	p->g();
	delete p;

	cout << sizeof(D) << endl;
	
	return 0;
}

