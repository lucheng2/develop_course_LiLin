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

private:
	CLPhoneBookFeatures(const CLPhoneBookFeatures&);
	CLPhoneBookFeatures& operator=(const CLPhoneBookFeatures&);

private:
	CLPhoneBook *m_pPhoneBook;
};

#endif