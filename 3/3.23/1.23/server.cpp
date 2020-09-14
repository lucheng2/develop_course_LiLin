#include <winsock2.h>
#include <iostream>

#pragma comment(lib, "ws2_32.lib")

using namespace std;

struct Head
{
	char flag;
	int len;
};

int main()
{
	WORD wVersionRequested;
	WSADATA wsaData;
	wVersionRequested = MAKEWORD(2, 2);
	WSAStartup(wVersionRequested, &wsaData);

    int nListenSocket = ::socket(AF_INET, SOCK_STREAM, 0);
    if(-1 == nListenSocket)
    {
		cout << "socket error" << endl;
		return 0;
    }

    sockaddr_in ServerAddress;
    memset(&ServerAddress, 0, sizeof(sockaddr_in));
    ServerAddress.sin_family = AF_INET;
    ServerAddress.sin_addr.s_addr = htonl(INADDR_ANY);
    ServerAddress.sin_port = htons(4000);

    if(::bind(nListenSocket, (sockaddr *)&ServerAddress, sizeof(sockaddr_in)) == -1)
    {
		cout << "bind error" << endl;
		::closesocket(nListenSocket);
		return 0;
    }

    if(::listen(nListenSocket, 23) == -1)
    {
		cout << "listen error" << endl;
		::closesocket(nListenSocket);
		return 0;
    }

    sockaddr_in ClientAddress;
    int LengthOfClientAddress = sizeof(sockaddr_in);
    int nConnectedSocket = ::accept(nListenSocket, (sockaddr *)&ClientAddress, &LengthOfClientAddress);
    if(-1 == nConnectedSocket)
    {
		cout << "accept error" << endl;
		::closesocket(nListenSocket);
		return 0;
    }

	Head *pHead = new Head;
	char *pFlag = (char *)pHead;
	int *pLen = (int *)(pFlag + 1);

	*pFlag = 1;
	*pLen = 12;

    ::send(nConnectedSocket, (char *)pHead, sizeof(Head), 0);

    ::closesocket(nConnectedSocket);
    ::closesocket(nListenSocket);

    return 0;
}
