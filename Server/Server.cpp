//Server.cpp
//Multithreded Server for MIS client server model
//Aaron Doubek-Kraft, adoubekk@ucsc.edu

#include "../TCP/headers/TCPServerSocket.h"
#include "../TCP/headers/TCPSocket.h"
#include "../MIS/MIS.h"
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string>
#include <thread>
#define MAXSIZE 4096

using namespace std;

void socketThread(TCPSocket* Sockelstiltskin, int threadID);

int main(){
   int threadID = 0;

   //initialize Server Socket
	TCPServerSocket* ServerSock = new TCPServerSocket("", 5532, 10);
	ServerSock->initializeSocket();

   while(true){
      //get client socket connection
      TCPSocket* newSock = ServerSock->getConnection();
      //begin a new thread and run the socket inside of it
      thread (socketThread,newSock,threadID++).detach(); //begin a new thread with this socket and detach it
   }
}

void socketThread(TCPSocket* Sockelstiltskin, int threadID){
   char *out, *err;
   char data[MAXSIZE]; 
   
   Sockelstiltskin->readFromSocket(data, MAXSIZE);
   
   //copy input file raw data to a temporary local file to be read by MIS object
   string src_name = "server_copy" + std::to_string(threadID);
   ofstream file;
   file.open(src_name);
   file << data;
   file.close();
   
   // Write default content to output and error files
   string out_name = src_name + ".out";
   string err_name = src_name + ".err";
   file.open(out_name);
   file << "MIS Output: \n";
   file.close();
   file.open(err_name);
   file << "MIS Error: \n";
   file.close();
   
   //instantiate MIS on input
   MIS* myMIS = new MIS();
   try {
      myMIS->makeParser(src_name);
   } catch (exception& e) {
      
   }
   myMIS->run();
   delete(myMIS);
   
   //retrieve program output and error from files created by MIS
   auto output = ifstream(out_name,ifstream::in);
   auto errors = ifstream(err_name,ifstream::in);
   stringbuf sb(ios_base::in | ios_base::out);
   
   output.get(sb,EOF); // read output file into stringbuffer
   output.close();
   //convert stringbuffer contents to c-style character array and copy to out
   out = new char[sb.str().length() + 1];
   strcpy(out,sb.str().c_str()); 
    
   sb.str(""); //clear stringbuffer
   
   errors.get(sb,EOF);
   errors.close();
   err = new char[sb.str().length() + 1];
   strcpy(err,sb.str().c_str()); 
   
   //remove temporary source,out,and error files
   remove(src_name.c_str());
   remove(out_name.c_str());
   remove(err_name.c_str());
   
   //write output and error to client socket
   Sockelstiltskin->writeToSocket(out, MAXSIZE);
   Sockelstiltskin->writeToSocket(err, MAXSIZE);
   
   free(out);
   free(err);
}