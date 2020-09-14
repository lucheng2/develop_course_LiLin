#ifndef SUPPORT_H
#define SUPPORT_H

struct SLPhoneInMemory
{
	int CurrentPosition;//ָ��buffer�кδ��ǿ��е�
	char Buffer[PHONE_BUFFER_LENGTH];
};

SLPhoneInMemory *GetPhoneBuffer();

void InitialPhoneBuffer();

const char *GetOrSetDefaultFileFullPath(const char *strDefaultFileFullPath = NULL);

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