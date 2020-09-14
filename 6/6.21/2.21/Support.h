#ifndef SUPPORT_H
#define SUPPORT_H

struct SLPhoneInMemory
{
	int CurrentPosition;//指定buffer中何处是空闲的
	char Buffer[PHONE_BUFFER_LENGTH];
};

SLPhoneInMemory *GetPhoneBuffer();

void InitialPhoneBuffer();

const char *GetOrSetDefaultFileFullPath(const char *strDefaultFileFullPath = NULL);

/*
确保strCommandHead和strParameter有足够的空间，建议分别设为MAX_LENGTH_OF_CMD_HEAD、MAX_LENGTH_OF_CMD
*/
bool InterpretCommand(const char* strCommand, char *strCommandHead, char *strParameter);

/*
若返回false，则表示退出命令循环；否则继续等待接收命令
*/
bool DispatchCommand(const char *strCommandHead, const char *strCommandParameter);

void EnterCommandLoop();

#endif