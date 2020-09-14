// 2.6.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <string.h>

const unsigned int MAX_LENGTH_OF_CMD = 256;

int _tmain(int argc, _TCHAR* argv[])
{
	char cmd[MAX_LENGTH_OF_CMD];

	while(1)
	{
		printf("Please input your command : ");
		
		if(scanf("%[^\n]", cmd) == 0)
		{
			fflush(stdin);
			continue;
		}
		
		fflush(stdin);
		
		printf("Your command is : %s\n", cmd);

		if(strcmp(cmd, "-ld") == 0)
		{
			printf("will import phone book\n");
			continue;
		}

		if(strcmp(cmd, "-sa") == 0)
		{
			printf("will export phone book\n");
			continue;
		}

		if(strcmp(cmd, "-se") == 0)
		{
			printf("will save phone book\n");
			continue;
		}

		if(strcmp(cmd, "-ad") == 0)
		{
			printf("will add item(name phone)\n");
			continue;
		}

		if(strcmp(cmd, "-qt") == 0)
		{
			printf("quit now ....\n");
			break;
		}
	}

	return 0;
}

