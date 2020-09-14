// 2.7.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <string.h>

int _tmain(int argc, _TCHAR* argv[])
{
	FILE *fp = fopen("c:\\temp.txt", "w");
	if(fp == NULL)
		return 0;

	fputs("Hello World!\r\n", fp);
	fputs("Hello China!\r\n", fp);

	fclose(fp);

	fp = fopen("c:\\temp.txt", "r");
	if(fp == NULL)
		return 0;

	char buf[30];
	for(;;)
	{
		if(fgets(buf, 30, fp) == NULL)
			break;

		printf("%s", buf);
	}

	if(feof(fp) != 0)
		printf("file end\n");

	return 0;
}