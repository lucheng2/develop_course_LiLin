#ifndef CLDynamicArray_H
#define CLDynamicArray_H

class CLDynamicArray
{
public:
	CLDynamicArray();
	virtual ~CLDynamicArray();

	bool Initial(unsigned int uiMaxItemCount, unsigned int uiItemSize);

	void Destroy();

	char* GetItem(unsigned int index);

	bool AppendItem(char *pItem);

private:
	CLDynamicArray(const CLDynamicArray&);
	CLDynamicArray& operator=(const CLDynamicArray&);

private:
	char *m_pBuffer;
	unsigned int m_uiCurrentItemCount;
	unsigned int m_uiMaxItemCount;
	unsigned int m_uiItemSize;
};

#endif