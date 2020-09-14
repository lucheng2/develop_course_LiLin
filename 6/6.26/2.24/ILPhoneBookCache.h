#ifndef ILPhoneBookCache_H
#define ILPhoneBookCache_H

const unsigned int NAME_LENGTH = 30;
const unsigned int PHONE_LENGTH = 30;

struct SLPhoneItem
{
	char name[NAME_LENGTH];
	char phone[PHONE_LENGTH];
};

class ILPhoneBookCache
{
public:
	ILPhoneBookCache();
	virtual ~ILPhoneBookCache();

	virtual bool Initial() = 0;
	virtual bool Unitial() = 0;

	virtual SLPhoneItem* GetPhoneItem(unsigned int index) = 0;
	virtual bool PutPhoneItem(SLPhoneItem *pPhoneItem) = 0;

	virtual bool FlushCache() = 0;

private:
	ILPhoneBookCache(const ILPhoneBookCache&);
	ILPhoneBookCache& operator=(const ILPhoneBookCache&);
};

#endif