// 1.25.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

int _tmain(int argc, _TCHAR* argv[])
{
	int flag;
	flag = 0;

	switch(flag)
	{
	case 1:
		printf("1\n");
		break;

	case 3:
		printf("3\n");
		break;

	case 5:
		printf("5\n");
		break;

	default:
		printf("%d\n", flag);
		break;
	}

	return 0;
}

