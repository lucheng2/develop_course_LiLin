#include "stdafx.h"

bool GetDefaultFileFullPath(char *strDefaultFileFullPath, const char *strDefaultFileName, const char *strArgv0)
{
	int i = strlen(strArgv0) - 1;
	while(i >= 0)
	{
		if(strArgv0[i] == '\\')
			break;

		i--;
	}

	if(i < 0)
	{
		strcpy(strDefaultFileFullPath, strDefaultFileName);
	}
	else
	{
		strcpy(strDefaultFileFullPath, strArgv0);
		strcpy(strDefaultFileFullPath + i + 1, strDefaultFileName);
	}

	return true;
}

bool TransferBetweenTwoFiles(const char *strSrcFile, const char *strDstFile)
{
	if((strSrcFile == NULL) || (strDstFile == NULL))
	{
		printf("False command.\n");
		Usage();
		return false;
	}

	if((strlen(strSrcFile) == 0) || (strlen(strDstFile) == 0))
	{
		printf("False command.\n");
		Usage();
		return false;
	}

	FILE *fpSrcFile = fopen(strSrcFile, "rb");
	if(fpSrcFile == NULL)
	{
		printf("File open error.\n");
		return false;
	}

	FILE *fpDstFile = fopen(strDstFile, "ab");
	if(fpDstFile == NULL)
	{
		printf("file open error.\n");
		fclose(fpSrcFile);
		return false;
	}

	while(1)
	{
		SLPhoneItem item;
		if(fread(&item, sizeof(SLPhoneItem), 1, fpSrcFile) == 0)
			break;

		fwrite(&item, sizeof(SLPhoneItem), 1, fpDstFile);
	}

	fclose(fpDstFile);
	fclose(fpSrcFile);

	return true;
}

bool GetUserInput(char *buffer, int buffer_length, char *IndicateMsg)
{
	printf(IndicateMsg);

	memset(buffer, 0, buffer_length);

	while(1)
	{
		if(scanf("%[^\n]", buffer) == 0)
		{
			fflush(stdin);
			continue;
		}

		break;
	}

	fflush(stdin);

	return true;
}