// 8.1.cpp : 定义控制台应用程序的入口点。
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
		static int q = 4;
		cout << "静态局部变量: " << hex << &q << endl;
		cout << "静态数据成员: " << hex << &k << endl;
		cout << "全局变量: " << hex << &p << endl;
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

