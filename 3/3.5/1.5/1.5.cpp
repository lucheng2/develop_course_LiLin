// 1.5.cpp : 定义控制台应用程序的入口点。
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

