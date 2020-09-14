#include <winsock2.h>
#include <iostream>
#include <conio.h>

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

    int nClientSocket = ::socket(AF_INET, SOCK_STREAM, 0);
    if(-1 == nClientSocket)
    {
		cout << "socket error" << endl;
		return 0;
    }

    sockaddr_in ServerAddress;
    memset(&ServerAddress, 0, sizeof(sockaddr_in));
    ServerAddress.sin_family = AF_INET;
	ServerAddress.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");
    ServerAddress.sin_port = htons(4000);

    if(::connect(nClientSocket, (sockaddr*)&ServerAddress, sizeof(ServerAddress)) == -1)
    {
		cout << "connect error" << endl;
		return 0;
    }

    Head h;
    ::recv(nClientSocket, (char *)(&h), sizeof(Head), 0);

	char f = h.flag;
	int len = h.len;

	printf("%x\n", f);
	printf("%x\n", len);

    ::closesocket(nClientSocket);

	_getch();

    return 0;
}
