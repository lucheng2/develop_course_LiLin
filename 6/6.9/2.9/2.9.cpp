// 2.9.cpp : �������̨Ӧ�ó������ڵ㡣
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
