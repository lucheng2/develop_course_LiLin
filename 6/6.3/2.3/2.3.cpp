// 2.3.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

const unsigned int MAX_LENGTH_OF_CMD = 256;

int _tmain(int argc, _TCHAR* argv[])
{
	char cmd[MAX_LENGTH_OF_CMD];

	while(1)
	{
		printf("Please input your command : ");
		scanf("%[^\n]", cmd);

		fflush(stdin);

		printf("Your command is : %s\n", cmd);
	}


	return 0;
}

