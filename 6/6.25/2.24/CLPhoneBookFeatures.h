#ifndef CLPhoneBookFeatures_H
#define CLPhoneBookFeatures_H

class CLPhoneBook;

class CLPhoneBookFeatures
{
public:
	explicit CLPhoneBookFeatures(CLPhoneBook *pPhoneBook);
	virtual ~CLPhoneBookFeatures();

	bool AddPhoneInfo();

	void DisplayDefaultFile();

	void Usage();

	bool SavePhoneInfo();

	bool ImportPhoneBookFile(const char *strFilePath);

	bool ExportPhoneBookFile(const char *strFilePath);

private:
	bool TransferBetweenTwoPhoneBookFiles(const char *strSrcFile, const char *strDstFile);

private:
	CLPhoneBookFeatures(const CLPhoneBookFeatures&);
	CLPhoneBookFeatures& operator=(const CLPhoneBookFeatures&);

private:
	CLPhoneBook *m_pPhoneBook;
};

#endif