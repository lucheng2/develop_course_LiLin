// 2.9.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	cout << "argc: " << argc << endl;

	for(int i = 0; i < argc; i++)
		cout << "argv[" << i << "]: " << argv[i] << endl;

	return 0;
}
