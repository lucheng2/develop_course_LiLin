#ifndef CLPhoneBookSaver_H
#define CLPhoneBookSaver_H

#include "ILPhoneBookCmdObserver.h"

class ILPhoneBookCache;

class CLPhoneBookSaver : public ILPhoneBookCmdObserver
{
public:
	explicit CLPhoneBookSaver(ILPhoneBookCache *pCache);
	virtual ~CLPhoneBookSaver();

	virtual bool Initial(CLPhoneBook * pPhoneBook);
	virtual bool Uninitial();

	virtual bool IsYours(const char * pstrCmd);
	virtual bool Notify(const char *pstrCmdParameter);

private:
	CLPhoneBookSaver(const CLPhoneBookSaver&);
	CLPhoneBookSaver& operator=(const CLPhoneBookSaver&);

private:
	ILPhoneBookCache *m_pCache;
};

#endif