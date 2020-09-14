#ifndef CLFullCacheForPhoneBook_H
#define CLFullCacheForPhoneBook_H

#include <string>
#include "ILPhoneBookCache.h"

using namespace std;

class CLDynamicArray;

class CLFullCacheForPhoneBook : public ILPhoneBookCache
{
public:
	explicit CLFullCacheForPhoneBook(const char *strDefaultFileFullPath);
	virtual ~CLFullCacheForPhoneBook();

	virtual bool Initial();
	virtual bool Unitial();

	virtual SLPhoneItem* GetPhoneItem(unsigned int index);
	virtual bool PutPhoneItem(SLPhoneItem *pPhoneItem);

	virtual bool FlushCache();

private:
	CLFullCacheForPhoneBook(const CLFullCacheForPhoneBook&);
	CLFullCacheForPhoneBook& operator=(const CLFullCacheForPhoneBook&);

private:
	string m_strDefaultFileFullPath;
	CLDynamicArray *m_pDynamicArray;
};

#endif