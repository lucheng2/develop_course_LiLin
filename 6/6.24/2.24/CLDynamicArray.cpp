#include "stdafx.h"
#include "CLDynamicArray.h"

const unsigned int STEP_ADD_DYNAMIC_ARRAY = 2;

CLDynamicArray::CLDynamicArray()
{
	m_pBuffer = NULL;
	m_uiCurrentItemCount = 0;
	m_uiItemSize = 0;
	m_uiMaxItemCount = 0;
}

CLDynamicArray::~CLDynamicArray()
{
	Destroy();
}

bool CLDynamicArray::Initial(unsigned int uiMaxItemCount, unsigned int uiItemSize)
{
	if((uiItemSize != 0) && (uiMaxItemCount != 0))
	{
		m_pBuffer = new char[uiMaxItemCount * uiItemSize];
		m_uiItemSize = uiItemSize;
		m_uiMaxItemCount = uiMaxItemCount;
		m_uiCurrentItemCount = 0;

		return true;
	}
	else
		return false;
}

void CLDynamicArray::Destroy()
{
	if(m_pBuffer != NULL)
		delete [] m_pBuffer;

	m_pBuffer = NULL;
	m_uiCurrentItemCount = 0;
	m_uiItemSize = 0;
	m_uiMaxItemCount = 0;
}

char* CLDynamicArray::GetItem(unsigned int index)
{
	if((index >= 0) && (index < m_uiCurrentItemCount))
	{
		char *p = m_pBuffer + index * m_uiItemSize;
		return p;
	}
	else
		return NULL;
}

bool CLDynamicArray::AppendItem(char *pItem)
{
	if(pItem != NULL)
	{
		if(m_uiCurrentItemCount == m_uiMaxItemCount)
		{
			int max_count = m_uiMaxItemCount + STEP_ADD_DYNAMIC_ARRAY;
			char *pTemp = new char[max_count * m_uiItemSize];
			memcpy(pTemp, m_pBuffer, m_uiCurrentItemCount * m_uiItemSize);

			delete [] m_pBuffer;

			m_pBuffer = pTemp;
			m_uiMaxItemCount = max_count;
		}

		char *p = m_pBuffer + m_uiCurrentItemCount * m_uiItemSize;
		memcpy(p, pItem, m_uiItemSize);
		m_uiCurrentItemCount++;

		return true;
	}
	else
		return false;
}