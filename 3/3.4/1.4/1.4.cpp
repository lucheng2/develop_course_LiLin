// 1.4.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"

int gi;
int *pi;

int _tmain(int argc, _TCHAR* argv[])
{
	pi = &gi;
	
	*pi = 12;

	return 0;
}

