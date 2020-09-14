// 2.22.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

const unsigned int STEP_ADD_DYNAMIC_ARRAY = 2;

struct SLDynamicArray
{
	char *pBuffer;
	unsigned int uiCurrentItemCount;
	unsigned int uiMaxItemCount;
	unsigned int uiItemSize;
};

bool InitialDynamicArray(SLDynamicArray *pDA, unsigned int uiMaxItemCount, unsigned int uiItemSize)
{
	if((pDA != NULL) && (uiItemSize != 0) && (uiMaxItemCount != 0))
	{
		pDA->pBuffer = new char[uiMaxItemCount * uiItemSize];
		pDA->uiItemSize = uiItemSize;
		pDA->uiMaxItemCount = uiMaxItemCount;
		pDA->uiCurrentItemCount = 0;

		return true;
	}
	else
		return false;
}

void DestroyDynamicArray(SLDynamicArray *pDA)
{
	if(pDA != NULL)
	{
		if(pDA->pBuffer != NULL)
			delete [] pDA->pBuffer;

		pDA->pBuffer = NULL;
		pDA->uiCurrentItemCount = 0;
		pDA->uiItemSize = 0;
		pDA->uiMaxItemCount = 0;
	}
}

char* GetItemOfDynamicArray(SLDynamicArray *pDA, unsigned int index)
{
	if((index >= 0) && (pDA != NULL) && (index < pDA->uiCurrentItemCount))
	{
		char *p = pDA->pBuffer + index * pDA->uiItemSize;
		return p;
	}
	else
		return NULL;
}

bool AppendItemForDynamicArray(SLDynamicArray *pDA, char *pItem)
{
	if((pDA != NULL) && (pItem != NULL))
	{
		if(pDA->uiCurrentItemCount == pDA->uiMaxItemCount)
		{
			int max_count = pDA->uiMaxItemCount + STEP_ADD_DYNAMIC_ARRAY;
			char *pTemp = new char[max_count * pDA->uiItemSize];
			memcpy(pTemp, pDA->pBuffer, pDA->uiCurrentItemCount * pDA->uiItemSize);

			delete [] pDA->pBuffer;

			pDA->pBuffer = pTemp;
			pDA->uiMaxItemCount = max_count;
		}

		char *p = pDA->pBuffer + pDA->uiCurrentItemCount * pDA->uiItemSize;
		memcpy(p, pItem, pDA->uiItemSize);
		pDA->uiCurrentItemCount++;

		return true;
	}
	else
		return false;
}

int _tmain(int argc, _TCHAR* argv[])
{
	SLDynamicArray da;
	InitialDynamicArray(&da, 10, 4);

	for(int i = 0; i < 10; i++)
	{
		AppendItemForDynamicArray(&da, (char *)&i);
	}

	int i = 10;
	AppendItemForDynamicArray(&da, (char *)&i);

	DestroyDynamicArray(&da);

	return 0;
}