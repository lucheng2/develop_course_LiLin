#ifndef CLPhoneBook_H
#define CLPhoneBook_H

#include <vector>

using namespace std;

extern const char* DEFAULT_FILE_NAME;

class CLPhoneBookFeatures;
class ILPhoneBookCache;
class ILPhoneBookCmdObserver;

class CLPhoneBook
{
public:
	CLPhoneBook();
	virtual ~CLPhoneBook();

	bool Run(const char *strArgv0);

	const char *GetDefaultFileFullPath();

	bool Register(ILPhoneBookCmdObserver *pCmdObserver);

private:
	bool Initial(const char *strArgv0);
	bool Uninitial();

	void EnterCommandLoop();
	bool InterpretCommand(const char* strCommand, char *strCommandHead, char *strParameter);
	bool DispatchCommand(const char *strCommandHead, const char *strCommandParameter);

private:
	CLPhoneBook(const CLPhoneBook&);
	CLPhoneBook& operator=(const CLPhoneBook&);

private:
	char *m_strDefaultFileFullPath;
	CLPhoneBookFeatures *m_pFeatures;
	ILPhoneBookCache *m_pPhoneBookCache;

	vector<ILPhoneBookCmdObserver *> m_pvCmdObservers;
};

#endif