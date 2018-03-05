#include "../headers/TCPSocket.h"
#include "../headers/TCPServerSocket.h"
#include <iostream>
#include <stdlib.h>

int main(){

	char buffer[1024] = "localhost";

	char buffer2[1024] = "hello cs109";

	TCPSocket* ServerSock = new TCPSocket(buffer, 5532);

	ServerSock->writeToSocket(buffer2, 1024);

}