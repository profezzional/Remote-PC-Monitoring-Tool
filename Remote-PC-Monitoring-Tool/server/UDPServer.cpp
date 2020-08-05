#include "UDPServer.hpp"

#ifdef TARGET_WINDOWS
#include <Windows.h>
#pragma warning(disable: 4996)
#include <winsock.h>
#include <iostream>
#pragma comment(lib,"ws2_32.lib")
#endif

#ifdef TARGET_LINUX
#include <iostream>
#include <unistd.h> 
#include <string.h> 
#include <sys/types.h> 
#include <sys/socket.h> 
#include <arpa/inet.h> 
#include <netinet/in.h>

typedef unsigned long long SOCKET;
#define INVALID_SOCKET  (SOCKET)(~0)
#define SOCKET_ERROR            (-1)

#endif

void UDPServer::listen(int port, std::function<std::string_view(std::string_view message)> callback)
{
	std::thread([=]()
	{
		SOCKET s;
		sockaddr_in server, si_other;
		const int bufferSize = 512;
		char buf[bufferSize];

#ifdef TARGET_WINDOWS
		int slen;
		WSADATA wsa;
		DEBUG_LOG("Initialising Winsock");
		if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0)
		{
			DEBUG_LOG("Failed. Error Code : " << ::WSAGetLastError());
			exit(EXIT_FAILURE);
		}
		DEBUG_LOG("Initialised");
#else
		unsigned int slen;
#endif

		slen = sizeof(si_other);
		
		//Create a socket
		if ((s = socket(AF_INET, SOCK_DGRAM, 0)) == INVALID_SOCKET)
		{
			DEBUG_LOG("Could not create socket : " << ::WSAGetLastError());
		}
		DEBUG_LOG("Socket created");

		server.sin_family = AF_INET;
		server.sin_addr.s_addr = INADDR_ANY;
		server.sin_port = htons(port);

		if (::bind(s, (struct sockaddr*) & server, sizeof(server)) == SOCKET_ERROR)
		{
			std::cerr << "Failed to bind port" << std::endl;
			return;
		}

		for (;;)
		{
			DEBUG_LOG("UDP Listening");
			fflush(stdout);
			memset(buf, '\0', bufferSize);
			int receivedLength = 0;
			if ((receivedLength = ::recvfrom(s, buf, bufferSize, 0, (struct sockaddr*) & si_other, &slen)) == SOCKET_ERROR)
			{
				DEBUG_LOG("recvfrom() failed with error code : " << ::WSAGetLastError());
				break;
			}
			if (receivedLength > bufferSize)
			{
				DEBUG_LOG("Oversided buffer recieved, " << receivedLength);
				continue;
			}

			DEBUG_LOG("Received packet from " << ::inet_ntoa(si_other.sin_addr) << " " << ntohs(si_other.sin_port));
			std::cout << buf << std::endl;
			std::string_view response = callback(buf);

			if (::sendto(s, response.data(), response.size(), 0, (struct sockaddr*) & si_other, slen) == SOCKET_ERROR)
			{
				DEBUG_LOG("sendto() failed with error code : " << ::WSAGetLastError());
				exit(EXIT_FAILURE);
			}
		}
#ifdef TARGET_WINDOWS
		::closesocket(s);
		::WSACleanup();
#else
		close(s);
#endif
	}).detach();
}


