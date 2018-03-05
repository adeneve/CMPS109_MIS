// Client.h
// Aaron Doubek-Kraft, adoubekk@ucsc.edu
// CMPS 109 MIS project
// Client program for client-server model. Instantiated on a file, which is read into a raw string
// and sent over a TCP connection. Then waits for result and writes it to a file.

#include <string>
#include <fstream>
#include <iostream>
#include <cstdlib>
#include "../TCP/headers/TCPSocket.h"

int main(int argc, char* argv[]){
   string filename; 
   int MAXSIZE = 4096;
   if (argc < 2) {
      cout << "Usage: Client filename" << endl;
      return -1;
   }
   //initialize file input stream and stringbuffer
   filename = argv[1];
   auto in = ifstream(filename,ifstream::in);
   stringbuf sb(ios_base::in | ios_base::out);
   in.get(sb,EOF); // read entire file into stringbuffer
   in.close();
   
   //check to see if maximum size was exceeded
   int len = sb.str().length();
   if (len > MAXSIZE) {
      cout << "Exceeded Maximum Filesize of " << MAXSIZE << endl;
   }
   
   //copy data from stringbuffer into c-style array
   char* data = (char *) calloc(len,sizeof(char));
   char out[MAXSIZE],err[MAXSIZE];
   sb.str().copy(data,sb.str().length(),0);
   char server[1024] = "localhost";
   
   //initialize socket and write data to it
   TCPSocket* SocketyMcSocketface = new TCPSocket(server, 5532);
   SocketyMcSocketface->writeToSocket(data, MAXSIZE);
   
   //read output and error from socket, once server has written it
   SocketyMcSocketface->readFromSocket(out, MAXSIZE);
   SocketyMcSocketface->readFromSocket(err,MAXSIZE);
   
   cout << out << endl << err << endl;
   
   //copy output and error into local files
   int n = 0, n_max = filename.length();
   while ( filename[n] != '.'){
      if (n == n_max) {
         break;
      }
      n++;
   }
   string strip = filename.substr(0,n);
   string out_name = strip + ".out";
   string err_name = strip + ".err";
   ofstream file;
   file.open(out_name);
   file << out;
   file.close();
   file.open(err_name);
   file << err;
   file.close();
   
   cout << "Output and error written to file" << endl;
   
   free(data);

}