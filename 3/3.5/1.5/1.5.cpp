// 1.5.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"

short gi;
short *pi;

int _tmain(int argc, _TCHAR* argv[])
{
	pi = &gi;
	*pi = 12;

	return 0;
}

