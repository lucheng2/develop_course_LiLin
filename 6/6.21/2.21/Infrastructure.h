#ifndef INFRASTRUCTURE_H
#define INFRASTRUCTURE_H

/*
strDefaultFileFullPathҪȷ���㹻�Ĵ洢�ռ䣬����ΪMAX_PATH
*/
bool GetDefaultFileFullPath(char *strDefaultFileFullPath, const char *strDefaultFileName, const char *strArgv0);

bool TransferBetweenTwoFiles(const char *strSrcFile, const char *strDstFile);

bool GetUserInput(char *buffer, int buffer_length, char *IndicateMsg);

#endif