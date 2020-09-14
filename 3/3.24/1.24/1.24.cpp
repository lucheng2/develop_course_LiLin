// 1.24.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"


int _tmain(int argc, _TCHAR* argv[])
{
	int flag;
	flag = 0;

	switch(flag)
	{
	case 2:
		printf("2\n");
		break;

	case 5:
		printf("5\n");
		break;

	case 7:
		printf("7\n");
		break;

	case 8:
		printf("8\n");

	default:
		printf("%d\n", flag);
		break;
	}

	return 0;
}

