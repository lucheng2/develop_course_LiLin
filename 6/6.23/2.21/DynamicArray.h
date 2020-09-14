#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H

struct SLDynamicArray
{
	char *pBuffer;
	unsigned int uiCurrentItemCount;
	unsigned int uiMaxItemCount;
	unsigned int uiItemSize;
};

bool InitialDynamicArray(SLDynamicArray *pDA, unsigned int uiMaxItemCount, unsigned int uiItemSize);

void DestroyDynamicArray(SLDynamicArray *pDA);

char* GetItemOfDynamicArray(SLDynamicArray *pDA, unsigned int index);

bool AppendItemForDynamicArray(SLDynamicArray *pDA, char *pItem);

#endif