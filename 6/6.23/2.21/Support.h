#ifndef SUPPORT_H
#define SUPPORT_H

struct SLDynamicArray;

SLDynamicArray *GetPhoneBuffer();

const char *GetOrSetDefaultFileFullPath(const char *strDefaultFileFullPath = NULL);

bool InitialPhoneBook(const char *strArgv0);

bool UninitialPhoneBook();

/*
ȷ��strCommandHead��strParameter���㹻�Ŀռ䣬����ֱ���ΪMAX_LENGTH_OF_CMD_HEAD��MAX_LENGTH_OF_CMD
*/
bool InterpretCommand(const char* strCommand, char *strCommandHead, char *strParameter);

/*
������false�����ʾ�˳�����ѭ������������ȴ���������
*/
bool DispatchCommand(const char *strCommandHead, const char *strCommandParameter);

void EnterCommandLoop();

#endif