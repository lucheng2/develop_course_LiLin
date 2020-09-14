#ifndef CLPhoneBookFeatures_H
#define CLPhoneBookFeatures_H

class CLPhoneBook;

class CLPhoneBookFeatures
{
public:
	CLPhoneBookFeatures(CLPhoneBook *pPhoneBook);
	virtual ~CLPhoneBookFeatures();

	void DisplayDefaultFile();

	void Usage();

	bool TransferBetweenTwoPhoneBookFiles(const char *strSrcFile, const char *strDstFile);

private:
	CLPhoneBookFeatures(const CLPhoneBookFeatures&);
	CLPhoneBookFeatures& operator=(const CLPhoneBookFeatures&);

private:
	CLPhoneBook *m_pPhoneBook;
};

#endif