#ifndef CLPhoneBook_H
#define CLPhoneBook_H

extern const char* DEFAULT_FILE_NAME;

class CLDynamicArray;
class CLPhoneBookFeatures;

const unsigned int NAME_LENGTH = 30;
const unsigned int PHONE_LENGTH = 30;

struct SLPhoneItem
{
	char name[NAME_LENGTH];
	char phone[PHONE_LENGTH];
};

class CLPhoneBook
{
public:
	CLPhoneBook();
	virtual ~CLPhoneBook();

	bool Run(const char *strArgv0);

	CLDynamicArray *GetPhoneBookCache();
	const char *GetDefaultFileFullPath();

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
	CLDynamicArray *m_pDynamicArray;
	CLPhoneBookFeatures *m_pFeatures;
};

#endif