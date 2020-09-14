#include "stdafx.h"
#include "CLUtility.h"

CLUtility::CLUtility()
{
}

CLUtility::~CLUtility()
{
}

bool CLUtility::GetDefaultFileFullPath(char *strDefaultFileFullPath, const char *strDefaultFileName, const char *strArgv0)
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

bool CLUtility::GetUserInput(char *buffer, int buffer_length, char *IndicateMsg)
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