#ifndef CLUtility_H
#define CLUtility_H

class CLUtility
{
public:
	CLUtility();
	virtual ~CLUtility();

	static bool GetDefaultFileFullPath(char *strDefaultFileFullPath, const char *strDefaultFileName, const char *strArgv0);
	static bool GetUserInput(char *buffer, int buffer_length, char *IndicateMsg);
	static bool TransferBetweenTwoFiles(const char *strSrcFile, const char *strDstFile);

private:
	CLUtility(const CLUtility&);
	CLUtility& operator=(const CLUtility&);
};

#endif