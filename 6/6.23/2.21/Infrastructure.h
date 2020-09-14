#ifndef INFRASTRUCTURE_H
#define INFRASTRUCTURE_H

/*
strDefaultFileFullPath要确保足够的存储空间，建议为MAX_PATH
*/
bool GetDefaultFileFullPath(char *strDefaultFileFullPath, const char *strDefaultFileName, const char *strArgv0);

bool TransferBetweenTwoFiles(const char *strSrcFile, const char *strDstFile);

bool GetUserInput(char *buffer, int buffer_length, char *IndicateMsg);

#endif