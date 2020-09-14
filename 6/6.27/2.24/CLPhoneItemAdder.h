#ifndef CLPhoneItemAdder_H
#define CLPhoneItemAdder_H

#include "ILPhoneBookCmdObserver.h"

class CLPhoneBook;
class ILPhoneBookCache;

class CLPhoneItemAdder : public ILPhoneBookCmdObserver
{
public:
	explicit CLPhoneItemAdder(ILPhoneBookCache *pCache);
	virtual ~CLPhoneItemAdder();

	virtual bool Initial(CLPhoneBook * pPhoneBook);
	virtual bool Uninitial();

	virtual bool IsYours(const char * pstrCmd);
	virtual bool Notify(const char *pstrCmdParameter);

private:
	CLPhoneItemAdder(const CLPhoneItemAdder&);
	CLPhoneItemAdder& operator=(const CLPhoneItemAdder&);

private:
	CLPhoneBook *m_pPhoneBook;
	ILPhoneBookCache *m_pCache;
};

#endif