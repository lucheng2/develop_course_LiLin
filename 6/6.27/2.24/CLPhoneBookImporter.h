#ifndef CLPhoneBookImporter_H
#define CLPhoneBookImporter_H

#include "ILPhoneBookCmdObserver.h"

class CLPhoneBookFeatures;

class CLPhoneBookImporter : public ILPhoneBookCmdObserver
{
public:
	explicit CLPhoneBookImporter(CLPhoneBookFeatures *pFeatures);
	virtual ~CLPhoneBookImporter();

	virtual bool Initial(CLPhoneBook * pPhoneBook);
	virtual bool Uninitial();

	virtual bool IsYours(const char * pstrCmd);
	virtual bool Notify(const char *pstrCmdParameter);

private:
	CLPhoneBookImporter(const CLPhoneBookImporter&);
	CLPhoneBookImporter& operator=(const CLPhoneBookImporter&);

private:
	CLPhoneBookFeatures *m_pFeatures;
	CLPhoneBook *m_pPhoneBook;
};

#endif