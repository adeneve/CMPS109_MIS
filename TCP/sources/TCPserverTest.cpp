#include "../headers/TCPSocket.h"
#include "../headers/TCPServerSocket.h"
#include <iostream>
#include <stdlib.h>

using namespace std;

int main(){

	string data;

	TCPServerSocket* ServerSock = new TCPServerSocket("127.0.0.1", 5532, 10);

	ServerSock->initializeSocket();

	TCPSocket* Sock1 = ServerSock->getConnection();

	Sock1->readFromSocket(data, 1024);

	cout << string << endl;

}