// 1.7.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"

int i;
int *pi;
short *ps;
char *pc;

int _tmain(int argc, _TCHAR* argv[])
{
	pi = &i;
	ps = (short *)&i;
	pc = (char *)&i;
	*pi = 0x1234;
	*ps = 0x1234;
	*pc = 0x12;
	return 0;
}

