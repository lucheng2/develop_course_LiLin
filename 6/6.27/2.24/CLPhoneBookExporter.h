#ifndef CLPhoneBookExporter_H
#define CLPhoneBookExporter_H

#include "ILPhoneBookCmdObserver.h"

class CLPhoneBookFeatures;

class CLPhoneBookExporter : public ILPhoneBookCmdObserver
{
public:
	CLPhoneBookExporter(CLPhoneBookFeatures *pFeatures);
	virtual ~CLPhoneBookExporter();

	virtual bool Initial(CLPhoneBook * pPhoneBook);
	virtual bool Uninitial();

	virtual bool IsYours(const char * pstrCmd);
	virtual bool Notify(const char *pstrCmdParameter);

private:
	CLPhoneBookExporter(const CLPhoneBookExporter&);
	CLPhoneBookExporter& operator=(const CLPhoneBookExporter&);

private:
	CLPhoneBookFeatures *m_pFeatures;
	CLPhoneBook *m_pPhoneBook;
};

#endif