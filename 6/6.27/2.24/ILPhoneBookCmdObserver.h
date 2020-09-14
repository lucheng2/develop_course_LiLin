#ifndef ILPhoneBookCmdObserver_H
#define ILPhoneBookCmdObserver_H

class CLPhoneBook;

class ILPhoneBookCmdObserver
{
public:
	ILPhoneBookCmdObserver();
	virtual ~ILPhoneBookCmdObserver();

	virtual bool Initial(CLPhoneBook * pPhoneBook) = 0;
	virtual bool Uninitial() = 0;

	virtual bool IsYours(const char * pstrCmd) = 0;
	virtual bool Notify(const char *pstrCmdParameter) = 0;

private:
	ILPhoneBookCmdObserver(const ILPhoneBookCmdObserver&);
	ILPhoneBookCmdObserver& operator=(const ILPhoneBookCmdObserver&);
};

#endif