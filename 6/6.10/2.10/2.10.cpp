// 2.10.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <windows.h>
#include <string.h>

int _tmain(int argc, _TCHAR* argv[])
{
	//��ʱ��iָ��argv[0]�����һ���ַ�������0��
	int i = strlen(argv[0]) -1;
	while(i >= 0)
	{
		if(argv[0][i] == '\\')
			break;

		i--;
	}

	char *strDefaultFile = "temp.txt";

	if(i < 0)
	{
	//��ǰ·��
		printf("current path is .\n");
	}
	else
	{
		char path[MAX_PATH];
		memset(path, 0, MAX_PATH);

		strcpy(path, argv[0]);
		path[i] = 0;

		printf("current path is %s\n", path);

		path[i] = '\\';
		strcpy(path + i + 1, strDefaultFile);
		
		printf("Default full path: %s\n", path);
	}

	return 0;
}

