// 2.8.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <string.h>

int _tmain(int argc, _TCHAR* argv[])
{
	FILE *fp = fopen("c:\\temp.txt", "w");
	if(fp == NULL)
		return 0;

	const char *p1 = "Hello World!\n";
	fwrite(p1, strlen(p1), 1, fp);

	const char *p2 = "Hello China!\n";
	fwrite(p2, strlen(p2), 1, fp);

	fclose(fp);

	return 0;
}